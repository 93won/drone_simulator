# 📋 Chapter 2: Installation Guide
## ROS2-PX4 Integration Setup

---

## 📌 Overview

This guide walks you through installing and configuring the **Micro XRCE-DDS Agent**, which acts as a bridge between PX4 (using XRCE protocol) and ROS2 (using DDS protocol).

**Installation Time:** 10-15 minutes  
**Disk Space Required:** ~500MB  
**Prerequisites:** 
- ROS2 Galactic installed
- PX4-Autopilot installed and working
- CMake 3.20 or higher

---

## 🏗️ Architecture

```
Communication Flow:
    
┌─────────────┐     XRCE      ┌──────────────┐     DDS      ┌──────────┐
│ PX4 (SITL)  │ ←──────────→  │ Micro XRCE   │ ←─────────→  │   ROS2   │
│             │  UDP:8888     │ DDS Agent    │              │  Nodes   │
└─────────────┘               └──────────────┘              └──────────┘
   Lightweight                   Translator                   Full DDS
   XRCE Client                 (Runs on PC)                   Messages
```

**What gets installed:**
1. **CMake 3.20+** (if needed) - Build system
2. **px4_msgs** - ROS2 message definitions for PX4 (236 message types)
3. **Micro XRCE-DDS Agent** - Communication bridge

---

## 🚀 Quick Installation

### Option 1: Automated Script (Recommended)

```bash
cd ~/drone_simulator/chapter2
./install_chapter2.sh
```

This script automatically:
- ✅ Checks CMake version (installs 3.20 if needed)
- ✅ Verifies ROS2 Galactic installation
- ✅ Builds px4_msgs package
- ✅ Installs Micro XRCE-DDS Agent with system FastDDS support
- ✅ Creates `run_agent.sh` helper script
- ✅ Adds ROS2 workspace to `~/.bashrc`

**Jump to [Testing](#-testing-the-installation) section after running the script.**

---

### Option 2: Manual Step-by-Step Installation

Follow these steps if you want to understand each component or if the automated script fails.

---

## 📝 Manual Installation Steps

### Step 1: Check CMake Version

Micro XRCE-DDS Agent requires CMake 3.20 or higher.

```bash
cmake --version
```

**Expected:** `cmake version 3.20.6` or higher

**If version is below 3.20:**

```bash
# Download CMake 3.20.6
cd /tmp
wget https://github.com/Kitware/CMake/releases/download/v3.20.6/cmake-3.20.6-linux-x86_64.sh

# Install to ~/.local (no sudo required)
chmod +x cmake-3.20.6-linux-x86_64.sh
./cmake-3.20.6-linux-x86_64.sh --prefix=$HOME/.local --skip-license

# Add to PATH
export PATH="$HOME/.local/bin:$PATH"

# Permanently add to PATH
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc

# Verify
cmake --version
```

**Why CMake 3.20?**
- Micro XRCE-DDS Agent v2.4+ uses modern CMake features
- Ubuntu 20.04 ships with CMake 3.16 (too old)

---

### Step 2: Verify ROS2 Installation

```bash
# Source ROS2 environment
source /opt/ros/galactic/setup.bash

# Check ROS2 version
ros2 --version
```

**Expected:** `ros2 cli version galactic`

**Verify DDS middleware (CRITICAL!):**

```bash
dpkg -l | grep -E "cyclonedds|fastrtps"
```

**Expected output (at least one):**
```
ii  ros-galactic-cyclonedds
ii  ros-galactic-fastrtps
ii  ros-galactic-rmw-cyclonedds-cpp
ii  ros-galactic-rmw-fastrtps-cpp
```

**If missing:**
```bash
sudo apt update
sudo apt install ros-galactic-fastrtps ros-galactic-rmw-fastrtps-cpp
```

**Why is DDS important?**
- The Agent uses DDS (Data Distribution Service) to communicate with ROS2
- Without DDS libraries, you'll get "no Middleware selected" error
- ROS2 Galactic includes FastRTPS and CycloneDDS by default

---

### Step 3: Build PX4 Messages for ROS2

#### 3.1 Create Workspace and Clone Messages

```bash
# Create ROS2 workspace
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src

# Clone PX4 message definitions
git clone https://github.com/PX4/px4_msgs.git
```

**What's in px4_msgs?**
- 236 message type definitions (`.msg` files)
- Covers all PX4 sensors, actuators, and control messages
- Examples: `VehicleStatus`, `VehicleLocalPosition`, `VehicleCommand`

#### 3.2 Build Messages

```bash
cd ~/ros2_ws

# Source ROS2 first
source /opt/ros/galactic/setup.bash

# Build (takes 2-3 minutes)
colcon build

# Source the new workspace
source install/setup.bash
```

**Build process:**
1. Converts `.msg` files to C++ and Python code
2. Creates ROS2 message libraries
3. Installs to `~/ros2_ws/install/`

#### 3.3 Add to Shell Environment

```bash
# Add to ~/.bashrc for permanent availability
echo "source ~/ros2_ws/install/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

#### 3.4 Verify Installation

```bash
# List PX4 message types (should show 236 messages)
ros2 interface list | grep px4_msgs | wc -l

# View a specific message structure
ros2 interface show px4_msgs/msg/VehicleStatus
```

---

### Step 4: Install Micro XRCE-DDS Agent

#### ⚠️ CRITICAL: Use System FastDDS

**Previous Failed Approach:**
```bash
# ❌ DON'T DO THIS - Builds Agent without DDS support
cmake .. -DUAGENT_FAST_PROFILE=OFF
```
**Result:** "no Middleware selected" error at runtime

**Correct Approach:**
```bash
# ✅ DO THIS - Uses ROS2's existing FastDDS libraries
cmake .. -DUAGENT_USE_SYSTEM_FASTDDS=ON \
         -DUAGENT_USE_SYSTEM_FASTCDR=ON
```
**Result:** Agent can communicate with ROS2 DDS network

#### 4.1 Clone Repository

```bash
cd ~/drone_simulator
git clone https://github.com/eProsima/Micro-XRCE-DDS-Agent.git
cd Micro-XRCE-DDS-Agent
```

#### 4.2 Configure Build

```bash
mkdir -p build
cd build

# CRITICAL: Source ROS2 environment first to detect FastDDS
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash

# Configure with system FastDDS support
cmake .. \
    -DUAGENT_USE_SYSTEM_FASTDDS=ON \
    -DUAGENT_USE_SYSTEM_FASTCDR=ON \
    -DCMAKE_INSTALL_PREFIX=../../agent_install
```

**CMake Options Explained:**

| Option | Purpose | Why Needed? |
|--------|---------|-------------|
| `DUAGENT_USE_SYSTEM_FASTDDS=ON` | Use FastDDS from ROS2 | Enables DDS middleware |
| `DUAGENT_USE_SYSTEM_FASTCDR=ON` | Use FastCDR from ROS2 | Compatible serialization |
| `CMAKE_INSTALL_PREFIX=...` | Local install path | No sudo required |

**Verify Configuration:**
Look for this in CMake output:
```
-- Found FastRTPS
-- Found FastCDR
-- Middleware support: ENABLED
```

#### 4.3 Build and Install

```bash
# Compile (2-3 minutes)
make -j$(nproc)

# Install to ../agent_install/
make install
```

**Installation Result:**
```
agent_install/
├── bin/
│   └── MicroXRCEAgent        # Main executable
├── lib/
│   └── libmicroxrcedds_agent.so.2.4.2
└── include/
    └── uxr/agent/...
```

#### 4.4 Create Helper Script

The Agent needs ROS2 environment variables to find DDS libraries.

```bash
cd ~/drone_simulator

cat > run_agent.sh << 'EOF'
#!/bin/bash
# Helper script to run MicroXRCEAgent with proper environment

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# CRITICAL: Source ROS2 to enable DDS middleware
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash

# Add Agent library path
export LD_LIBRARY_PATH="$SCRIPT_DIR/agent_install/lib:$LD_LIBRARY_PATH"

# Run the Agent
"$SCRIPT_DIR/agent_install/bin/MicroXRCEAgent" "$@"
EOF

chmod +x run_agent.sh
```

**Why this script is essential:**
- Without `source /opt/ros/galactic/setup.bash`: Agent can't find FastDDS
- Without `source ~/ros2_ws/install/setup.bash`: Agent can't use px4_msgs
- Without `LD_LIBRARY_PATH`: Agent can't load its own libraries

---

## ✅ Testing the Installation

### Test 1: PX4 Simulation

**Terminal 1:**
```bash
cd ~/PX4-Autopilot
make px4_sitl gazebo-classic
```

**Wait for:**
```
INFO  [commander] EKF2 IMU aligned
INFO  [commander] home position set
pxh>
```

---

### Test 2: Start DDS Agent

**Terminal 2:**
```bash
cd ~/drone_simulator
./run_agent.sh udp4 -p 8888
```

**Success indicators:**
```
[INFO] UDPv4AgentLinux.cpp | init | running... | port: 8888
[INFO] Root.cpp | create_client | create | client_key: 0x00000001
[INFO] SessionManager.hpp | establish_session | session established
[INFO] ProxyClient.cpp | create_participant | participant created
[INFO] ProxyClient.cpp | create_topic | topic created
[INFO] ProxyClient.cpp | create_subscriber | subscriber created
[INFO] ProxyClient.cpp | create_datareader | datareader created
```

**Key messages:**
- ✅ `session established` → PX4 connected
- ✅ `participant created` → DDS middleware working!
- ✅ `topic created` → ROS2 topics being registered

**If you see errors, check [Troubleshooting](#-troubleshooting) section.**

---

### Test 3: Verify ROS2 Topics

**Terminal 3:**
```bash
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash

# List all topics
ros2 topic list
```

**Expected output (50+ topics):**
```
/fmu/in/vehicle_command
/fmu/out/battery_status
/fmu/out/sensor_combined
/fmu/out/vehicle_attitude
/fmu/out/vehicle_local_position_v1
/fmu/out/vehicle_status_v1
/fmu/out/vehicle_gps_position
... (and many more)
```

**Topic Structure:**
- `/fmu/out/*` → PX4 → ROS2 (sensor data, status)
- `/fmu/in/*` → ROS2 → PX4 (commands, setpoints)

---

### Test 4: Real-time Data Monitoring

**Monitor drone status:**
```bash
ros2 topic echo /fmu/out/vehicle_status_v1
```

**Monitor position:**
```bash
ros2 topic echo /fmu/out/vehicle_local_position_v1
```

**Make the drone fly (in PX4 Terminal 1):**
```bash
pxh> commander arm
pxh> commander takeoff
```

**You should see real-time position updates in Terminal 3!**

---

## 🐛 Troubleshooting

### ❌ Error: "no Middleware selected"

```
[CRITICAL] ProxyClient.cpp | ProxyClient | no Middleware selected
```

**Cause:** Agent was built without DDS support, or ROS2 environment not sourced

**Fix 1: Rebuild Agent with System FastDDS**
```bash
cd ~/drone_simulator/Micro-XRCE-DDS-Agent/build
rm -rf *
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash
cmake .. \
    -DUAGENT_USE_SYSTEM_FASTDDS=ON \
    -DUAGENT_USE_SYSTEM_FASTCDR=ON \
    -DCMAKE_INSTALL_PREFIX=../../agent_install
make -j$(nproc)
make install
```

**Fix 2: Verify DDS Libraries**
```bash
dpkg -l | grep fastrtps
# Should show ros-galactic-fastrtps
```

**Fix 3: Check run_agent.sh Script**
```bash
cat ~/drone_simulator/run_agent.sh
# Must contain:
#   source /opt/ros/galactic/setup.bash
#   source ~/ros2_ws/install/setup.bash
```

---

### ❌ Error: "bind error | port: 8888"

**Cause:** Port 8888 already in use (Agent already running)

**Fix:**
```bash
# Kill existing Agent
pkill -f MicroXRCEAgent

# Or use different port
./run_agent.sh udp4 -p 8889

# (And update PX4 client to use 8889)
```

---

### ❌ Error: "cmake: command not found"

**Cause:** CMake not installed or not in PATH

**Fix:** Follow [Step 1: Check CMake Version](#step-1-check-cmake-version)

---

### ❌ Error: "CMake 3.20 or higher required"

**Cause:** Ubuntu 20.04 ships with CMake 3.16

**Fix:** Install CMake 3.20+ (see Step 1)

---

### ❌ No /fmu/* topics visible in ROS2

**Diagnostic Checklist:**

1. **Is PX4 running?**
   ```bash
   # Should see pxh> prompt in Terminal 1
   ```

2. **Is Agent connected?**
   ```bash
   # Terminal 2 should show "session established"
   ```

3. **ROS2 environment sourced?**
   ```bash
   source /opt/ros/galactic/setup.bash
   source ~/ros2_ws/install/setup.bash
   ```

4. **PX4 data flowing?**
   ```bash
   # In PX4 console (Terminal 1):
   pxh> uorb top
   # Should show topics updating
   ```

5. **Agent middleware working?**
   ```bash
   # Terminal 2 should NOT show "no Middleware selected"
   # Should show "participant created"
   ```

---

### ❌ px4_msgs not found

**Symptoms:**
```
Package 'px4_msgs' not found
```

**Fix:**
```bash
cd ~/ros2_ws
source /opt/ros/galactic/setup.bash
colcon build
source install/setup.bash
```

---

## 📊 Installation Summary

### Installed Components

```
~/ros2_ws/
├── src/
│   └── px4_msgs/              # PX4 message definitions
└── install/
    └── px4_msgs/              # Built message libraries (236 types)

~/drone_simulator/
├── Micro-XRCE-DDS-Agent/      # Agent source code
│   └── build/                 # Build directory
├── agent_install/             # Agent installation
│   ├── bin/MicroXRCEAgent     # Executable
│   └── lib/                   # Libraries
└── run_agent.sh               # Helper script (IMPORTANT!)
```

### ~/.bashrc Additions

```bash
# ROS2 workspace (px4_msgs)
source ~/ros2_ws/install/setup.bash

# Optional: CMake 3.20
export PATH="$HOME/.local/bin:$PATH"
```

---

## 🎯 Performance Metrics

| Metric | Value |
|--------|-------|
| **Message Latency** | ~1-2ms (local UDP) |
| **Available Topics** | 50+ bidirectional |
| **Message Rate** | 100-500 Hz (varies by topic) |
| **Agent CPU Usage** | ~5-10% |
| **Agent Memory** | ~50MB |
| **Build Time (px4_msgs)** | 2-3 minutes |
| **Build Time (Agent)** | 2-3 minutes |

---

## 🚀 Next Steps

### 1. Create Your First ROS2 Control Node

```bash
cd ~/ros2_ws/src
ros2 pkg create --build-type ament_python drone_controller \
    --dependencies rclpy px4_msgs
```

### 2. Run the Offboard Control Example

```bash
cd ~/drone_simulator/chapter2
python3 offboard_control.py
```

**See `README.md` for complete usage guide.**

### 3. Monitor and Debug

```bash
# Check topic rates
ros2 topic hz /fmu/out/vehicle_status_v1

# Inspect message structure
ros2 interface show px4_msgs/msg/VehicleCommand

# Log topics to file
ros2 bag record -a
```

---

## 📚 Additional Resources

### Official Documentation
- [PX4 ROS2 Guide](https://docs.px4.io/main/en/ros/ros2_comm.html)
- [Micro XRCE-DDS Docs](https://micro-xrce-dds.docs.eprosima.com/)
- [ROS2 Galactic](https://docs.ros.org/en/galactic/)

### Community
- [PX4 Forum](https://discuss.px4.io/)
- [ROS Answers](https://answers.ros.org/)

---

## ✅ Installation Checklist

- [ ] CMake 3.20+ installed
- [ ] ROS2 Galactic environment working
- [ ] FastDDS/CycloneDDS libraries present
- [ ] px4_msgs built (236 message types)
- [ ] Micro XRCE-DDS Agent installed with system FastDDS
- [ ] `run_agent.sh` helper script created
- [ ] PX4 SITL connects to Agent successfully
- [ ] ROS2 topics `/fmu/out/*` and `/fmu/in/*` visible
- [ ] Real-time data streaming confirmed

**🎉 Installation Complete! Ready for autonomous flight!**

See `README.md` for the complete Offboard control tutorial.
