#include "Scheduler.hpp"

#include <algorithm>

std::vector<ExecutionSlice>
FCFSScheduler::schedule(std::vector<Process> processes)
{
    std::sort(
        processes.begin(),
        processes.end(),
        [](const Process& a, const Process& b) {
            return a.arrivalTime < b.arrivalTime;
        }
    );

    std::vector<ExecutionSlice> timeline;

    int currentTime = 0;

    for (const auto& process : processes) {

        if (currentTime < process.arrivalTime) {
            currentTime = process.arrivalTime;
        }

        int start = currentTime;
        int end = start + process.burstTime;

        timeline.push_back({
            process.pid,
            start,
            end
        });

        currentTime = end;
    }

    return timeline;
}