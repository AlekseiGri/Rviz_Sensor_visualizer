#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "visualization_msgs/Marker.h"

float temp = 0.0;
float pres = 0.0;


void tempCallback (const std_msgs::Float32::ConstPtr& msg)
{
    ROS_INFO("Get temp: [%.2f] C ", msg->data);
    temp = msg->data;

}

void presCallback (const std_msgs::Float32::ConstPtr& msg)
{
    ROS_INFO("Get pressure: [%.2f] mmHg ", msg->data);
    pres = msg->data;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rviz_marker_publisher");

    ros::NodeHandle n;

    ros::Subscriber temp_sub = n.subscribe("/sensor/temperature", 10, tempCallback);
    ros::Subscriber pre_sub = n.subscribe("/sensor/pressure", 10, presCallback);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("/visualization_marker",1);

    int rate;
    n.getParam("publish_rate", rate);
    ros::Rate loop_rate(rate);

    while (ros::ok())
    {

        ros::spinOnce();

        visualization_msgs::Marker marker;
        marker.header.frame_id = "world";
        marker.header.stamp = ros::Time::now();
        marker.ns = "sensor_data";
        marker.id = 0;
        marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
        marker.action = visualization_msgs::Marker::ADD;

        marker.pose.position.x = 0;
        marker.pose.position.y = 0;
        marker.pose.position.z = 1;
        marker.scale.z = 0.4;

        marker.color.r = 1.0;
        marker.color.g = 1.0;
        marker.color.b = 1.0;
        marker.color.a = 1.0;

        std::stringstream ss;
        ss << "Temp: " << temp << "°C\n Pressure: " << pres << "mmHg";
        marker.text = ss.str();

        marker_pub.publish(marker);
        loop_rate.sleep();

    }


    return 0;
}

