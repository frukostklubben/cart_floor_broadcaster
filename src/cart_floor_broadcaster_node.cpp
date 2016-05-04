#include <ros/ros.h>
#include "tf/transform_broadcaster.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv){
  ros::init(argc, argv, "cart_floor_broadcaster");
  
  ros::NodeHandle node;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);
  std::cout << "*******************************************************************" << std::endl;
  ROS_INFO("Broadcasting frame \"/floor\", which is offset -0.8 in Z from \"/camera_link\"");
  std::cout << "*******************************************************************" << std::endl;

  while (node.ok()){
    transform.setOrigin( tf::Vector3(0.0, 0.0, -0.8) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "camera_link", "floor"));
    rate.sleep();
  }
  return 0;
};