#!/bin/bash
# Helper script to run MicroXRCEAgent with proper library path and ROS2 environment

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROS2_WS="$SCRIPT_DIR/../ros2_ws"
AGENT_INSTALL="$SCRIPT_DIR/../agent_install"

# Source ROS2 environment to enable DDS middleware
# Try Humble first (Ubuntu 22.04), fallback to Galactic (Ubuntu 20.04)
if [ -f /opt/ros/humble/setup.bash ]; then
    source /opt/ros/humble/setup.bash
elif [ -f /opt/ros/galactic/setup.bash ]; then
    source /opt/ros/galactic/setup.bash
else
    echo "Warning: ROS2 setup.bash not found in /opt/ros/humble or /opt/ros/galactic"
fi

if [ -f "$ROS2_WS/install/setup.bash" ]; then
    source "$ROS2_WS/install/setup.bash"
fi

export LD_LIBRARY_PATH="$AGENT_INSTALL/lib:$LD_LIBRARY_PATH"

"$AGENT_INSTALL/bin/MicroXRCEAgent" "$@"
