#!/usr/bin/env python3
"""
Depth Camera Viewer Node
Subscribes to depth camera topics with correct QoS settings and republishes
for RViz visualization.
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import Image, CameraInfo, PointCloud2

class DepthCameraViewer(Node):
    def __init__(self):
        super().__init__('depth_camera_viewer')
        
        # QoS profile matching Gazebo's settings (BEST_EFFORT)
        qos_profile_sensor = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # QoS profile for republishing (RELIABLE for RViz)
        qos_profile_reliable = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # Subscribers (BEST_EFFORT to match Gazebo)
        self.depth_image_sub = self.create_subscription(
            Image,
            '/camera/depth/image_raw',
            self.depth_image_callback,
            qos_profile_sensor
        )
        
        self.rgb_image_sub = self.create_subscription(
            Image,
            '/camera/image_raw',
            self.rgb_image_callback,
            qos_profile_sensor
        )
        
        self.pointcloud_sub = self.create_subscription(
            PointCloud2,
            '/camera/points',
            self.pointcloud_callback,
            qos_profile_sensor
        )
        
        self.depth_info_sub = self.create_subscription(
            CameraInfo,
            '/camera/depth/camera_info',
            self.depth_info_callback,
            qos_profile_sensor
        )
        
        # Publishers (RELIABLE for RViz compatibility)
        self.depth_image_pub = self.create_publisher(
            Image,
            '/camera/depth/image_raw/reliable',
            qos_profile_reliable
        )
        
        self.rgb_image_pub = self.create_publisher(
            Image,
            '/camera/image_raw/reliable',
            qos_profile_reliable
        )
        
        self.pointcloud_pub = self.create_publisher(
            PointCloud2,
            '/camera/points/reliable',
            qos_profile_reliable
        )
        
        self.depth_info_pub = self.create_publisher(
            CameraInfo,
            '/camera/depth/camera_info/reliable',
            qos_profile_reliable
        )
        
        # Statistics
        self.depth_count = 0
        self.rgb_count = 0
        self.pc_count = 0
        
        # Timer for status reporting
        self.create_timer(2.0, self.report_status)
        
        self.get_logger().info('=== Depth Camera Viewer Node Started ===')
        self.get_logger().info('Subscribing to Gazebo topics with BEST_EFFORT QoS')
        self.get_logger().info('Republishing with RELIABLE QoS for RViz')
        self.get_logger().info('')
        self.get_logger().info('Available topics for RViz:')
        self.get_logger().info('  - /camera/depth/image_raw/reliable')
        self.get_logger().info('  - /camera/image_raw/reliable')
        self.get_logger().info('  - /camera/points/reliable')
    
    def depth_image_callback(self, msg):
        """Republish depth image with RELIABLE QoS"""
        self.depth_image_pub.publish(msg)
        self.depth_count += 1
    
    def rgb_image_callback(self, msg):
        """Republish RGB image with RELIABLE QoS"""
        self.rgb_image_pub.publish(msg)
        self.rgb_count += 1
    
    def pointcloud_callback(self, msg):
        """Republish point cloud with RELIABLE QoS"""
        self.pointcloud_pub.publish(msg)
        self.pc_count += 1
    
    def depth_info_callback(self, msg):
        """Republish camera info with RELIABLE QoS"""
        self.depth_info_pub.publish(msg)
    
    def report_status(self):
        """Report message counts"""
        if self.depth_count > 0 or self.rgb_count > 0 or self.pc_count > 0:
            self.get_logger().info(
                f'Messages received - Depth: {self.depth_count}, '
                f'RGB: {self.rgb_count}, PointCloud: {self.pc_count}'
            )
            # Reset counters
            self.depth_count = 0
            self.rgb_count = 0
            self.pc_count = 0

def main(args=None):
    rclpy.init(args=args)
    node = DepthCameraViewer()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    
    node.get_logger().info('Shutting down Depth Camera Viewer')
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
