#!/bin/bash
################################################################################
# @file      run_depth_warehouse.sh
# @brief     Launch PX4 simulation with depth camera in warehouse environment
# @author    Eugene (93won)
# @date      2025-11-09
# @copyright Copyright (c) 2025 Eugene. All rights reserved.
#
# @par License
# This project is released under the MIT License.
#
# @par Description
# Runs iris drone with depth camera in warehouse world
################################################################################

cd ~/drone_simulator/PX4-Autopilot || { echo "Error: PX4-Autopilot directory not found"; exit 1; }

# Source ROS2 environment for Gazebo plugins
if [ -f /opt/ros/humble/setup.bash ]; then
    source /opt/ros/humble/setup.bash
elif [ -f /opt/ros/galactic/setup.bash ]; then
    source /opt/ros/galactic/setup.bash
fi

# Add ROS2 Gazebo plugin path
export GAZEBO_PLUGIN_PATH=/opt/ros/humble/lib:$GAZEBO_PLUGIN_PATH

echo "========================================="
echo "Starting Depth Camera in Warehouse World"
echo "========================================="
echo ""
echo "Correct syntax: make px4_sitl gazebo-classic_model__world"
echo "Use double underscore (__)!"
echo ""

# Correct syntax: model__world (double underscore!)
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
