#!/usr/bin/env python3
"""
@file      offboard_control.py
@brief     Offboard Control Node for PX4 with smooth landing
@author    Eugene (93won)
@date      2025-11-09
@copyright Copyright (c) 2025 Eugene. All rights reserved.

@par License
This project is released under the MIT License.

@par Description
Offboard Control Node for PX4
Chapter 2 - ROS2-PX4 Integration Example

Features:
1. Switch to Offboard mode
2. Navigate to specific positions
3. Execute landing command with smooth descent
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

from px4_msgs.msg import OffboardControlMode, TrajectorySetpoint, VehicleCommand, VehicleLocalPosition, VehicleStatus


class OffboardControl(Node):
    """PX4 Offboard Control Node"""

    def __init__(self):
        super().__init__('offboard_control')
        
        # QoS settings for PX4 communication
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )

        # Publishers (send commands to PX4)
        self.offboard_control_mode_publisher = self.create_publisher(
            OffboardControlMode, '/fmu/in/offboard_control_mode', qos_profile)
        self.trajectory_setpoint_publisher = self.create_publisher(
            TrajectorySetpoint, '/fmu/in/trajectory_setpoint', qos_profile)
        self.vehicle_command_publisher = self.create_publisher(
            VehicleCommand, '/fmu/in/vehicle_command', qos_profile)

        # Subscribers (receive status from PX4)
        self.vehicle_local_position_subscriber = self.create_subscription(
            VehicleLocalPosition, '/fmu/out/vehicle_local_position_v1', 
            self.vehicle_local_position_callback, qos_profile)
        self.vehicle_status_subscriber = self.create_subscription(
            VehicleStatus, '/fmu/out/vehicle_status_v1',
            self.vehicle_status_callback, qos_profile)

        # State variables
        self.offboard_setpoint_counter = 0
        self.vehicle_local_position = VehicleLocalPosition()
        self.vehicle_status = VehicleStatus()
        self.takeoff_height = -5.0  # NED coordinate system: negative z is up (5m altitude)
        self.is_armed = False
        
        # Timer (20Hz = 50ms)
        self.timer = self.create_timer(0.05, self.timer_callback)
        
        self.get_logger().info('=== Offboard Control Node Started ===')
        self.get_logger().info('Sending setpoints before engaging Offboard mode...')

    def vehicle_local_position_callback(self, vehicle_local_position):
        """Receive position information"""
        self.vehicle_local_position = vehicle_local_position
        if self.offboard_setpoint_counter % 100 == 0:  # Log every 5 seconds
            self.get_logger().info(f'[CALLBACK] Position received: x={vehicle_local_position.x:.2f}, z={vehicle_local_position.z:.2f}')

    def vehicle_status_callback(self, vehicle_status):
        """Receive status information"""
        # Log first callback
        if self.offboard_setpoint_counter == 0:
            self.get_logger().info(f'[CALLBACK] First vehicle_status received! Nav={vehicle_status.nav_state}, Arm={vehicle_status.arming_state}')
        
        old_nav_state = self.vehicle_status.nav_state
        self.vehicle_status = vehicle_status
        
        # Detect nav state changes
        if old_nav_state != vehicle_status.nav_state:
            self.get_logger().info(f'>> Nav state changed: {old_nav_state} -> {vehicle_status.nav_state}')
            if vehicle_status.nav_state == VehicleStatus.NAVIGATION_STATE_OFFBOARD:
                self.get_logger().info('>> OFFBOARD MODE ACTIVE!')
        
        # Track arming state
        if vehicle_status.arming_state == 2 and not self.is_armed:
            self.is_armed = True
            self.get_logger().info('>> Vehicle ARMED successfully!')
        elif vehicle_status.arming_state != 2 and self.is_armed:
            self.is_armed = False
            self.get_logger().warn('>> Vehicle DISARMED!')

    def arm(self):
        """Send arm command"""
        self.publish_vehicle_command(
            VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, param1=1.0)
        self.get_logger().info('Arm command sent')

    def disarm(self):
        """Send disarm command"""
        self.publish_vehicle_command(
            VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, param1=0.0)
        self.get_logger().info('Disarm command sent')

    def engage_offboard_mode(self):
        """Switch to Offboard mode"""
        self.publish_vehicle_command(
            VehicleCommand.VEHICLE_CMD_DO_SET_MODE, param1=1.0, param2=6.0)
        self.get_logger().info("Switching to Offboard mode")

    def land(self):
        """Send landing command"""
        self.publish_vehicle_command(VehicleCommand.VEHICLE_CMD_NAV_LAND)
        self.get_logger().info("Landing command sent")

    def publish_offboard_control_mode(self):
        """Publish Offboard Control Mode (position control mode)"""
        msg = OffboardControlMode()
        msg.position = True
        msg.velocity = False
        msg.acceleration = False
        msg.attitude = False
        msg.body_rate = False
        msg.timestamp = 0  # PX4 automatically sets timestamp
        self.offboard_control_mode_publisher.publish(msg)

    def publish_position_setpoint(self, x: float, y: float, z: float, yaw: float = 0.0):
        """Publish position setpoint (NED coordinate system)"""
        msg = TrajectorySetpoint()
        msg.position = [x, y, z]
        msg.yaw = yaw  # (rad)
        msg.timestamp = 0  # PX4 automatically sets timestamp
        self.trajectory_setpoint_publisher.publish(msg)

    def publish_vehicle_command(self, command, **params):
        """Publish Vehicle Command"""
        msg = VehicleCommand()
        msg.command = command
        msg.param1 = params.get("param1", 0.0)
        msg.param2 = params.get("param2", 0.0)
        msg.param3 = params.get("param3", 0.0)
        msg.param4 = params.get("param4", 0.0)
        msg.param5 = params.get("param5", 0.0)
        msg.param6 = params.get("param6", 0.0)
        msg.param7 = params.get("param7", 0.0)
        msg.target_system = 1
        msg.target_component = 1
        msg.source_system = 1
        msg.source_component = 1
        msg.from_external = True
        msg.timestamp = 0  # PX4 automatically sets timestamp
        self.vehicle_command_publisher.publish(msg)

    def timer_callback(self):
        """Main control loop (20Hz)"""
        
        # Continuously publish messages to maintain Offboard mode
        self.publish_offboard_control_mode()

        # Send setpoints first for 2 seconds (prepare for Offboard mode)
        if self.offboard_setpoint_counter < 40:
            self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)  # Send takeoff target from the start
            if self.offboard_setpoint_counter == 0:
                self.get_logger().info(f'>> Sending initial takeoff setpoints: (0, 0, {self.takeoff_height})...')
            if self.offboard_setpoint_counter % 20 == 0:
                self.get_logger().info(f'>> [DEBUG] Counter: {self.offboard_setpoint_counter}, Nav state: {self.vehicle_status.nav_state}, Arming: {self.vehicle_status.arming_state}')
        
        # After 2 seconds, arm first (arming required before Offboard transition)
        elif self.offboard_setpoint_counter == 40:
            self.arm()
            self.get_logger().info(f'>> [DEBUG] Arm command sent first. Nav state: {self.vehicle_status.nav_state}, Arming state: {self.vehicle_status.arming_state}')
            self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)  # Continue sending
        
        # Switch to Offboard mode 0.25s after arming (quickly!)
        elif self.offboard_setpoint_counter == 45:
            self.engage_offboard_mode()
            self.get_logger().info(f'>> [DEBUG] Now switching to Offboard mode. Current nav_state: {self.vehicle_status.nav_state}, Arming: {self.vehicle_status.arming_state}')
            self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)  # Continue sending
        
        # Continue sending setpoints between Arm and Offboard
        elif 40 < self.offboard_setpoint_counter < 45:
            self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)

        # Control sequence (after entering Offboard mode)
        if self.vehicle_status.nav_state == VehicleStatus.NAVIGATION_STATE_OFFBOARD:
            
            # Start takeoff setpoint immediately after Offboard entry (prevent auto disarm)
            if self.offboard_setpoint_counter < 150:
                self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)  # Takeoff target
                if self.offboard_setpoint_counter == 50:
                    self.get_logger().info(f'>> [OFFBOARD] Starting takeoff to {-self.takeoff_height}m...')
                if self.offboard_setpoint_counter % 20 == 0:
                    self.get_logger().info(f'>> [OFFBOARD] Counter: {self.offboard_setpoint_counter}, Target: (0, 0, {self.takeoff_height})')
            
            elif self.offboard_setpoint_counter < 300:  # 7.5~15s: Hold altitude
                self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)
                if self.offboard_setpoint_counter == 150:
                    self.get_logger().info(f'>> [OFFBOARD] Holding at {-self.takeoff_height}m...')
            
            elif self.offboard_setpoint_counter < 500:  # 15~25s: Move forward 5m
                self.publish_position_setpoint(5.0, 0.0, self.takeoff_height)
                if self.offboard_setpoint_counter == 300:
                    self.get_logger().info('>> [OFFBOARD] Moving forward 5m...')
            
            elif self.offboard_setpoint_counter < 700:  # 25~35s: Move left 5m
                self.publish_position_setpoint(5.0, 5.0, self.takeoff_height)
                if self.offboard_setpoint_counter == 500:
                    self.get_logger().info('>> [OFFBOARD] Moving left 5m...')
            
            elif self.offboard_setpoint_counter < 900:  # 35~45s: Return to origin
                self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)
                if self.offboard_setpoint_counter == 700:
                    self.get_logger().info('>> [OFFBOARD] Returning to home...')
            
            # 45s~65s: Gradual descent (smooth landing) - descend slowly over 20 seconds
            elif self.offboard_setpoint_counter < 1300:
                # Descend from 5m to 0.15m over 20 seconds (0.24m/s - very slow)
                progress = (self.offboard_setpoint_counter - 900) / 400.0  # 0.0 ~ 1.0
                # Two-stage descent: first 10s fast (5m->1m), last 10s slow (1m->0.15m)
                if progress < 0.5:
                    # First 10 seconds: 5m -> 1m (0.4m/s)
                    current_altitude = -5.0 + (progress * 2.0) * 4.0  # -5.0 -> -1.0
                else:
                    # Last 10 seconds: 1m -> 0.15m (0.085m/s)
                    current_altitude = -1.0 + ((progress - 0.5) * 2.0) * 0.85  # -1.0 -> -0.15
                
                self.publish_position_setpoint(0.0, 0.0, current_altitude)
                if self.offboard_setpoint_counter == 900:
                    self.get_logger().info('>> [OFFBOARD] Starting smooth descent (20 seconds)...')
                if self.offboard_setpoint_counter % 40 == 0:
                    self.get_logger().info(f'>> [DESCENT] Target altitude: {-current_altitude:.2f}m')
            
            elif self.offboard_setpoint_counter == 1300:  # 65s: Final land command at 0.15m altitude
                self.land()
                self.get_logger().info('>> [OFFBOARD] Final landing command (altitude ~0.15m)...')
                self.get_logger().info('=== Mission Complete ===')
            
            # Print current position every 2 seconds
            if self.offboard_setpoint_counter % 40 == 0:
                self.get_logger().info(
                    f'[OFFBOARD] Position: x={self.vehicle_local_position.x:.2f}, '
                    f'y={self.vehicle_local_position.y:.2f}, '
                    f'z={self.vehicle_local_position.z:.2f}')
        else:
            # Continue sending setpoints even when not in Offboard mode (prepare for Offboard entry)
            if self.offboard_setpoint_counter >= 40:
                self.publish_position_setpoint(0.0, 0.0, self.takeoff_height)
                if self.offboard_setpoint_counter % 40 == 0:
                    self.get_logger().warn(
                        f'[NOT OFFBOARD] Counter: {self.offboard_setpoint_counter}, '
                        f'Nav state: {self.vehicle_status.nav_state}, '
                        f'Expected: {VehicleStatus.NAVIGATION_STATE_OFFBOARD}, '
                        f'Sending setpoint: (0, 0, {self.takeoff_height})')

        self.offboard_setpoint_counter += 1


def main(args=None):
    print('Starting offboard control node...')
    rclpy.init(args=args)
    offboard_control = OffboardControl()
    rclpy.spin(offboard_control)
    offboard_control.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
