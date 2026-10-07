#pragma once

#include "Scheduler.hpp"

class SJFScheduler : public Scheduler {
public:
    std::vector<ExecutionSlice>
    schedule(std::vector<Process> processes) override;

};

