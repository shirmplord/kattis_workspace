#include "ros/ros.h"
#include "simple_pub_sub/number_msgs.h"
#include <iostream>

//function called when ever a message is received
//data received is usually manipulated here
//in this case, the data is extracted and printed to the screen
void numberCallback (const simple_pub_sub::number_msgs::ConstPtr& msg)
{
    ROS_INFO("Message received %d %d",msg->num1, msg->num2);
    ROS_INFO("Sum of received numbers: %d", msg->num1+msg->num2);
}

int main(int argc, char** argv)
{
    //initialize a node with the name "simple_subscriber"
    //MANDATORY FOR ALL C++ NODES
    ros::init(argc,argv,"simple_subscriber");
    //creates a nodeHandle obj to communicate with ROS system
    ros::NodeHandle nh;
    //creates a Subscriber obj, subscribing to the topic /numbers
    //buffer size is the same as that of the publisher
    //the callback function is also called
    ros::Subscriber sub = nh.subscribe<simple_pub_sub::number_msgs>("/numbers",10,numberCallback);

    //the node will wait here at this loop until either
    //receives a new message
    //Ctrl+C is pressed
    ros::spin();
    return 0;
}






