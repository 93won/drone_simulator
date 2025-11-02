#!/bin/bash
# Depth Camera로 Warehouse 환경 실행

cd ~/source4/drone_simulator/PX4-Autopilot || cd /home/eugene/source4/drone_simulator/PX4-Autopilot

echo "========================================="
echo "Starting Depth Camera in Warehouse World"
echo "========================================="
echo ""
echo "올바른 문법: make px4_sitl gazebo-classic_모델명__world명"
echo "언더스코어 2개 (__) 사용!"
echo ""

# 올바른 문법: 모델명__world명 (언더스코어 2개!)
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
