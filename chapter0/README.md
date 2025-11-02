# 📦 Chapter 0: Installation

## Overview

This chapter covers the installation of PX4 drone simulation environment.

**What gets installed:**
- Gazebo 11 (3D simulator)
- GStreamer (video streaming)
- PX4-Autopilot (drone firmware)
- MAVLink (communication protocol)
- All required dependencies

---

## 🚀 Quick Start

### 1. Run Installation Script

```bash
cd ~/source4/drone_simulator/chapter0
chmod +x install_drone_sim.sh
./install_drone_sim.sh
```

**Estimated time:** 20-30 minutes

---

## 📚 Detailed Documentation

For step-by-step explanation of what each part of the installation does, see:
- **[INSTALL_GUIDE.md](./INSTALL_GUIDE.md)** - Detailed breakdown of installation steps

---

## 📂 Installation Output

After successful installation, the following will be created in the **parent directory** (not in chapter0):

```
~/source4/drone_simulator/
├── chapter0/              # This chapter (installation files)
│   ├── README.md
│   ├── install_drone_sim.sh
│   └── INSTALL_GUIDE.md
├── chapter1/              # Next chapter (basic flight)
├── PX4-Autopilot/         # ✨ PX4 source code (created here)
└── README.md              # Main project README
```

**Note:** `PX4-Autopilot` is installed in the **root project directory**, not inside chapter0. This allows all chapters to access it.

---

## ✅ Verify Installation

After installation completes:

```bash
# Check if PX4 was built successfully
ls ~/source4/drone_simulator/PX4-Autopilot/build/px4_sitl_default/bin/px4

# Check Gazebo version
gazebo --version
```

---

## 🔧 What Gets Installed

### System Packages
- **Gazebo 11**: 3D physics simulator
- **GStreamer**: Video streaming libraries
- **Build tools**: cmake, ninja, gcc, g++
- **Python tools**: pip, empy, jinja2, yaml

### Python Packages
- kconfiglib
- jsonschema
- pyros-genmsg
- packaging
- pymavlink

### PX4 Source Code
- Repository: https://github.com/PX4/PX4-Autopilot.git
- Location: `~/source4/drone_simulator/PX4-Autopilot/`
- Size: ~2GB (with submodules)

---

## 🐛 Troubleshooting

### Issue: GStreamer build error

If you get GStreamer-related errors during build, the script now includes all necessary packages. Re-run:

```bash
./install_drone_sim.sh
```

### Issue: "Permission denied"

```bash
chmod +x install_drone_sim.sh
```

### Issue: Disk space

Make sure you have at least 10GB free:

```bash
df -h
```

---

## 🎯 Next Steps

Once installation is complete:

1. **Restart terminal** (to apply dialout group)
   ```bash
   exec bash
   ```

2. **Move to Chapter 1**
   ```bash
   cd ../chapter1
   ```

3. **Start your first flight!** 🚁

See [Chapter 1](../chapter1/README.md) for basic flight operations.

---

## 📖 Resources

- [PX4 Official Documentation](https://docs.px4.io/main/en/)
- [Gazebo Documentation](https://gazebosim.org/tutorials)
- [INSTALL_GUIDE.md](./INSTALL_GUIDE.md) - Detailed installation explanation

---

**Installation complete? Ready for Chapter 1!** 🎉
