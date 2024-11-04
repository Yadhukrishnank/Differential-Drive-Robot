// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_description:action/MoveRobo.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_DESCRIPTION__ACTION__DETAIL__MOVE_ROBO__BUILDER_HPP_
#define MY_ROBOT_DESCRIPTION__ACTION__DETAIL__MOVE_ROBO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_description/action/detail/move_robo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_Goal_z
{
public:
  explicit Init_MoveRobo_Goal_z(::my_robot_description::action::MoveRobo_Goal & msg)
  : msg_(msg)
  {}
  ::my_robot_description::action::MoveRobo_Goal z(::my_robot_description::action::MoveRobo_Goal::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_Goal msg_;
};

class Init_MoveRobo_Goal_x
{
public:
  Init_MoveRobo_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobo_Goal_z x(::my_robot_description::action::MoveRobo_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MoveRobo_Goal_z(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_Goal>()
{
  return my_robot_description::action::builder::Init_MoveRobo_Goal_x();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_Result_message
{
public:
  explicit Init_MoveRobo_Result_message(::my_robot_description::action::MoveRobo_Result & msg)
  : msg_(msg)
  {}
  ::my_robot_description::action::MoveRobo_Result message(::my_robot_description::action::MoveRobo_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_Result msg_;
};

class Init_MoveRobo_Result_z
{
public:
  explicit Init_MoveRobo_Result_z(::my_robot_description::action::MoveRobo_Result & msg)
  : msg_(msg)
  {}
  Init_MoveRobo_Result_message z(::my_robot_description::action::MoveRobo_Result::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_MoveRobo_Result_message(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_Result msg_;
};

class Init_MoveRobo_Result_x
{
public:
  Init_MoveRobo_Result_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobo_Result_z x(::my_robot_description::action::MoveRobo_Result::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MoveRobo_Result_z(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_Result>()
{
  return my_robot_description::action::builder::Init_MoveRobo_Result_x();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_Feedback_current_position
{
public:
  Init_MoveRobo_Feedback_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_description::action::MoveRobo_Feedback current_position(::my_robot_description::action::MoveRobo_Feedback::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_Feedback>()
{
  return my_robot_description::action::builder::Init_MoveRobo_Feedback_current_position();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_SendGoal_Request_goal
{
public:
  explicit Init_MoveRobo_SendGoal_Request_goal(::my_robot_description::action::MoveRobo_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_description::action::MoveRobo_SendGoal_Request goal(::my_robot_description::action::MoveRobo_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_SendGoal_Request msg_;
};

class Init_MoveRobo_SendGoal_Request_goal_id
{
public:
  Init_MoveRobo_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobo_SendGoal_Request_goal goal_id(::my_robot_description::action::MoveRobo_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveRobo_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_SendGoal_Request>()
{
  return my_robot_description::action::builder::Init_MoveRobo_SendGoal_Request_goal_id();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_SendGoal_Response_stamp
{
public:
  explicit Init_MoveRobo_SendGoal_Response_stamp(::my_robot_description::action::MoveRobo_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_description::action::MoveRobo_SendGoal_Response stamp(::my_robot_description::action::MoveRobo_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_SendGoal_Response msg_;
};

class Init_MoveRobo_SendGoal_Response_accepted
{
public:
  Init_MoveRobo_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobo_SendGoal_Response_stamp accepted(::my_robot_description::action::MoveRobo_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveRobo_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_SendGoal_Response>()
{
  return my_robot_description::action::builder::Init_MoveRobo_SendGoal_Response_accepted();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_GetResult_Request_goal_id
{
public:
  Init_MoveRobo_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_description::action::MoveRobo_GetResult_Request goal_id(::my_robot_description::action::MoveRobo_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_GetResult_Request>()
{
  return my_robot_description::action::builder::Init_MoveRobo_GetResult_Request_goal_id();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_GetResult_Response_result
{
public:
  explicit Init_MoveRobo_GetResult_Response_result(::my_robot_description::action::MoveRobo_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_description::action::MoveRobo_GetResult_Response result(::my_robot_description::action::MoveRobo_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_GetResult_Response msg_;
};

class Init_MoveRobo_GetResult_Response_status
{
public:
  Init_MoveRobo_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobo_GetResult_Response_result status(::my_robot_description::action::MoveRobo_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveRobo_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_GetResult_Response>()
{
  return my_robot_description::action::builder::Init_MoveRobo_GetResult_Response_status();
}

}  // namespace my_robot_description


namespace my_robot_description
{

namespace action
{

namespace builder
{

class Init_MoveRobo_FeedbackMessage_feedback
{
public:
  explicit Init_MoveRobo_FeedbackMessage_feedback(::my_robot_description::action::MoveRobo_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_description::action::MoveRobo_FeedbackMessage feedback(::my_robot_description::action::MoveRobo_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_FeedbackMessage msg_;
};

class Init_MoveRobo_FeedbackMessage_goal_id
{
public:
  Init_MoveRobo_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobo_FeedbackMessage_feedback goal_id(::my_robot_description::action::MoveRobo_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveRobo_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_description::action::MoveRobo_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_description::action::MoveRobo_FeedbackMessage>()
{
  return my_robot_description::action::builder::Init_MoveRobo_FeedbackMessage_goal_id();
}

}  // namespace my_robot_description

#endif  // MY_ROBOT_DESCRIPTION__ACTION__DETAIL__MOVE_ROBO__BUILDER_HPP_
