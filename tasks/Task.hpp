/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef SIMPLE_POSE_TASK_TASK_HPP
#define SIMPLE_POSE_TASK_TASK_HPP

#include "simple_pose/TaskBase.hpp"

namespace simple_pose {

    
    class Task : public TaskBase
    {
	friend class TaskBase;
    protected:
        base::samples::RigidBodyState imu_pose;
        base::samples::RigidBodyState gps_pose;
        base::samples::RigidBodyState resulting_pose;


    public:
        Task(std::string const& name = "simple_pose::Task");
        Task(std::string const& name, RTT::ExecutionEngine* engine);

	    ~Task();

        bool configureHook();
        bool startHook();
        void updateHook();
        void errorHook();
        void stopHook();
        void cleanupHook();
    };
}

#endif

