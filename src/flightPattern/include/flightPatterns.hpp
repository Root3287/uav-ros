#ifndef FLIGHT_PATTERNS_H
#define FLIGHT_PATTERNS_H

#include <ros/ros.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/State.h>
#include <flightPattern/Trajectory.h>

typedef mavros_msgs::State state_msg;
typedef flightPattern::Trajectory trajectory_msg;


//position needs to be updated atleast 20 times a second
#define RATE 25

class flight_patterns{
    private:
    state_msg drone_state;

    public:

    trajectory_msg land(int time, const ros::Duration &current_time);

    trajectory_msg takeoff(int time, const ros::Duration &current_time);

};

#endif SAFETY_CHECK_H