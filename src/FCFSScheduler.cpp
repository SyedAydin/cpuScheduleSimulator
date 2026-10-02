#include "Scheduler.hpp"

#include <algorithm>

std::vector<ExecutionSlice> FCFSScheduler::schedule(std::vector<Process> &processes) {
    std::vector<ExecutionSlice> timeline;

    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;

    for (auto &process : processes) {
        if (currentTime < process.arrivalTime) {
            currentTime = process.arrivalTime; // Wait for the process to arrive
        }

        ExecutionSlice slice;
        slice.pid = process.pid;
        slice.startTime = currentTime;
        slice.endTime = currentTime + process.burstTime;

        timeline.push_back(slice);

        currentTime = slice.endTime; // Update current time after executing the process
    }

    return  timeline;
}