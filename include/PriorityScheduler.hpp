#pragma once

#include "Scheduler.hpp"

class PriorityScheduler : public Scheduler {
    public:
        std::vector<ExecutionSlice>
        schedule(std::vector<Process> processes) override;
};