#include <vector>
#include <iostream>

#include "Scheduler.hpp"
#include "Metrics.hpp"
#include "SJFScheduler.hpp"
#include "SRTFScheduler.hpp"

int main(){

    // FCFS UNITS
// std::vector<Process> processes = {
//     {1, 0, 5, 1, 5}, // pid, arrivalTime, burstTime, priority, remainingTime
//     {2, 1, 3, 2, 3},
//     {3, 2, 8, 1, 8},
//     {4, 3, 6, 3, 6}

// };


// SJFS UNITS
// std::vector<Process> processes = {
//     {1, 0, 8, 1, 8},
//     {2, 1, 4, 2, 4},
//     {3, 2, 2, 1, 2},
//     {4, 3, 1, 3, 1}
// };

//SRTF UNITS
std::vector<Process> processes = {
    {1, 0, 8, 1, 8},
    {2, 1, 4, 2, 4},
    {3, 2, 2, 1, 2},
    {4, 3, 1, 3, 1}
};

SRTFScheduler scheduler;
auto timeline = scheduler.schedule(processes);

auto metrics = calculateMetrics(processes, timeline);

std::cout << "Execution Timeline:\n\n";

for (const auto& slice : timeline) {
    std::cout << "P" << slice.pid
              << ": " << slice.startTime
              << " -> " << slice.endTime << '\n';
}

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


// cmake --build build
// .\build\cpuScheduleSimulator.exe