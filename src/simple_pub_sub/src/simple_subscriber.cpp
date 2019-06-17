#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

//function called when ever a message is received
//data received is usually manipulated here
//in this case, the data is extracted and printed to the screen
void numberCallback (const std_msgs::Int32::ConstPtr& msg)
{
    ROS_INFO("Message received %d",msg->data);
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
    ros::Subscriber sub = nh.subscribe<std_msgs::Int32>("/numbers",10,numberCallback);

    //the node will wait here at this loop until either
    //receives a new message
    //Ctrl+C is pressed
    ros::spin();
    return 0;
}






