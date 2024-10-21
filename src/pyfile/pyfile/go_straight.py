#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class StraightMotion(Node):
    def __init__(self):
        super().__init__("straight")
        self.cmd_vel_publisher=self.create_publisher(Twist,"cmd_vel",10)
        self.timer_=self.create_timer(0.5,self.velocity_cmd)
    def velocity_cmd(self):
        msg=Twist()
        msg.angular.z =0.0
        msg.linear.x=2.0
        msg.linear.y=1.0
        self.cmd_vel_publisher.publish(msg)
        

def main(args=None):
    rclpy.init(args=args)
    node= StraightMotion()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__=='__main__':
    main()