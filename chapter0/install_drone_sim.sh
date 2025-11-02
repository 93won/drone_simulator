#!/bin/bash

################################################################################
# PX4 + Gazebo Drone Simulation Environment Installation Script
# For Ubuntu 20.04 + ROS2 Galactic
################################################################################

set -e  # Stop script on error

# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}PX4 Drone Simulation Setup Started${NC}"
echo -e "${GREEN}========================================${NC}"

################################################################################
# Step 1: System Update
################################################################################
echo -e "\n${YELLOW}[1/6] Updating system packages...${NC}"
sudo apt-get update

################################################################################
# Step 2: Install Gazebo 11
################################################################################
echo -e "\n${YELLOW}[2/6] Installing Gazebo 11...${NC}"
echo "Gazebo is a 3D physics simulator. It simulates drone dynamics, sensors, and environments."

sudo apt-get install -y \
    gazebo11 \
    libgazebo11-dev \
    ros-galactic-gazebo-ros-pkgs \
    ros-galactic-gazebo-plugins \
    libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav

echo -e "${GREEN}✓ Gazebo 11 installation completed${NC}"

################################################################################
# Step 3: Install PX4 Dependencies
################################################################################
echo -e "\n${YELLOW}[3/6] Installing PX4 build dependencies...${NC}"
echo "Installing tools required for PX4 compilation."

sudo apt-get install -y \
    git \
    cmake \
    build-essential \
    genromfs \
    ninja-build \
    python3-pip \
    python3-dev \
    python3-empy \
    python3-toml \
    python3-numpy \
    python3-jinja2 \
    python3-yaml

# Install Python packages
pip3 install --user \
    kconfiglib \
    jsonschema \
    pyros-genmsg \
    packaging

echo -e "${GREEN}✓ PX4 dependencies installation completed${NC}"

################################################################################
# Step 4: Install MAVLink Tools
################################################################################
echo -e "\n${YELLOW}[4/6] Installing MAVLink tools...${NC}"
echo "MAVLink is the communication protocol for PX4."

pip3 install --user pymavlink

# Additional setup for QGroundControl
sudo usermod -a -G dialout $USER

echo -e "${GREEN}✓ MAVLink tools installation completed${NC}"

################################################################################
# Step 5: Download PX4-Autopilot
################################################################################
echo -e "\n${YELLOW}[5/6] Downloading PX4-Autopilot...${NC}"
echo "Cloning PX4 firmware from GitHub to parent directory. (~1-2GB, may take some time)"

if [ -d "../PX4-Autopilot" ]; then
    echo -e "${YELLOW}PX4-Autopilot folder already exists in parent directory. Skipping.${NC}"
else
    cd ..
    git clone https://github.com/PX4/PX4-Autopilot.git --recursive
    cd chapter0
    echo -e "${GREEN}✓ PX4-Autopilot download completed${NC}"
fi

################################################################################
# Step 6: Build PX4 (SITL + Gazebo Classic)
################################################################################
echo -e "\n${YELLOW}[6/6] Building PX4 and installing Gazebo plugins...${NC}"
echo "Building PX4 in simulation mode (SITL). First build takes 10-20 minutes."

cd ../PX4-Autopilot

# Run build script (also installs Gazebo dependencies)
bash ./Tools/setup/ubuntu.sh --no-nuttx --no-sim-tools

# Build SITL + Gazebo Classic
make px4_sitl gazebo-classic

cd ../chapter0

echo -e "${GREEN}✓ PX4 build completed${NC}"

################################################################################
# Installation Complete & Instructions
################################################################################
echo -e "\n${GREEN}========================================${NC}"
echo -e "${GREEN}🎉 Installation Complete!${NC}"
echo -e "${GREEN}========================================${NC}"

echo -e "\n${YELLOW}Next Steps:${NC}"
echo -e "1. Restart terminal to apply dialout group permissions:"
echo -e "   ${GREEN}exec bash${NC}"
echo -e ""
echo -e "2. Move to Chapter 1 to start flying:"
echo -e "   ${GREEN}cd ../chapter1${NC}"
echo -e ""
echo -e "3. Or test simulation directly:"
echo -e "   ${GREEN}cd ../PX4-Autopilot${NC}"
echo -e "   ${GREEN}make px4_sitl gazebo-classic${NC}"

echo -e "\n${YELLOW}Important Notes:${NC}"
echo -e "- PX4-Autopilot is installed in: ${GREEN}~/source4/drone_simulator/PX4-Autopilot/${NC}"
echo -e "- First run may take time to download Gazebo models"
echo -e "- See Chapter 1 for detailed flight instructions"

echo -e "\n${GREEN}Installation complete! Ready for Chapter 1! 🚁${NC}\n"
