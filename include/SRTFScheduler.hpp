#pragma once

#include "Scheduler.hpp"

class SRTFScheduler : public Scheduler {
    public:
        std::vector<ExecutionSlice>
        schedule(std::vector<Process> processes) override;
};
