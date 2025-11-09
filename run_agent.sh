#!/bin/bash
################################################################################
# @file      run_agent.sh
# @brief     Helper script to run Micro XRCE-DDS Agent
# @author    Eugene (93won)
# @date      2025-11-09
# @copyright Copyright (c) 2025 Eugene. All rights reserved.
#
# @par License
# This project is released under the MIT License.
#
# @par Description
# Runs MicroXRCEAgent with proper library path and ROS2 environment
################################################################################

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Source ROS2 environment to enable DDS middleware
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash

export LD_LIBRARY_PATH="$SCRIPT_DIR/agent_install/lib:$LD_LIBRARY_PATH"

"$SCRIPT_DIR/agent_install/bin/MicroXRCEAgent" "$@"
