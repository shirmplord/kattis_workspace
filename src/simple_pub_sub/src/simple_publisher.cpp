#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>


int main(int argc, char** argv)
{
    //initialize a node with the name "simple_publisher"
    //MANDATORY FOR C++ NODES
    ros::init(argc, argv, "simple_publisher");
    //creates a nodeHandle obj, which is used to communicate with ROS system
    ros::NodeHandle nh;
    //creates a publisher obj, publishing the topic named /numbers
    //the numbers is the number of message needs to be put in a buffer before sending
    //the higher the transfer rate, the higher that number must be
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("/numbers", 10);
    //set the data sending frequency
    ros::Rate loop_rate(10);
    int count = 0;
    //loops until Ctrl+C is pressed
    while (ros::ok()) 
    {
        //msg is the message to be sent
        std_msgs::Int32 msg;
        //load the msg with data
        msg.data = count++;
        //print to the console for debug
        ROS_INFO("Sending messages %d",msg.data);
        //publishing the message
        pub.publish(msg);
        //read and update all ROS topics
        //the node will not be published without spin() or spinOnce()
        ros::spinOnce();
        //provide the delay necessary to send at 10Hz
        loop_rate.sleep();
    }
    return 0;
}





