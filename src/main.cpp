#include "Scheduler.hpp"
#include <iostream>
#include <vector>

int main(){

std::vector<Process> processes = {
    {1, 0, 5, 1, 5}, // pid, arrivalTime, burstTime, priority, remainingTime
    {2, 1, 3, 2, 3},
    {3, 2, 8, 1, 8},
    {4, 3, 6, 3, 6}

};


FCFSScheduler scheduler;
std::vector<ExecutionSlice> timeline = scheduler.schedule(processes);

std::cout << "Execution Timeline:\n\n";
for (const auto& slice : timeline) 
{ std::cout << "P" << slice.pid 
    << ": " << slice.startTime 
    << " -> " << slice.endTime << '\n'; }

    return 0;
}
