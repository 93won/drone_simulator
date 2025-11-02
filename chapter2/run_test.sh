#!/bin/bash

##############################################################################
# Chapter 2: Quick Test Script
# This script helps you test ROS2-PX4 connection
##############################################################################

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

print_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

print_step() {
    echo -e "${BLUE}[STEP]${NC} $1"
}

echo "=========================================="
echo "Chapter 2: ROS2-PX4 Connection Test"
echo "=========================================="
echo ""

# Get script directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Check if installations are complete
if [ ! -f "$SCRIPT_DIR/agent_install/bin/MicroXRCEAgent" ]; then
    echo "❌ MicroXRCEAgent not found. Please run install_chapter2.sh first."
    exit 1
fi

if [ ! -d "$HOME/ros2_ws" ]; then
    echo "❌ ROS2 workspace not found. Please run install_chapter2.sh first."
    exit 1
fi

echo "✅ Prerequisites checked"
echo ""

# Source workspace
print_info "Sourcing ROS2 workspace..."
source ~/ros2_ws/install/setup.bash

echo ""
echo "=========================================="
echo "📋 Test Instructions"
echo "=========================================="
echo ""
echo "You need to open 4 terminals to test the full system."
echo "This script will help you know what to run in each terminal."
echo ""

read -p "Press Enter to see Terminal 1 instructions..."
echo ""
print_step "Terminal 1: Start PX4 Simulation"
echo "--------------------"
echo "cd ~/PX4-Autopilot"
echo "make px4_sitl gazebo-classic"
echo ""
echo "Wait until you see 'pxh>' prompt and Gazebo window opens."
echo ""

read -p "Press Enter to see Terminal 2 instructions..."
echo ""
print_step "Terminal 2: Start Micro XRCE-DDS Agent"
echo "--------------------"
echo "cd $SCRIPT_DIR"
echo "./run_agent.sh udp4 -p 8888"
echo ""
echo "You should see:"
echo "  [INFO] Starting Micro XRCE-DDS Agent..."
echo "  [INFO] UDP Transport listening on port 8888"
echo ""
echo "Wait until PX4 connects (you'll see connection messages)."
echo ""

read -p "Press Enter to see Terminal 3 instructions..."
echo ""
print_step "Terminal 3: Check ROS2 Topics"
echo "--------------------"
echo "source ~/ros2_ws/install/setup.bash"
echo "ros2 topic list"
echo ""
echo "You should see many /fmu/ topics like:"
echo "  /fmu/out/vehicle_status"
echo "  /fmu/out/vehicle_local_position"
echo "  /fmu/out/battery_status"
echo "  ... (100+ topics)"
echo ""
echo "To monitor drone position:"
echo "ros2 topic echo /fmu/out/vehicle_local_position"
echo ""

read -p "Press Enter to see Terminal 4 instructions..."
echo ""
print_step "Terminal 4: Fly the Drone (PX4 Console)"
echo "--------------------"
echo "In Terminal 1's PX4 console (pxh> prompt), type:"
echo ""
echo "commander arm"
echo "commander takeoff"
echo ""
echo "Watch Terminal 3 show real-time position updates!"
echo ""
echo "To land:"
echo "commander land"
echo ""

echo ""
echo "=========================================="
echo "🎯 Quick Verification"
echo "=========================================="
echo ""
echo "If you just want to quickly check if everything works,"
echo "run this in a separate terminal AFTER starting PX4 and Agent:"
echo ""
echo "source ~/ros2_ws/install/setup.bash"
echo "ros2 topic list | grep fmu"
echo ""
echo "If you see /fmu/ topics, everything is working! 🎉"
echo ""
echo "=========================================="
echo ""

# Option to check topics now
echo ""
read -p "Do you want to check ROS2 topics now? (y/n) " -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]; then
    print_info "Checking ROS2 topics..."
    echo ""
    
    TOPICS=$(ros2 topic list 2>/dev/null | grep fmu)
    
    if [ -z "$TOPICS" ]; then
        echo "❌ No /fmu/ topics found."
        echo ""
        echo "This means either:"
        echo "  1. PX4 simulation is not running"
        echo "  2. MicroXRCEAgent is not running"
        echo "  3. They are not connected"
        echo ""
        echo "Please start PX4 and Agent first (see instructions above)."
    else
        echo "✅ Found PX4 topics! Connection is working!"
        echo ""
        echo "Available topics:"
        echo "$TOPICS"
        echo ""
        echo "🎉 ROS2-PX4 bridge is working correctly!"
    fi
fi

echo ""
print_info "For detailed examples, see chapter2/README.md"
echo ""

