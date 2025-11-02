# 🚁 Autonomous Drone Navigation Simulation Project

# !! Under Construction !!

## 📖 Overview

This project develops an autonomous navigation system for drones to move from point A to point B using PX4 Autopilot and Gazebo.

### Goals
- Localization and mapping using SLAM
- Path planning for autonomous navigation
- Autonomous control using PX4 Offboard mode

---

## 📂 Project Structure

```
drone_simulator/
├── chapter0/          # Installation
│   ├── README.md
│   ├── install_drone_sim.sh
│   └── INSTALL_GUIDE.md
├── chapter1/          # Basic Flight Operations
│   └── README.md
├── chapter2/          # ROS2 Integration & Offboard Control
│   ├── README.md
│   ├── INSTALL.md
│   ├── install_chapter2.sh
│   ├── offboard_control.py
│   └── run_test.sh
├── chapter3/          # Sensor Data Integration (Coming soon)
├── chapter4/          # SLAM Integration (Coming soon)
├── chapter5/          # Navigation in Static Environment (Coming soon)
├── chapter6/          # Navigation in Dynamic Environment (Coming soon)
├── PX4-Autopilot/     # Shared PX4 source code
├── Micro-XRCE-DDS-Agent/  # Communication bridge
├── agent_install/     # Local Agent installation
├── run_agent.sh       # Helper script to run Agent
└── README.md          # This file
```

---

## 📚 Chapters

Follow these chapters in order to build your autonomous drone system:

- **[Chapter 0: Installation](./chapter0/README.md)** ✅
  - Install Gazebo, PX4, and all dependencies
  - Build PX4 in simulation mode
  
- **[Chapter 1: Getting Started - Basic Flight](./chapter1/README.md)** ✅
  - Launch simulation
  - Control drone with PX4 commands
  - Monitor sensor data
  
- **[Chapter 2: ROS2 Integration & Offboard Control](./chapter2/README.md)** ✅
  - Setup PX4 ↔ ROS2 communication bridge (Micro XRCE-DDS Agent)
  - Build px4_msgs for ROS2 (236 message types)
  - Create autonomous control nodes
  - Implement Offboard mode control
  - Execute waypoint navigation missions
  - Complete autonomous flight: Takeoff → Navigate → Land
  
- **Chapter 3: Sensor Data Integration** (Coming soon)

- **Chapter 4: SLAM Integration** (Coming soon)
  
- **Chapter 5: Navigation in Static Environments** (Coming soon)
  
- **Chapter 6: Navigation in Dynamic Environments** (Coming soon)


---

## 🛠️ System Architecture

```
┌─────────────────────────────────────────────────────┐
│            Your Application (ROS2)                  │
│  ┌──────────┐  ┌──────────────┐  ┌──────────────┐   │
│  │   SLAM   │→→│ Path Planning│→→│ PX4 Control  │   │
│  └──────────┘  └──────────────┘  └──────────────┘   │
└─────────────────────────┬───────────────────────────┘
                          │ MAVLink/DDS
┌─────────────────────────▼───────────────────────────┐
│                PX4 Autopilot (SITL)                 │
└─────────────────────────┬───────────────────────────┘
                          │
┌─────────────────────────▼───────────────────────────┐
│              Gazebo Simulator                       │
│  ┌────────────┐  ┌────────────┐  ┌──────────────┐   │
│  │   Drone    │  │  Sensors   │  │ Environment  │   │
│  │  Physics   │  │ (Cam/LiDAR)│  │   (World)    │   │
│  └────────────┘  └────────────┘  └──────────────┘   │
└─────────────────────────────────────────────────────┘
```

---

## 💻 Requirements

### Prerequisites
- **OS**: Ubuntu 20.04 LTS
- **ROS**: ROS2 Galactic ✅ (Already installed)
- **Python**: 3.8+
- **Disk Space**: Minimum 10GB

### Software to be Installed
- **Gazebo 11**: 3D physics simulator
- **PX4-Autopilot**: Drone flight control firmware
- **MAVLink**: Communication protocol

---

## 🚀 Quick Start

### Step 1: Installation (Chapter 0)

Navigate to Chapter 0 and run the installation script:

```bash
cd chapter0
chmod +x install_drone_sim.sh
./install_drone_sim.sh
```

**Estimated Time**: 20-30 minutes

**What gets installed:**
- Gazebo 11 + GStreamer
- PX4-Autopilot source code
- All build dependencies

### Step 2: Restart Terminal

```bash
# Apply dialout group permissions
exec bash
```

### Step 3: First Flight (Chapter 1)

```bash
cd ../chapter1
# Follow the README.md for detailed instructions
```

### Step 4: Launch Simulation

```bash
cd ../PX4-Autopilot
make px4_sitl gazebo-classic
```

### Step 5: Fly!

In the PX4 console:

```bash
commander arm       # Enable motors
commander takeoff   # Lift off to 2.5m
commander land      # Land safely
```

**For detailed instructions, see [Chapter 1 README](./chapter1/README.md)**

---

## 📚 Learning Path

### Phase 1: Basic Control ✅
- [x] Environment setup (Chapter 0)
- [x] Learn PX4 console commands (Chapter 1)
- [x] Learn Gazebo controls (Chapter 1)
- [x] First flight complete! 🎉

### Phase 2: ROS2 Integration & Autonomous Control ✅
- [x] Setup PX4 ↔ ROS2 communication (Micro XRCE-DDS Agent)
- [x] Monitor sensor topics in ROS2 (`/fmu/out/*`)
- [x] Send commands via ROS2 (`/fmu/in/*`)
- [x] Create autonomous control nodes (Python)
- [x] Implement Offboard mode control
- [x] Execute autonomous missions (waypoint navigation)
- [x] Complete autonomous flight tested successfully! 🎉

### Phase 3: SLAM (Chapter 3 & 4 - Coming Soon)
- [ ] Understand and monitor sensor data streams
- [ ] Add depth camera/LiDAR sensors to drone
- [ ] Install RTAB-Map or Cartographer SLAM
- [ ] Generate maps in simulation
- [ ] Save and reload maps for navigation
- [ ] Test localization accuracy

### Phase 4: Autonomous Navigation (Chapter 5 & 6 - Coming Soon)
- [ ] Implement path planning algorithms (A*, RRT)
- [ ] Navigate in static environments with known maps
- [ ] Detect and track dynamic obstacles
- [ ] Implement reactive navigation (DWA, potential fields)
- [ ] Complete autonomous missions with obstacle avoidance
- [ ] Full A → B navigation with safety guarantees

---

## 🔧 Troubleshooting

For detailed troubleshooting guides, see:
- [Chapter 0 README](./chapter0/README.md) - Installation issues
- [Chapter 1 README](./chapter1/README.md) - Simulation and flight issues

### Common Issues

**Installation fails?** → See Chapter 0 troubleshooting
**Gazebo won't open?** → See Chapter 1 troubleshooting
**Drone won't arm?** → See Chapter 1 troubleshooting

---

## 📖 Additional Resources

### Official Documentation
- [PX4 User Guide](https://docs.px4.io/main/en/)
- [PX4 Gazebo Simulation](https://docs.px4.io/main/en/simulation/gazebo.html)
- [ROS2 + PX4 Integration](https://docs.px4.io/main/en/ros/ros2_comm.html)
- [Gazebo Tutorials](https://gazebosim.org/tutorials)
- [MAVLink Protocol](https://mavlink.io/en/)

### Chapter-Specific Guides
- [Chapter 0: Installation Guide](./chapter0/INSTALL_GUIDE.md)
- [Chapter 1: Getting Started Guide](./chapter1/README.md)
- [Chapter 2: ROS2 Integration Guide](./chapter2/README.md)
- [Chapter 2: Installation Guide](./chapter2/INSTALL.md)

---

## 🤝 Contributing

Feel free to suggest issues or improvements!

---

**Happy Flying! 🚁**
