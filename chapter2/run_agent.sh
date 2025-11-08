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
