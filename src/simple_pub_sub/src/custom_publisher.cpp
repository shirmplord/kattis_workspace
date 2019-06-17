#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "simple_pub_sub/number_msgs.h"
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
    ros::Publisher pub = nh.advertise<simple_pub_sub::number_msgs>("/numbers", 10);
    //set the data sending frequency
    ros::Rate loop_rate(10);
    int count = 0;
    //loops until Ctrl+C is pressed
    while (ros::ok()) 
    {
        //msg is the message to be sent
        simple_pub_sub::number_msgs msg;
        //load the msg with data
        msg.num1 = count;
        msg.num2 = count;
        //print to the console for debug
        ROS_INFO("Sending messages %d %d",msg.num1, msg.num2);
        //publishing the message
        pub.publish(msg);
        //read and update all ROS topics
        //the node will not be published without spin() or spinOnce()
        count++;
        ros::spinOnce();
        //provide the delay necessary to send at 10Hz
        loop_rate.sleep();
    }
    return 0;
}





