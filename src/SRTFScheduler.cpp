
#include "SRTFScheduler.hpp"

#include <limits>

std::vector<ExecutionSlice>
SRTFScheduler::schedule(std::vector<Process> processes)
{
    std::vector<ExecutionSlice> timeline;

    int currentTime = 0;
    int completed = 0;
    int n = static_cast<int>(processes.size());

    if (n == 0) {
        return timeline;
    }

    for (auto& process : processes) {
        process.remainingTime = process.burstTime;
    }

    int runningPid = -1;
    int sliceStart = 0;

    while (completed < n) {
        int selectedIndex = -1;
        int shortestRemaining = std::numeric_limits<int>::max();

        // Find the arrived process with the shortest remaining time
        for (int i = 0; i < n; ++i) {
            if (processes[i].remainingTime <= 0) {
                continue;
            }

            if (processes[i].arrivalTime > currentTime) {
                continue;
            }

            if (processes[i].remainingTime < shortestRemaining) {
                shortestRemaining = processes[i].remainingTime;
                selectedIndex = i;
            }
        }

        // No process is ready: close the current slice and advance time
        if (selectedIndex == -1) {
            if (runningPid != -1 && currentTime > sliceStart) {
                timeline.push_back({
                    runningPid, sliceStart, currentTime
                });
                runningPid = -1;
            }

            ++currentTime;
            continue;
        }

        Process& process = processes[selectedIndex];

        // A different process was selected, so close the previous slice
        if (runningPid != process.pid) {
            if (runningPid != -1 && currentTime > sliceStart) {
                timeline.push_back({
                    runningPid, sliceStart, currentTime
                });
            }

            runningPid = process.pid;
            sliceStart = currentTime;

            if (process.startTime == -1) {
                process.startTime = currentTime;
            }
        }

        // Runs the selected process for one time unit
        --process.remainingTime;
        ++currentTime;

        // Record completion
        if (process.remainingTime == 0) {
            process.completionTime = currentTime;
            ++completed;

            timeline.push_back({
                runningPid, sliceStart, currentTime
            });

            runningPid = -1;
        }
    }

    return timeline;
}
