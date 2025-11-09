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

cd ~/source4/drone_simulator/PX4-Autopilot || cd /home/eugene/source4/drone_simulator/PX4-Autopilot

echo "========================================="
echo "Starting Depth Camera in Warehouse World"
echo "========================================="
echo ""
echo "Correct syntax: make px4_sitl gazebo-classic_model__world"
echo "Use double underscore (__)!"
echo ""

# Correct syntax: model__world (double underscore!)
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
