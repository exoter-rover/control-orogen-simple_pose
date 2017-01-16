/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"

using namespace simple_pose;

Task::Task(std::string const& name)
    : TaskBase(name)
{
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
{
}

Task::~Task()
{
}

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;
    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;
    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();

    base::samples::RigidBodyState pose;
    if (_imu_pose.readNewest(pose) == RTT::NewData ){
        imu_pose = pose;
    }
    if (_gps_pose.readNewest(pose) == RTT::NewData ){
        gps_pose = pose;
    }

    // GPS Position    
    resulting_pose.position = gps_pose.position;


    double roll, pitch, yaw;
    // GPS yaw, IMU roll, pitch
    yaw     = gps_pose.getYaw();
    roll    = imu_pose.getRoll();
    pitch   = imu_pose.getPitch();

    resulting_pose.orientation = Eigen::Quaterniond( 
            Eigen::AngleAxisd(yaw,   Eigen::Vector3d::UnitZ()) *
            Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(roll,  Eigen::Vector3d::UnitX()));    

    _pose.write(resulting_pose);
}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
