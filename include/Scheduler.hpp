#pragma once

#include "Process.hpp"
#include "Types.hpp"

#include <vector>

class Scheduler {
public:
    virtual ~Scheduler() = default;

    virtual std::vector<ExecutionSlice>
    schedule(std::vector<Process> processes) = 0;
};

class FCFSScheduler : public Scheduler {
public:
    std::vector<ExecutionSlice>
    schedule(std::vector<Process> processes) override;
};