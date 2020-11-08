#include "flightPatterns.hpp"

//Class that holds methods that supply messages for flight patterns

trajectory_msg flight_patterns::land(int time, const ros::Duration &current_time){
    trajectory_msg land_msg;
    float t = current_time.toSec();
    float mod_t = std::fmod(t, time);
    float xpos, ypos, zpos;
    if(mod_t < time){
        xpos = 0;
        ypos = 0;
        zpos = mod_t/time;
    }
    else{
        xpos = 0;
        ypos =0;
        zpos = 1;
    }
    land_msg.pose.pose.position.x = xpos;
    land_msg.pose.pose.position.y = ypos;
    land_msg.pose.pose.position.z = zpos;
    land_msg.mode = "land";

    return land_msg;
}

trajectory_msg flight_patterns::takeoff(int time, const ros::Duration &current_time){
    trajectory_msg takeoff_msg;
    float t = current_time.toSec();
    float mod_t = std::fmod(t, time);
    float xpos, ypos, zpos;
    if(mod_t < time){
        xpos = 0;
        ypos = 0;
        zpos = 1- (mod_t - time) / time;
    }
    else{
        xpos = 0;
        ypos = 0;
        zpos = 0;
    }
    takeoff_msg.pose.pose.position.x = xpos;
    takeoff_msg.pose.pose.position.y = ypos;
    takeoff_msg.pose.pose.position.z = zpos;

    return takeoff_msg;

}