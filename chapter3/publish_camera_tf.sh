#!/bin/bash
################################################################################
# @file      publish_camera_tf.sh
# @brief     Static TF publisher for camera frame
# @author    Eugene (93won)
# @date      2025-11-09
# @copyright Copyright (c) 2025 Eugene. All rights reserved.
#
# @par License
# This project is released under the MIT License.
#
# @par Description
# Publishes static transform from base_link to camera_link
# Required for RViz to display camera images
################################################################################

source /opt/ros/galactic/setup.bash

echo "Publishing static TF: base_link -> camera_link"
echo "This allows RViz to display camera images"
echo "Press Ctrl+C to stop"

ros2 run tf2_ros static_transform_publisher \
    0.1 0 0.035 0 0 0 \
    base_link camera_link
