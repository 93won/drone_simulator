# 📋 Step-by-Step Script Explanation

## Understanding the Overall Structure

```
Installation Script
    ↓
[1] System Update
    ↓
[2] Install Gazebo 11 ← 3D Simulator
    ↓
[3] PX4 Build Tools ← Compilers, Python Tools
    ↓
[4] MAVLink Tools ← PX4 Communication Library
    ↓
[5] Download PX4 Source ← Clone from GitHub
    ↓
[6] Build PX4 ← Actual Compilation (takes time)
    ↓
Done!
```

---

## Detailed Step Explanation

### 🔷 Step 1: System Update
```bash
sudo apt-get update
```

**Purpose**: Update package manager's package list

**Time**: 30 seconds ~ 1 minute

**Why needed?**: To install the latest versions of packages

---

### 🔷 Step 2: Install Gazebo 11
```bash
sudo apt-get install -y \
    gazebo11 \                      # Gazebo simulator main package
    libgazebo11-dev \               # Development libraries
    ros-galactic-gazebo-ros-pkgs \  # ROS2 ↔ Gazebo bridge
    ros-galactic-gazebo-plugins     # Gazebo plugins
```

**Purpose**: Build 3D environment for drone simulation

**Time**: 5-10 minutes (Download size: ~500MB)

**What gets installed**:
- **gazebo11**: Main simulator
  - Physics engine (gravity, air resistance, collision)
  - 3D rendering
  - Sensor simulation
  
- **libgazebo11-dev**: Development libraries
  - C++ header files
  - For custom plugin development
  
- **ros-galactic-gazebo-ros-pkgs**: ROS2 integration
  - `/gazebo/...` topics
  - Control Gazebo from ROS2
  
- **ros-galactic-gazebo-plugins**: Sensor plugins
  - Camera, LiDAR, IMU, etc.

**Why Gazebo 11?**
| Version | ROS2 Compatibility | Status |
|---------|-------------------|--------|
| Gazebo 9 | Dashing | Old version |
| **Gazebo 11** | **Galactic** ✅ | **Currently used** |
| Gazebo Garden | Humble | New version (for ROS2 Humble) |

---

### 🔷 Step 3: PX4 Build Dependencies
```bash
sudo apt-get install -y \
    git \                    # Version control
    cmake \                  # Build system
    build-essential \        # Basic compilation tools (gcc, g++, make)
    genromfs \               # ROM file system generation
    ninja-build \            # Fast build tool
    python3-pip \            # Python package manager
    python3-dev \            # Python development headers
    python3-empy \           # Template engine
    python3-toml \           # TOML file parsing
    python3-numpy \          # Numerical computation
    python3-jinja2 \         # Template engine
    python3-yaml             # YAML file parsing
```

**Purpose**: Tools for compiling PX4 source code

**Time**: 3-5 minutes

**Role of each tool**:

| Tool | Role | Used in PX4 for |
|------|------|-----------------|
| **cmake** | Build configuration management | Entire build system |
| **ninja** | Fast compilation | Used instead of make |
| **empy** | Code generation | MAVLink message generation |
| **jinja2** | Template processing | Config file generation |
| **genromfs** | File system creation | Embedded firmware files |

**Additional Python packages**:
```bash
pip3 install --user \
    kconfiglib \      # Kconfig file parsing (build config)
    jsonschema \      # JSON validation
    pyros-genmsg \    # ROS message generation
    packaging         # Version management
```

---

### 🔷 Step 4: MAVLink Tools
```bash
pip3 install --user pymavlink
sudo usermod -a -G dialout $USER
```

**Purpose**: Library for communicating with PX4

**Time**: 1 minute

**What is pymavlink?**
- Use MAVLink protocol in Python
- Required for drone control scripts
- Example:
  ```python
  from pymavlink import mavutil
  master = mavutil.mavlink_connection('udp:127.0.0.1:14550')
  master.mav.command_long_send(...)  # Send command
  ```

**What is dialout group?**
- Serial port (/dev/ttyUSB*, /dev/ttyACM*) access permissions
- Required for actual drone hardware connection
- Not directly used in simulation

---

### 🔷 Step 5: Download PX4-Autopilot
```bash
git clone https://github.com/PX4/PX4-Autopilot.git --recursive
```

**Purpose**: Fetch PX4 firmware source code

**Time**: 5-15 minutes (depends on network speed)

**Size**: About 1-2GB

**Meaning of `--recursive` flag**:
- PX4 includes multiple submodules
- Submodule examples:
  - MAVLink (protocol)
  - uORB (messaging)
  - ECL (control library)
  - Drivers

**Directory structure**:
```
PX4-Autopilot/
├── src/                    # Main source code
│   ├── modules/           # Feature modules
│   │   ├── commander/     # State management
│   │   ├── navigator/     # Path planning
│   │   └── mc_pos_control/ # Position control
│   ├── drivers/           # Sensor drivers
│   └── lib/               # Libraries
├── Tools/                 # Build/simulation tools
│   └── sitl_gazebo/       # Gazebo plugins
├── msg/                   # uORB message definitions
└── ROMFS/                 # Firmware filesystem
```

---

### 🔷 Step 6: Build PX4
```bash
cd PX4-Autopilot
bash ./Tools/setup/ubuntu.sh --no-nuttx --no-sim-tools
make px4_sitl gazebo-classic
```

**Purpose**: Compile PX4 firmware for simulation

**Time**: 10-20 minutes (first build, depends on CPU)

#### 6-1. Setup script
```bash
bash ./Tools/setup/ubuntu.sh --no-nuttx --no-sim-tools
```
- **--no-nuttx**: Exclude real hardware build tools (simulation only)
- **--no-sim-tools**: Exclude some simulator tools (use Gazebo only)
- Automatically installs additional dependencies

#### 6-2. Build command
```bash
make px4_sitl gazebo-classic
```

**Command breakdown**:
- `make`: Run build system
- `px4_sitl`: **S**oftware **I**n **T**he **L**oop (simulation target)
- `gazebo-classic`: Include Gazebo Classic plugins

**What gets built?**
1. **PX4 firmware** (px4 executable)
2. **Gazebo plugins**
   - Drone models
   - Sensor plugins
   - Environment models
3. **SITL bridge**
   - PX4 ↔ Gazebo communication

**Build output**:
```
build/
└── px4_sitl_default/
    ├── bin/
    │   └── px4              # Executable
    └── build_gazebo/
        └── libgazebo_*.so   # Gazebo plugins
```

---

## Estimated Total Time

| Step | Time | Note |
|------|------|------|
| 1. System Update | 1 min | - |
| 2. Gazebo Install | 5-10 min | Download: ~500MB |
| 3. PX4 Dependencies | 3-5 min | - |
| 4. MAVLink Tools | 1 min | - |
| 5. PX4 Download | 5-15 min | Download: ~1-2GB |
| 6. PX4 Build | 10-20 min | High CPU usage |
| **Total** | **25-52 min** | Depends on network/CPU |

---

## Disk Space Usage

```
Gazebo 11:           ~1 GB
PX4-Autopilot:       ~2 GB (source)
Build artifacts:     ~3 GB
Additional deps:     ~1 GB
─────────────────────────
Total:               ~7 GB
```

**Recommended free space**: 10GB or more

---

## Verification Methods

### ✅ Verify Gazebo installation
```bash
gazebo --version
# Gazebo multi-robot simulator, version 11.x.x
```

### ✅ Verify PX4 build
```bash
cd PX4-Autopilot
ls build/px4_sitl_default/bin/px4
# Success if file exists
```

### ✅ Execution test
```bash
cd PX4-Autopilot
make px4_sitl gazebo-classic
# Success if Gazebo window + PX4 console appear
```

---

## Troubleshooting

### ❌ "No space left on device"
```bash
# Check disk space
df -h

# Clean unnecessary files
sudo apt-get clean
sudo apt-get autoremove
```

### ❌ Python package installation failed
```bash
# Upgrade pip
pip3 install --upgrade pip

# Retry
pip3 install --user kconfiglib jsonschema
```

### ❌ "ninja: build stopped: subcommand failed" during build
```bash
# Possible memory shortage
# Limit parallel build
make px4_sitl gazebo-classic -j2  # Use only 2 cores
```

### ❌ Gazebo doesn't run
```bash
# Check DISPLAY environment variable (GUI required)
echo $DISPLAY

# Reset Gazebo environment
source /usr/share/gazebo/setup.sh
```

---

## Next Steps

After running the script:

1. **Restart terminal** (apply dialout group)
   ```bash
   exec bash
   ```

2. **Run first simulation**
   ```bash
   cd PX4-Autopilot
   make px4_sitl gazebo-classic
   ```

3. **Test PX4 commands**
   ```bash
   commander arm
   commander takeoff
   ```

4. **Read next document**: See `README.md`

---

**Ready? Run the script!** 🚀

```bash
chmod +x install_drone_sim.sh
./install_drone_sim.sh
```
