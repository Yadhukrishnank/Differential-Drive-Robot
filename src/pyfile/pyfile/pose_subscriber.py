#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class PoseSubscriber(Node):
    def __init__(self):
        super().__init__("pose_subscriber")
        self.pose_subscriber_=self.create_subscription(
            Odometry,"/odom",self.pose_callback,10)

        
    
    def pose_callback(self,msg:Odometry):
        x=msg.pose.pose.position.x
        y=msg.pose.pose.position.y
        self.get_logger().info("("+ str(x) +"," +str(y)+ ") ")
        

def main(args=None):
    rclpy.init(args=args)
    node= PoseSubscriber()
    rclpy.spin(node)
    rclpy.shutdown() 

if __name__=='__main__':
    main()