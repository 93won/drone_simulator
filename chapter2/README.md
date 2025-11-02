# 📘 Chapter 2: ROS2-PX4 Integration & Offboard Control

## 🎯 Overview

This chapter covers the complete integration of ROS2 with PX4, from basic communication setup to autonomous drone control using Offboard mode.

**What you'll learn:**
- Set up PX4 ↔ ROS2 communication bridge (Micro XRCE-DDS Agent)
- Subscribe to PX4 sensor data in ROS2
- Publish control commands to PX4 from ROS2
- Implement autonomous flight with Offboard mode
- Execute waypoint navigation missions

**Mission Profile:**
```
1. Arm & switch to Offboard mode
2. Takeoff to 5m altitude
3. Move forward 5m
4. Move left 5m  
5. Return to home position
6. Land automatically
```

---

## 📋 Prerequisites

✅ **Completed Chapter 0 & 1:**
- PX4-Autopilot installed and built
- Successfully flown drone manually in Gazebo
- Familiar with PX4 console commands

✅ **Required Software:**
- Ubuntu 20.04 LTS
- ROS2 Galactic (installed in Chapter 0)
- Python 3.8+
- CMake 3.20+ (will be installed if needed)
- PX4-Autopilot (from Chapter 0)

---

## 🛠️ Architecture Overview

```
┌─────────────────────────────────────────┐
│    Your ROS2 Node (offboard_control.py) │
│                                         │
│  ┌──────────────┐   ┌────────────────┐  │
│  │ Subscribe to │   │  Publish       │  │
│  │ /fmu/out/*   │   │  /fmu/in/*     │  │
│  │ (Status/Pos) │   │  (Commands)    │  │
│  └──────────────┘   └────────────────┘  │
└───────────────┬─────────────┬───────────┘
                │             │
                │  uXRCE-DDS  │
                │   Bridge    │
                │  (UDP:8888) │
┌───────────────▼─────────────▼───────────┐
│         PX4 Autopilot (SITL)            │
│                                         │
│  Topics (50+):                          │
│  - /fmu/out/vehicle_status_v1           │
│  - /fmu/out/vehicle_local_position_v1   │
│  - /fmu/in/vehicle_command              │
│  - /fmu/in/offboard_control_mode        │
│  - /fmu/in/trajectory_setpoint          │
└─────────────────────────────────────────┘
```

**Key Components:**
- **PX4 SITL**: Simulated drone with full autopilot firmware
- **Micro XRCE-DDS Agent**: Translates between PX4's XRCE and ROS2's DDS protocols
- **ROS2 Node**: Your Python/C++ code for autonomous control

---

## 🚀 Quick Start

### Installation
```bash
cd ~/drone_simulator/chapter2
./install_chapter2.sh
```

### Testing (4 terminals required)

**Terminal 1: PX4 Simulation**
```bash
cd ~/PX4-Autopilot
make px4_sitl gazebo-classic
```

**Terminal 2: DDS Agent**
```bash
cd ~/drone_simulator/chapter2
../run_agent.sh udp4 -p 8888
```

**Terminal 3: ROS2 Topics Monitor (Optional)**
```bash
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash
ros2 topic list
ros2 topic echo /fmu/out/vehicle_status_v1
```

**Terminal 4: Offboard Control Node**
```bash
cd ~/drone_simulator/chapter2
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash
python3 offboard_control.py
```

**Expected Output:**
```
[INFO] [offboard_control]: === Offboard Control Node Started ===
[INFO] [offboard_control]: >> Sending initial takeoff setpoints...
[INFO] [offboard_control]: Arm command sent
[INFO] [offboard_control]: >> Vehicle ARMED successfully!
[INFO] [offboard_control]: >> Nav state changed: 4 -> 14
[INFO] [offboard_control]: >> OFFBOARD MODE ACTIVE!
[INFO] [offboard_control]: >> [OFFBOARD] Starting takeoff to 5.0m...
[INFO] [offboard_control]: [OFFBOARD] Position: x=0.00, y=0.00, z=-5.00
[INFO] [offboard_control]: >> [OFFBOARD] Moving forward 5m...
[INFO] [offboard_control]: [OFFBOARD] Position: x=5.03, y=0.17, z=-4.97
[INFO] [offboard_control]: >> [OFFBOARD] Moving left 5m...
[INFO] [offboard_control]: [OFFBOARD] Position: x=5.06, y=5.04, z=-4.96
[INFO] [offboard_control]: >> [OFFBOARD] Returning to home...
[INFO] [offboard_control]: [OFFBOARD] Position: x=-0.13, y=-0.14, z=-4.97
[INFO] [offboard_control]: >> [OFFBOARD] Landing...
[INFO] [offboard_control]: >> Nav state changed: 14 -> 18
[INFO] [offboard_control]: === Mission Complete ===
```

---

## 🔧 Understanding the Code

### 1. QoS Profile Configuration

```python
qos_profile = QoSProfile(
    reliability=ReliabilityPolicy.BEST_EFFORT,
    durability=DurabilityPolicy.VOLATILE,
    history=HistoryPolicy.KEEP_LAST,
    depth=10
)
```

**Why these settings?**
- `BEST_EFFORT`: Real-time communication, no retransmission (faster)
- `VOLATILE`: Don't store historical messages (lighter)
- `depth=10`: Keep last 10 messages in queue

### 2. Topic Names (Important!)

PX4 uses `_v1` suffix on output topics:
```python
# Correct:
'/fmu/out/vehicle_status_v1'
'/fmu/out/vehicle_local_position_v1'

# Wrong:
'/fmu/out/vehicle_status'  # Won't receive data!
```

**Input topics (commands) don't need _v1:**
```python
'/fmu/in/vehicle_command'
'/fmu/in/offboard_control_mode'
'/fmu/in/trajectory_setpoint'
```

### 3. Offboard Control Mode

```python
def publish_offboard_control_mode(self):
    msg = OffboardControlMode()
    msg.position = True      # Position control enabled
    msg.velocity = False     # Velocity control disabled
    msg.acceleration = False # Acceleration control disabled
    msg.attitude = False     # Attitude control disabled
    msg.body_rate = False    # Body rate control disabled
    msg.timestamp = 0        # PX4 auto-fills timestamp
    self.offboard_control_mode_publisher.publish(msg)
```

**Critical:** Must publish at 2Hz minimum to maintain Offboard mode!

### 4. NED Coordinate System

PX4 uses **NED** (North-East-Down):
- **X**: North(+) / South(-)
- **Y**: East(+) / West(-)
- **Z**: Down(+) / Up(-) ⚠️ **Negative Z = altitude!**

```python
self.takeoff_height = -5.0  # 5 meters UP (negative!)

# Waypoints:
(0, 0, -5)     # Home at 5m altitude
(5, 0, -5)     # 5m north at 5m altitude
(5, 5, -5)     # 5m north, 5m east at 5m altitude
```

### 5. Control Sequence Timing

```python
# 0-2s (40 loops @ 20Hz): Send setpoints before arming
if self.offboard_setpoint_counter < 40:
    self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)

# 2s: Arm first (required before Offboard mode)
elif self.offboard_setpoint_counter == 40:
    self.arm()

# 2.25s: Switch to Offboard mode (0.25s after arm)
elif self.offboard_setpoint_counter == 45:
    self.engage_offboard_mode()
```

**Why this sequence?**
1. PX4 requires setpoints before accepting Offboard mode
2. Must be armed before switching to Offboard
3. Quick transition (0.25s) prevents timeout

### 6. Vehicle Commands

```python
# Arm
self.publish_vehicle_command(
    VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, 
    param1=1.0)  # 1.0=arm, 0.0=disarm

# Offboard mode
self.publish_vehicle_command(
    VehicleCommand.VEHICLE_CMD_DO_SET_MODE, 
    param1=1.0,  # MAV_MODE_FLAG_CUSTOM_MODE_ENABLED
    param2=6.0)  # PX4_CUSTOM_MAIN_MODE_OFFBOARD

# Land
self.publish_vehicle_command(
    VehicleCommand.VEHICLE_CMD_NAV_LAND)
```

---

## ⚙️ Customization Guide

### Change Mission Waypoints

Edit `timer_callback()` in `offboard_control.py`:

```python
# Takeoff to 10m altitude (instead of 5m)
self.takeoff_height = -10.0

# Custom waypoint sequence
elif self.offboard_setpoint_counter < 400:
    self.publish_position_setpoint(10.0, 0.0, -10.0)  # 10m north

elif self.offboard_setpoint_counter < 600:
    self.publish_position_setpoint(10.0, 10.0, -10.0)  # Square pattern

elif self.offboard_setpoint_counter < 800:
    self.publish_position_setpoint(0.0, 10.0, -10.0)
```

### Switch to Velocity Control

```python
def publish_offboard_control_mode(self):
    msg = OffboardControlMode()
    msg.position = False
    msg.velocity = True  # Enable velocity control
    ...

def publish_velocity_setpoint(self, vx, vy, vz, yaw_rate=0.0):
    """Publish velocity setpoint (m/s)"""
    msg = TrajectorySetpoint()
    msg.velocity = [vx, vy, vz]
    msg.yawspeed = yaw_rate
    msg.timestamp = 0
    self.trajectory_setpoint_publisher.publish(msg)
```

### Add Yaw Control (Heading)

```python
import math

# Face north (0 radians)
self.publish_position_setpoint(5.0, 0.0, -5.0, yaw=0.0)

# Face east (90 degrees = π/2 radians)
self.publish_position_setpoint(5.0, 5.0, -5.0, yaw=math.pi/2)

# Face south (180 degrees = π radians)
self.publish_position_setpoint(0.0, 5.0, -5.0, yaw=math.pi)
```

---

## 🐛 Troubleshooting

### ❌ "No callbacks received" / "Nav state: 0, Arming: 0"

**Cause:** Wrong topic names (missing `_v1` suffix)

**Solution:**
```bash
# Check actual topic names
ros2 topic list | grep vehicle_status

# Should see:
# /fmu/out/vehicle_status_v1 (not vehicle_status)

# Fix in code:
self.vehicle_status_subscriber = self.create_subscription(
    VehicleStatus, '/fmu/out/vehicle_status_v1',  # Add _v1!
    self.vehicle_status_callback, qos_profile)
```

### ❌ "Offboard mode rejected"

**Cause:** Not sending setpoints long enough before mode switch

**Solution:**
- Increase initial setpoint duration (currently 2 seconds is sufficient)
- Ensure `publish_offboard_control_mode()` runs at 20Hz continuously

### ❌ Drone doesn't move / stays on ground

**Cause:** Wrong coordinate system (positive Z instead of negative)

**Solution:**
```python
# Wrong:
self.takeoff_height = 5.0  # This tries to go underground!

# Correct:
self.takeoff_height = -5.0  # Negative = up in NED
```

### ❌ "Failsafe: No manual control stick input"

**Cause:** RC controller not connected (normal for autonomous flight)

**Solution 1:** Ignore (doesn't affect Offboard mode)

**Solution 2:** Disable RC loss failsafe in PX4
```bash
# In PX4 console:
param set COM_RCL_EXCEPT 4  # Allow Offboard without RC
param set NAV_RCL_ACT 0     # Disable RC loss action
```

### ❌ "no Middleware selected" error (Agent)

**Cause:** Agent not built with system FastDDS/CycloneDDS

**Solution:** Reinstall with correct flags
```bash
cd ~/drone_simulator/chapter2
rm -rf ../Micro-XRCE-DDS-Agent/build/*
./install_chapter2.sh  # Uses -DUAGENT_USE_SYSTEM_FASTDDS=ON
```

### ❌ No /fmu/* topics in ROS2

**Checklist:**
1. ✅ PX4 SITL running (`pxh>` prompt visible)
2. ✅ Agent running (`session established` message)
3. ✅ ROS2 environment sourced
   ```bash
   source /opt/ros/galactic/setup.bash
   source ~/ros2_ws/install/setup.bash
   ```
4. ✅ Check PX4 data flow: In PX4 console run `uorb top`

---

## 📊 Mission Timeline Breakdown

| Time | Counter | Action | Setpoint |
|------|---------|--------|----------|
| 0-2s | 0-40 | Send initial setpoints | (0, 0, -5) |
| 2s | 40 | **ARM** command | (0, 0, -5) |
| 2.25s | 45 | **OFFBOARD** mode switch | (0, 0, -5) |
| 2.25-7.5s | 45-150 | **Takeoff** to 5m | (0, 0, -5) |
| 7.5-15s | 150-300 | Hold altitude | (0, 0, -5) |
| 15-25s | 300-500 | **Move forward** 5m | (5, 0, -5) |
| 25-35s | 500-700 | **Move left** 5m | (5, 5, -5) |
| 35-45s | 700-900 | **Return home** | (0, 0, -5) |
| 45s | 900 | **LAND** command | - |

*Counter increments at 20Hz (50ms intervals)*

---

## 📚 Next Steps

### Level 1: Basic Enhancements
- [ ] Add more waypoints (fly a circle, figure-8)
- [ ] Implement yaw control (face specific directions)
- [ ] Adjust flight speed via setpoint frequency

### Level 2: Sensor Integration
- [ ] Subscribe to `/fmu/out/sensor_combined` for IMU data
- [ ] Monitor battery status (`/fmu/out/battery_status`)
- [ ] Log flight data to CSV file

### Level 3: Interactive Control
- [ ] Add keyboard control using `teleop_twist_keyboard`
- [ ] Create ROS2 service for waypoint submission
- [ ] Implement emergency stop service

### Level 4: Autonomous Features
- [ ] Obstacle detection and avoidance
- [ ] GPS waypoint missions
- [ ] Camera integration for vision-based navigation

---

## 📖 Reference

### Official Documentation
- [PX4 Offboard Control](https://docs.px4.io/main/en/flight_modes/offboard.html)
- [PX4 ROS2 User Guide](https://docs.px4.io/main/en/ros/ros2_comm.html)
- [Micro XRCE-DDS](https://micro-xrce-dds.docs.eprosima.com/)
- [px4_msgs API](https://github.com/PX4/px4_msgs)

### Navigation States
| State | Value | Description |
|-------|-------|-------------|
| MANUAL | 0 | Manual flight mode |
| ALTCTL | 1 | Altitude control |
| POSCTL | 2 | Position control |
| AUTO | 3 | Auto mission |
| ACRO | 4 | Acrobatic mode |
| **OFFBOARD** | **14** | **External control** |
| LAND | 18 | Landing mode |

### Arming States
| State | Value | Description |
|-------|-------|-------------|
| DISARMED | 1 | Motors off |
| **ARMED** | **2** | **Motors on, ready to fly** |

---

## ✅ Chapter 2 Completion Checklist

- [ ] PX4 SITL runs successfully
- [ ] Micro XRCE-DDS Agent connects (port 8888)
- [ ] ROS2 topics visible (`/fmu/out/*`, `/fmu/in/*`)
- [ ] Offboard control node runs without errors
- [ ] Drone arms successfully
- [ ] Offboard mode activates (nav_state: 14)
- [ ] Autonomous takeoff to 5m altitude
- [ ] Waypoint navigation completes (forward, left, home)
- [ ] Safe automatic landing
- [ ] Understand code and able to customize waypoints

**Congratulations! You've completed Chapter 2!** 🎉

You now have:
- ✅ Full ROS2-PX4 integration working
- ✅ Autonomous drone control via Offboard mode
- ✅ Understanding of PX4 coordinate systems
- ✅ Ability to create custom flight missions

**Ready for Chapter 3: SLAM & Autonomous Navigation?** 🗺️✨
