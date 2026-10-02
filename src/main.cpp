#include <iostream>
#include <vector>

#include "Scheduler.hpp"
#include "Metrics.hpp"


int main(){

std::vector<Process> processes = {
    {1, 0, 5, 1, 5}, // pid, arrivalTime, burstTime, priority, remainingTime
    {2, 1, 3, 2, 3},
    {3, 2, 8, 1, 8},
    {4, 3, 6, 3, 6}

};


FCFSScheduler scheduler;
auto timeline = scheduler.schedule(processes);

auto metrics = calculateMetrics(processes, timeline);

std::cout << "Execution Timeline:\n\n";
for (const auto& slice : timeline) 
{ std::cout << "P" << slice.pid 
    << ": " << slice.startTime 
    << " -> " << slice.endTime << '\n'; }

std::cout << "\nMetrics\n";
std::cout << "-------\n";


for (const auto& metric : metrics) {
    std::cout
        << "P" << metric.pid
        << " | Completion: " << metric.completionTime
        << " | Turnaround: " << metric.turnaroundTime
        << " | Waiting: " << metric.waitingTime
        << " | Response: " << metric.responseTime
        << '\n';
}


    return 0;

}

