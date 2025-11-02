# 📘 Chapter 1: Getting Started with PX4 Drone Simulation

## 🎯 Chapter 1 Overview

This chapter covers the basic setup and first flight of a simulated drone using PX4 and Gazebo.

**What you'll learn:**
- Install PX4 simulation environment
- Launch Gazebo simulator
- Control drone with basic commands
- Monitor drone status

---

## 📋 Prerequisites

- Ubuntu 20.04 LTS
- ROS2 Galactic (already installed)
- At least 10GB free disk space
- Internet connection for downloads

---

## 🚀 Step-by-Step Guide

### Step 1: Run Installation Script

First, navigate to Chapter 0 directory and run the installation script:

```bash
cd ../chapter0
chmod +x install_drone_sim.sh
./install_drone_sim.sh
```

**What this does:**
1. Updates system packages
2. Installs Gazebo 11 (3D simulator) + GStreamer (video streaming)
3. Installs PX4 build dependencies
4. Installs MAVLink communication tools
5. Downloads PX4-Autopilot source code (~1-2GB)
6. Builds PX4 in simulation mode (SITL)

**Estimated time:** 20-30 minutes

**Note:** If you encounter a GStreamer error during build, the script now includes all necessary GStreamer packages.

---

### Step 2: Restart Terminal

After installation, restart your terminal to apply dialout group permissions:

```bash
exec bash
```

Or simply close and reopen your terminal.

---

### Step 3: Launch Simulation

Navigate to PX4-Autopilot directory and start the simulation:

```bash
cd ../PX4-Autopilot
make px4_sitl gazebo-classic
```

**What happens:**
- **Gazebo window** opens → 3D simulation environment
- **PX4 console** appears → Command interface for drone control

**First launch note:** Gazebo will download required models automatically. This may take 5-10 minutes on first run.

---

## 🎮 Basic Flight Commands

Once the simulation is running, you can control the drone using PX4 console commands.

### Essential Commands

#### 1. **Arm the Drone** (Enable motors)
```bash
commander arm
```
- Motors are now ready to spin
- Propellers will start spinning slowly
- Required before takeoff

#### 2. **Takeoff**
```bash
commander takeoff
```
- Drone lifts off to 2.5 meters altitude
- Hovers in place automatically
- Watch in Gazebo window!

#### 3. **Land**
```bash
commander land
```
- Drone descends and lands safely
- Motors continue spinning until disarmed

#### 4. **Disarm** (Turn off motors)
```bash
commander disarm
```
- Stops all motors
- Use only when drone is landed

---

## 📊 Monitoring Commands

### Check Drone Status

```bash
commander status
```

**Output shows:**
- Arming state
- Flight mode
- System health
- Battery level

---

### Listen to Sensor Data

#### Combined Sensor Data
```bash
listener sensor_combined
```
Shows:
- Accelerometer (m/s²)
- Gyroscope (rad/s)
- Magnetometer
- Timestamp

Press `Ctrl+C` to stop listening.

---

#### GPS Position
```bash
listener vehicle_gps_position
```
Shows:
- Latitude/Longitude
- Altitude
- Number of satellites
- GPS fix status

---

#### Local Position (relative to start)
```bash
listener vehicle_local_position
```
Shows:
- X, Y, Z position (meters)
- Velocity (m/s)
- Reference point

---

#### Battery Status
```bash
listener battery_status
```
Shows:
- Voltage
- Current
- Remaining percentage
- Time remaining

---

#### IMU Data
```bash
listener vehicle_imu
```
Shows:
- Angular velocity
- Linear acceleration
- Temperature

---

## 🎨 Gazebo Controls

### Camera Controls

| Action | Control |
|--------|---------|
| **Zoom In/Out** | Mouse Wheel |
| **Rotate Camera** | Shift + Left Mouse Drag |
| **Pan Camera** | Ctrl + Left Mouse Drag |
| **Reset View** | R key |

### Simulation Controls

- **Bottom left:** Real-time factor (simulation speed)
- **Play/Pause:** Control simulation time
- **Top menu:** Insert objects, change world

---

## 🔄 Complete Flight Sequence Example

Here's a complete flight from start to finish:

```bash
# 1. Start in project root, then go to PX4-Autopilot
cd PX4-Autopilot

# 2. Launch simulation
make px4_sitl gazebo-classic

# Wait for PX4 console to appear and stabilize (~10 seconds)

# 3. Check status
commander status

# 4. Arm motors
commander arm

# 5. Takeoff
commander takeoff

# Wait and watch drone fly up to 2.5m

# 6. Check position while hovering
listener vehicle_local_position

# Press Ctrl+C to stop listening

# 7. Land
commander land

# Wait for drone to land completely

# 8. Disarm
commander disarm
```

---

## 🚁 Different Drone Models

You can launch different drone configurations:

### Basic Quadcopter (Iris)
```bash
make px4_sitl gazebo-classic_iris
```

### Quadcopter with Depth Camera
```bash
make px4_sitl gazebo-classic_iris_depth_camera
```
- Includes front-facing depth camera
- Useful for obstacle detection
- Required for SLAM (Chapter 3)

### Quadcopter with 2D LiDAR
```bash
make px4_sitl gazebo-classic_iris_rplidar
```
- 2D laser scanner
- 360° obstacle detection
- Good for indoor navigation

### Hexacopter (Typhoon H480)
```bash
make px4_sitl gazebo-classic_typhoon_h480
```
- 6 propellers (more stable)
- Can carry heavier payload
- Better redundancy

---

## 🌍 Different Environments

Launch drone in different worlds:

### Empty World (default)
```bash
make px4_sitl gazebo-classic
```

### Warehouse
```bash
make px4_sitl gazebo-classic_iris__warehouse
```
- Indoor environment
- Obstacles and structures
- Good for navigation testing

### Baylands
```bash
make px4_sitl gazebo-classic_iris__baylands
```
- Outdoor terrain
- Trees and landscape
- GPS navigation testing

### Office
```bash
make px4_sitl gazebo-classic_iris__office
```
- Indoor office layout
- Desks and walls
- SLAM testing environment

---

## 🛠️ Troubleshooting

### Issue: Gazebo window doesn't open

**Solution:**
```bash
# Check Gazebo environment
echo $GAZEBO_MODEL_PATH
echo $GAZEBO_PLUGIN_PATH

# Reset environment
source /usr/share/gazebo/setup.sh

# Try again from project root
cd PX4-Autopilot
make px4_sitl gazebo-classic
```

---

### Issue: "Command 'commander' not found"

**Cause:** PX4 console not fully loaded yet

**Solution:** Wait 5-10 seconds after launch, then try again.

---

### Issue: Build fails with GStreamer error

**Solution:** The installation script now includes GStreamer packages. If you installed before this update:

```bash
sudo apt-get install -y \
    libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav

# Then rebuild from project root
cd PX4-Autopilot
make clean
make px4_sitl gazebo-classic
```

---

### Issue: Drone won't arm

**Possible causes and solutions:**

1. **Pre-flight checks failing**
   ```bash
   commander status
   # Check for error messages
   ```

2. **Wait for GPS lock** (in GPS-enabled worlds)
   ```bash
   listener vehicle_gps_position
   # Wait for "fix_type: 3" (3D fix)
   ```

3. **Force arm** (simulation only!)
   ```bash
   commander arm -f
   ```

---

### Issue: Simulation is very slow

**Solutions:**

1. **Check real-time factor** (bottom left in Gazebo)
   - Should be close to 1.0
   - Lower = simulation is struggling

2. **Reduce graphics quality:**
   - Edit → Physics → Real-time update rate
   - Lower from 1000 to 500

3. **Close other applications** to free up CPU/GPU

---

## 📝 Useful Tips

### 1. **Stop Simulation Cleanly**
Press `Ctrl+C` in the terminal where you ran `make px4_sitl`

### 2. **Quick Restart**
```bash
# After Ctrl+C, just run again:
make px4_sitl gazebo-classic
```

### 3. **View All Topics**
```bash
# In PX4 console:
listener
# Shows all available topics to listen to
```

### 4. **Check MAVLink Messages**
```bash
# Monitor MAVLink communication:
listener mavlink
```

### 5. **Emergency Stop**
```bash
commander disarm -f
# Force disarm immediately (use with caution!)
```

---

## ✅ Chapter 1 Checklist

By the end of Chapter 1, you should be able to:

- [ ] Successfully install PX4 simulation environment
- [ ] Launch Gazebo with PX4 SITL
- [ ] Arm the drone
- [ ] Execute takeoff and landing
- [ ] Monitor sensor data in real-time
- [ ] Navigate Gazebo interface
- [ ] Launch different drone models
- [ ] Launch different environments

---

## 🎓 What You've Learned

**Concepts:**
- ✅ SITL (Software In The Loop) simulation
- ✅ MAVLink communication protocol
- ✅ PX4 flight modes and commands
- ✅ Gazebo physics simulation
- ✅ Sensor data streams (GPS, IMU, etc.)

**Skills:**
- ✅ Basic drone control
- ✅ System monitoring
- ✅ Troubleshooting simulation issues

---

## 🚀 Next Steps: Chapter 2

In **Chapter 2: ROS2 Integration**, you'll learn to:
- Connect ROS2 to PX4
- Control drone using Python/C++ code
- Subscribe to sensor topics in ROS2
- Create autonomous control nodes

**Are you ready to move forward?** 🎉

---

## 📚 Additional Resources

### Official Documentation
- [PX4 User Guide](https://docs.px4.io/main/en/)
- [PX4 Gazebo Simulation](https://docs.px4.io/main/en/simulation/gazebo.html)
- [MAVLink Developer Guide](https://mavlink.io/en/)

### Video Tutorials
- Search: "PX4 SITL Gazebo tutorial"
- Search: "PX4 commander commands"

### Community
- [PX4 Discuss Forum](https://discuss.px4.io/)
- [PX4 Discord](https://discord.com/invite/dronecode)

---

**Congratulations on completing Chapter 1!** 🎊

You've successfully set up your drone simulation environment and performed your first flight. You're now ready to move on to more advanced topics in Chapter 2!

**Happy Flying!** 🚁✨
