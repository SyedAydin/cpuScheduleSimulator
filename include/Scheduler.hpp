#include "Types.hpp"
#include "Process.hpp"
#pragma once

#include <vector>
#include "Process.hpp"
#include "Types.hpp"

#include <vector>

class Scheduler {
public:
    virtual ~Scheduler() = default;

    public:
        virtual ~Scheduler() = default;

        virtual std::vector<ExecutionSlice>
        schedule(std::vector<Process> &processes) = 0;
    virtual std::vector<ExecutionSlice>
    schedule(std::vector<Process> processes) = 0;
};

class FCFSScheduler : public Scheduler{ 
class FCFSScheduler : public Scheduler {
public:

    std::vector<ExecutionSlice> 
    schedule(std::vector<Process> &processes) override;

};
    std::vector<ExecutionSlice>
    schedule(std::vector<Process> processes) override;
};