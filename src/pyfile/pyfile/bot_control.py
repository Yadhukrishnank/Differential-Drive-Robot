#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

class BotControl(Node):
    def __init__(self):
        super().__init__("bot_control")
        self.pose_subscriber_=self.create_subscription(Odometry,"/odom",self.pose_callback,10)
        self.cmd_vel_publisher_=self.create_publisher(Twist,"cmd_vel",10)


    def pose_callback(self,msg:Odometry):
        cmd=Twist()
        x=msg.pose.pose.position.x
        y=msg.pose.pose.position.y
        z=msg.pose.pose.position.z
        if x > 7.0 or x < -1.0 or y < -3.5 or y > 3.0 :
            cmd.linear.x =1.1
            cmd.angular.z =-1.1
        else:
            cmd.linear.x=3.0
            cmd.linear.z=0.0
            cmd.angular.z =0.0

        self.cmd_vel_publisher_.publish(cmd)

        self.get_logger().info("("+ str(x) +"," +str(y)+ ") ")
        

def main(args=None):
    rclpy.init(args=args)
    node= BotControl()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__=='__main__':
    main()