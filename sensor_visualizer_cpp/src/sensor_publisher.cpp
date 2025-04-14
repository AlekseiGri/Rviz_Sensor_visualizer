#include "ros/ros.h"
#include "std_msgs/Float32.h"

#include <cstdlib>
#include <ctime>


int getRandom(int min, int max)
{
    int x = rand() % (max - min + 1) + min;
    return x;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sensor_publisher");
    ros::NodeHandle n;

    ros::Publisher tem_pub = n.advertise<std_msgs::Float32>("/sensor/temperature", 10);
    ros::Publisher pre_pub = n.advertise<std_msgs::Float32>("/sensor/pressure", 10);

    int temp_min, temp_max, pres_min, pres_max, rate;

    n.getParam("temperature_min", temp_min);
    n.getParam("temperature_max", temp_max);
    n.getParam("pressure_min", pres_min);
    n.getParam("pressure_max", pres_max);
    n.getParam("publish_rate", rate);
    
    ros::Rate loop_rate(rate);

    std::srand(std::time(nullptr));
    
    int count = 0;

    while (ros::ok())
    {
        std_msgs::Float32 tem_msg;
        std_msgs::Float32 pre_msg;

        tem_msg.data = getRandom(temp_min, temp_max);
        pre_msg.data = getRandom(pres_min, pres_max);
        
        ROS_INFO("Count: %d / temperature: %.2f / pressure: %.2f", count, tem_msg.data, pre_msg.data);

        tem_pub.publish(tem_msg);
        pre_pub.publish(pre_msg);

        ros::spinOnce();

        loop_rate.sleep();

        ++count;

    }

    return 0;

}
