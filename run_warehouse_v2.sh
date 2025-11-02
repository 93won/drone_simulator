#!/bin/bash
# Warehouse 환경 실행 (확실한 방법)

cd ~/drone_simulator/PX4-Autopilot || cd PX4-Autopilot

echo "========================================="
echo "Starting Warehouse Simulation"
echo "========================================="

# 방법 1: 직접 모델명에 월드 지정
make px4_sitl gazebo-classic_iris_depth_camera__warehouse

# 만약 위 방법이 안되면 아래 방법 사용:
# GAZEBO_WORLD=warehouse.world make px4_sitl gazebo-classic_iris_depth_camera
