#!/bin/bash
# Static TF publisher for camera frame
# This publishes the camera_link transform so RViz can display images

source /opt/ros/galactic/setup.bash

echo "Publishing static TF: base_link -> camera_link"
echo "This allows RViz to display camera images"
echo "Press Ctrl+C to stop"

ros2 run tf2_ros static_transform_publisher \
    0.1 0 0.035 0 0 0 \
    base_link camera_link
