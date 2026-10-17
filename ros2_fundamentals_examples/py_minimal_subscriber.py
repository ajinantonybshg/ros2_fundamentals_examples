#! /usr/bin/env python3


"""
Description:
This ROS 2 node subscribes to "Hello World" messages.

----------
Publishing Topics:
None

----------
Subscribing Topics:
The channel containing the "Hello World" messagges.
/py_example_topic - std_msgs/String

----------
Author: Ajin Antony
Date: October 16, 2026

"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPYSubscriber(Node):
  def __init__(self):
    super().__init__('minimal_py_subscriber')

    self.subscriber_1 = self.create_subscription(
      String,
      '/py_example_topic',
      self.listener_callback,
      10)

  def listener_callback(self, msg):
    self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
  rclpy.init(args=args)

  minimal_py_subscriber = MinimalPYSubscriber()

  rclpy.spin(minimal_py_subscriber)

  minimal_py_subscriber.destroy_node()
  rclpy.shutdown()

if __name__ == "__main__":
  main()