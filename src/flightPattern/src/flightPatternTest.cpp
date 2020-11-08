#include "flightPatterns.hpp"

state_msg drone_state;

void state_cb(const state_msg::ConstPtr& msg){
    drone_state = *msg;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "safety_test");
    ros::NodeHandle n;

    ros::Subscriber state_sub = n.subscribe<state_msg>("mavros/state", 10, state_cb);

    ros::Rate rate(RATE);

    while(ros::ok() && !drone_state.connected){
        ros::spinOnce();
        rate.sleep();

        ROS_WARN("Waiting for flight controller to connect!");
    }

    ROS_WARN("Starting safety check test. All values below");

    while(ros::ok()){




        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}