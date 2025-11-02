#!/usr/bin/env python3
"""
Simple Image Viewer - RViz 없이 OpenCV로 이미지 직접 보기
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class SimpleImageViewer(Node):
    def __init__(self):
        super().__init__('simple_image_viewer')
        
        self.bridge = CvBridge()
        
        # QoS profile for Gazebo
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # Subscribe to depth and RGB images
        self.depth_sub = self.create_subscription(
            Image,
            '/camera/depth/image_raw',
            self.depth_callback,
            qos_profile
        )
        
        self.rgb_sub = self.create_subscription(
            Image,
            '/camera/image_raw',
            self.rgb_callback,
            qos_profile
        )
        
        self.get_logger().info('=== Simple Image Viewer Started ===')
        self.get_logger().info('OpenCV windows will open automatically')
        self.get_logger().info('Press "q" in any window to quit')
        
    def depth_callback(self, msg):
        try:
            # Convert ROS Image to OpenCV format
            # Depth image is 32FC1 (32-bit float, 1 channel)
            depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='32FC1')
            
            # Normalize depth for visualization (0-10 meters range)
            depth_normalized = np.clip(depth_image, 0, 10) / 10.0
            depth_normalized = (depth_normalized * 255).astype(np.uint8)
            
            # Apply colormap for better visualization
            depth_colored = cv2.applyColorMap(depth_normalized, cv2.COLORMAP_JET)
            
            # Add text overlay
            cv2.putText(depth_colored, 'Depth Image (0-10m)', (10, 30),
                       cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
            
            # Display
            cv2.imshow('Depth Camera', depth_colored)
            cv2.waitKey(1)
            
        except Exception as e:
            self.get_logger().error(f'Error processing depth image: {e}')
    
    def rgb_callback(self, msg):
        try:
            # Convert ROS Image to OpenCV format
            rgb_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            
            # Add text overlay
            cv2.putText(rgb_image, 'RGB Camera', (10, 30),
                       cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            # Display
            cv2.imshow('RGB Camera', rgb_image)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                raise KeyboardInterrupt
                
        except KeyboardInterrupt:
            raise
        except Exception as e:
            self.get_logger().error(f'Error processing RGB image: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = SimpleImageViewer()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
