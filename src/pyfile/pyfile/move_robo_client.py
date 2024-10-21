import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus
from my_robot_description.action import MoveRobo
from example_interfaces.msg import Empty

class MoveRoboClientNode(Node):
    def __init__(self):
        super().__init__("move_robo_client")
        self.goal_handle_ = None
        self.move_robot_client_ = ActionClient(self, MoveRobo, "move_robo")
        self.cancel_subscriber = self.create_subscription(
            Empty, "cancel_move", self.callback_cancel_move, 10)

    def send_goal(self, x, z):
        self.move_robot_client_.wait_for_server()

        goal = MoveRobo.Goal()
        goal.x =x
        goal.z= z

        self.get_logger(). \
            info("Send goal with position " + str(x) + " and velocity " + str(z))
        self.move_robot_client_. \
            send_goal_async(goal, feedback_callback=self.goal_feedback_callback). \
            add_done_callback(self.goal_response_callback)
 
    def goal_response_callback(self, future):
        self.goal_handle_: ClientGoalHandle = future.result()
        if self.goal_handle_.accepted:
            self.get_logger().info("Goal got accepted")
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)
        else:
            self.get_logger().info("Goal got rejected")

    def goal_result_callback(self, future):
        status = future.result().status
        result = future.result().result
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Succeeded")
        elif status == GoalStatus.STATUS_ABORTED:
            self.get_logger().error("Aborted")
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Canceled")
        self.get_logger().info("Position: " + str(result.position))
        self.get_logger().info("Message: " + str(result.message))

    def goal_feedback_callback(self, feedback_msg):
        position = feedback_msg.feedback.current_position
        self.get_logger().info("Feedback position: " + str(position))

    def callback_cancel_move(self, msg):
        self.cancel_goal()

    def cancel_goal(self):
        if self.goal_handle_ is not None:
            self.get_logger().info("Send a cancel request")
            self.goal_handle_.cancel_goal_async()

def main(args=None):
    rclpy.init(args=args)
    node = MoveRoboClientNode()
    node.send_goal(0.50, 1.0)
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()