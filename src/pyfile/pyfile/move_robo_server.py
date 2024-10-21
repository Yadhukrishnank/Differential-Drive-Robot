#!/usr/bin/env python3
import rclpy
import time
import threading
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle, GoalResponse, CancelResponse
from my_robot_description.action import MoveRobo
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

class MoveRoboServerNode(Node):
    def __init__(self):
        super().__init__("move_robo_server")
        self.goal_lock_ = threading.Lock()
        self.goal_handle_: ServerGoalHandle = None
        self.current_position = Odometry()
        
        # Initialize Action Server
        self.move_robot_server_ = ActionServer(
            self,
            MoveRobo,
            "move_robo",
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
            callback_group=ReentrantCallbackGroup())
        
        # Subscribe to the robot's odometry data
        self.pose_subscriber_ = self.create_subscription(Odometry, "/odom", self.pose_callback, 10)
        
        # Publisher for velocity commands
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "cmd_vel", 10)
        
        self.get_logger().info("Action server has been started")

    def pose_callback(self, msg: Odometry):
        """Update the current robot position from odometry."""
        self.current_position = msg

    def goal_callback(self, goal_request: MoveRobo.Goal):
        """Handle a new goal request."""
        self.get_logger().info("Received a new goal")

        # Validate the goal
        if not (0.0 <= goal_request.x <= 5.0) or not (0.0 <= goal_request.z <= 5.0):
            self.get_logger().warn("Invalid goal, rejecting")
            return GoalResponse.REJECT

        # If a goal is already active, abort it
        if self.goal_handle_ is not None and self.goal_handle_.is_active:
            self.goal_handle_.abort()

        self.get_logger().info("Goal accepted")
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle: ServerGoalHandle):
        """Handle a goal cancellation request."""
        self.get_logger().info("Received a cancel request")
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle: ServerGoalHandle):
        """Execute the goal."""
        with self.goal_lock_:
            self.goal_handle_ = goal_handle

        goal_x = goal_handle.request.x
        goal_z = goal_handle.request.z

        cmd = Twist()  # Create a Twist message for controlling the robot
        result = MoveRobo.Result()  # Action result
        feedback = MoveRobo.Feedback()  # Action feedback

        self.get_logger().info("Executing goal")

        while rclpy.ok():
            # Get the current position from the updated odometry message
            current_x = self.current_position.pose.pose.position.x
            current_z = self.current_position.pose.pose.position.z

            # # Check if the goal has been achieved
            # if abs(goal_x - current_x) < 0.1 and abs(goal_z - current_z) < 0.1:
            #     self.get_logger().info("Goal reached!")
            #     result.position.x = current_x
            #     result.position.z = current_z
            #     result.message = "Goal reached"
            #     goal_handle.succeed()
            #     return result

            # Control the robot's movement
            if current_x > 7.0 or current_x < -1.0 or current_z < -3.5 or current_z > 3.0:
                cmd.linear.x = goal_x
                cmd.angular.z = goal_z
            else:
                cmd.linear.x = 1.0
                cmd.angular.z = 0.0

            # Publish the velocity command
            self.cmd_vel_publisher_.publish(cmd)

            # Log the current position
            self.get_logger().info(f"Current Position: ({current_x}, {current_z})")

            if goal_handle.is_cancel_requested:
                self.get_logger().info("Goal canceled, stopping robot")
                # Publish zero velocities to stop the robot
                cmd.linear.x = 0.0
                cmd.angular.z = 0.0
                self.cmd_vel_publisher_.publish(cmd)
                goal_handle.canceled()
                result.message = "Goal was canceled"
                return result

            # Provide feedback to the client
            feedback.current_position = current_x
            goal_handle.publish_feedback(feedback)

            time.sleep(1.0)  # Simulate a delay in processing

        # If something goes wrong, return the result with an error message
        result.x = current_x
        result.z = current_z
        
        result.message = "Execution failed or interrupted"
        return result


def main(args=None):
    """Main function to initialize and run the action server."""
    rclpy.init(args=args)
    node = MoveRoboServerNode()
    executor = MultiThreadedExecutor()
    rclpy.spin(node, executor)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
