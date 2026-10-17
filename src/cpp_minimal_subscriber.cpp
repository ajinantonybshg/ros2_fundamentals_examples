/**
 * @file cpp_minimal_subscriber.cpp
 * @author Ajin Antony
 * @brief Minimal C++  subscriber example for ROS 2
 * @version 0.1
 * @date October 17, 2026
 * 
 * @copyright 
 * 
 * --------
 * Subscription Topics
 * String message
 * /cpp_example_topic - std_msgs/String
 * ---------
 * Publishing Topics:
 * None
 * 
 */

#include "rclcpp/rclcpp.hpp" // ROS 2 c++ client library
#include "std_msgs/msg/string.hpp" // Standard message type for strings

using std::placeholders::_1; // Placeholder for callback function

class MinimalCppSubscriber : public rclcpp::Node
{

public:
  MinimalCppSubscriber() : Node("minimal_cpp_subscriber")
  {
    subscriber_ = this->create_subscription<std_msgs::msg::String>(
      "/cpp_example_topic", 10, std::bind(&MinimalCppSubscriber::topicCallback, this, _1));

    RCLCPP_INFO(get_logger(), "Subscribed to /cpp_example_topic");
  }

  void topicCallback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(get_logger(), "I heard: '%s'", msg->data.c_str());
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_; // The subscriber object
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto minimal_cpp_subscriber_node = std::make_shared<MinimalCppSubscriber>();
  rclcpp::spin(minimal_cpp_subscriber_node);

  rclcpp::shutdown();

  return 0;
}