#!/bin/bash
# Helper script to run MicroXRCEAgent with proper library path and ROS2 environment

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Source ROS2 environment to enable DDS middleware
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash

export LD_LIBRARY_PATH="$SCRIPT_DIR/agent_install/lib:$LD_LIBRARY_PATH"

"$SCRIPT_DIR/agent_install/bin/MicroXRCEAgent" "$@"
