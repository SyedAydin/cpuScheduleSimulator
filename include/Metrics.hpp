#pragma once

#include "Process.hpp"
#include "Types.hpp"

#include <vector>  

struct ProcessMetrics
{
    int pid; // process id
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    int completionTime; 
};


std::vector<ProcessMetrics> 
calculateMetrics(
    const std::vector<Process>& processes, 
    const std::vector<ExecutionSlice>& timeline
);