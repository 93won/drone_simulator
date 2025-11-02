#!/bin/bash
# Warehouse 환경에서 depth camera 드론 실행

cd ~/drone_simulator/PX4-Autopilot || cd PX4-Autopilot

echo "========================================="
echo "Starting Warehouse Simulation"
echo "========================================="
echo ""
echo "Environment: Warehouse (Indoor SLAM)"
echo "Model: Iris with Depth Camera"
echo ""
echo "Press Ctrl+C to stop"
echo "========================================="

# Warehouse 월드를 명시적으로 지정
export PX4_SIM_MODEL=iris_depth_camera
make px4_sitl gazebo-classic PX4_GZ_WORLD=warehouse
