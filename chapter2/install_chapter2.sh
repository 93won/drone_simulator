#!/bin/bash

################################################################################
# Chapter 2: ROS2-PX4 Integration Setup Script
# Micro XRCE-DDS Agent Installation with DDS Middleware Support
# For Ubuntu 20.04 + ROS2 Galactic
################################################################################

set -e  # Stop script on error

# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}Chapter 2: ROS2-PX4 Integration Setup${NC}"
echo -e "${GREEN}========================================${NC}"

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

################################################################################
# Step 1: Check CMake Version
################################################################################
echo -e "\n${YELLOW}[1/5] Checking CMake version...${NC}"

CMAKE_VERSION=$(cmake --version | head -n 1 | grep -oP '\d+\.\d+\.\d+')
CMAKE_REQUIRED="3.20.0"

version_ge() {
    printf '%s\n%s' "$2" "$1" | sort -V -C
}

if version_ge $CMAKE_VERSION $CMAKE_REQUIRED; then
    echo -e "${GREEN}✓ CMake $CMAKE_VERSION detected (>= 3.20 required)${NC}"
else
    echo -e "${RED}✗ CMake $CMAKE_VERSION is too old. Need >= 3.20${NC}"
    echo -e "${YELLOW}Install CMake 3.20+ with:${NC}"
    echo -e "  cd /tmp"
    echo -e "  wget https://github.com/Kitware/CMake/releases/download/v3.20.6/cmake-3.20.6-linux-x86_64.sh"
    echo -e "  chmod +x cmake-3.20.6-linux-x86_64.sh"
    echo -e "  ./cmake-3.20.6-linux-x86_64.sh --prefix=\$HOME/.local --skip-license"
    echo -e "  export PATH=\"\$HOME/.local/bin:\$PATH\""
    exit 1
fi

################################################################################
# Step 2: Check ROS2 Installation
################################################################################
echo -e "\n${YELLOW}[2/5] Checking ROS2 installation...${NC}"

if [ -f "/opt/ros/galactic/setup.bash" ]; then
    echo -e "${GREEN}✓ ROS2 Galactic detected${NC}"
    source /opt/ros/galactic/setup.bash
else
    echo -e "${RED}✗ ROS2 Galactic not found${NC}"
    echo -e "${YELLOW}Please install ROS2 Galactic first${NC}"
    exit 1
fi

################################################################################
# Step 3: Build PX4 Messages for ROS2
################################################################################
echo -e "\n${YELLOW}[3/5] Setting up PX4 messages for ROS2...${NC}"

ROS2_WS="$SCRIPT_DIR/../ros2_ws"

if [ ! -d "$ROS2_WS/src/px4_msgs" ]; then
    echo "Creating ROS2 workspace and cloning px4_msgs..."
    mkdir -p "$ROS2_WS/src"
    cd "$ROS2_WS/src"
    git clone https://github.com/PX4/px4_msgs.git
    cd "$ROS2_WS"
    
    echo "Building px4_msgs package (takes 2-3 minutes)..."
    colcon build
    
    echo -e "${GREEN}✓ px4_msgs built successfully${NC}"
else
    echo -e "${BLUE}px4_msgs already exists. Skipping build.${NC}"
fi

source "$ROS2_WS/install/setup.bash"

################################################################################
# Step 4: Install Micro XRCE-DDS Agent with DDS Support
################################################################################
echo -e "\n${YELLOW}[4/5] Installing Micro XRCE-DDS Agent...${NC}"
echo -e "${BLUE}Important: Building with system FastDDS/CycloneDDS support${NC}"

AGENT_DIR="$SCRIPT_DIR/../Micro-XRCE-DDS-Agent"

# Clone if not exists
if [ ! -d "$AGENT_DIR" ]; then
    echo "Cloning Micro XRCE-DDS Agent..."
    cd "$SCRIPT_DIR/.."
    git clone https://github.com/eProsima/Micro-XRCE-DDS-Agent.git
fi

cd "$AGENT_DIR"
mkdir -p build
cd build

echo "Configuring CMake (building fastcdr internally)..."
echo -e "${YELLOW}ROS2 Galactic has fastcdr 1.0.20, but Agent needs 2.x${NC}"
echo -e "${YELLOW}Building fastcdr 2.x internally to avoid conflict${NC}"

# Source ROS2 environment before building
source /opt/ros/galactic/setup.bash
ROS2_WS="$SCRIPT_DIR/../ros2_ws"
if [ -f "$ROS2_WS/install/setup.bash" ]; then
    source "$ROS2_WS/install/setup.bash"
fi

# Build WITHOUT system FastCDR (let Agent build its own fastcdr 2.x)
cmake .. \
    -DUAGENT_USE_SYSTEM_FASTDDS=OFF \
    -DUAGENT_USE_SYSTEM_FASTCDR=OFF \
    -DCMAKE_INSTALL_PREFIX="$SCRIPT_DIR/../agent_install"

echo "Building Agent (takes 2-3 minutes)..."
make -j$(nproc)

echo "Installing Agent to agent_install/ directory..."
make install

cd "$SCRIPT_DIR"

echo -e "${GREEN}✓ Micro XRCE-DDS Agent installed successfully${NC}"

################################################################################
# Step 5: Create Helper Script
################################################################################
echo -e "\n${YELLOW}[5/5] Creating helper script...${NC}"

cat > run_agent.sh << 'EOF'
#!/bin/bash
# Helper script to run MicroXRCEAgent with proper library path and ROS2 environment

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROS2_WS="$SCRIPT_DIR/../ros2_ws"
AGENT_INSTALL="$SCRIPT_DIR/../agent_install"

# Source ROS2 environment to enable DDS middleware
source /opt/ros/galactic/setup.bash
if [ -f "$ROS2_WS/install/setup.bash" ]; then
    source "$ROS2_WS/install/setup.bash"
fi

export LD_LIBRARY_PATH="$AGENT_INSTALL/lib:$LD_LIBRARY_PATH"

"$AGENT_INSTALL/bin/MicroXRCEAgent" "$@"
EOF

chmod +x run_agent.sh

echo -e "${GREEN}✓ Helper script 'run_agent.sh' created${NC}"

################################################################################
# Installation Complete
################################################################################
echo -e "\n${GREEN}========================================${NC}"
echo -e "${GREEN}🎉 Chapter 2 Setup Complete!${NC}"
echo -e "${GREEN}========================================${NC}"

echo -e "\n${YELLOW}Testing the Installation:${NC}"
echo -e "\n${BLUE}Terminal 1 - Start PX4 Simulation:${NC}"
echo -e "  ${GREEN}cd ../PX4-Autopilot${NC}"
echo -e "  ${GREEN}make px4_sitl gazebo-classic${NC}"

echo -e "\n${BLUE}Terminal 2 - Start Micro XRCE-DDS Agent:${NC}"
echo -e "  ${GREEN}cd $SCRIPT_DIR${NC}"
echo -e "  ${GREEN}./run_agent.sh udp4 -p 8888${NC}"
echo -e "\n  ${YELLOW}Expected output:${NC}"
echo -e "    [INFO] UDP Transport listening on port 8888"
echo -e "    [INFO] session established"
echo -e "    [INFO] participant created"

echo -e "\n${BLUE}Terminal 3 - Verify ROS2 Topics:${NC}"
echo -e "  ${GREEN}ros2 topic list${NC}"
echo -e "\n  ${YELLOW}You should see many /fmu/* topics${NC}"

echo -e "\n${BLUE}Terminal 4 - Monitor Drone Data:${NC}"
echo -e "  ${GREEN}ros2 topic echo /fmu/out/vehicle_status${NC}"

echo -e "\n${YELLOW}Troubleshooting:${NC}"
echo -e "  ${RED}If you see 'no Middleware selected' error:${NC}"
echo -e "    1. Make sure ROS2 Galactic is installed"
echo -e "    2. Source ROS2 environment: ${GREEN}source /opt/ros/galactic/setup.bash${NC}"
echo -e "    3. Check DDS libraries: ${GREEN}dpkg -l | grep -E 'cyclonedds|fastrtps'${NC}"

echo -e "\n${YELLOW}Next Steps:${NC}"
echo -e "  1. Create drone_controller package: ${GREEN}ros2 pkg create drone_controller${NC}"
echo -e "  2. Write position monitor node (see tutorial)"
echo -e "  3. Write command publisher node (see tutorial)"
echo -e "  4. Test autonomous flight!"

echo -e "\n${GREEN}Ready to control your drone with ROS2! 🚁${NC}\n"
