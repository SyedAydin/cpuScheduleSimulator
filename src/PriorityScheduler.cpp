#include "PriorityScheduler.hpp"

#include <limits>
#include <vector>

std::vector<ExecutionSlice>
PriorityScheduler::schedule(std::vector<Process> processes)
{
    std::vector<ExecutionSlice> timeline;

    int currentTime = 0;
    int completed = 0;
    int n = static_cast<int>(processes.size());

    if (n == 0) {
        return timeline;
    }

    std::vector<bool> isCompleted(n, false);

    while (completed < n) {
        int selectedIndex = -1;
        int highestPriority = std::numeric_limits<int>::max();

        // Find the highest-priority process that has arrived.
        for (int i = 0; i < n; ++i) {
            if (isCompleted[i]) {
                continue;
            }

            if (processes[i].arrivalTime > currentTime) {
                continue;
            }

            if (processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                selectedIndex = i;
            }
        }

        // If no process is ready, advance to the next arrival.
        if (selectedIndex == -1) {
            int nextArrivalTime = std::numeric_limits<int>::max();

            for (int i = 0; i < n; ++i) {
                if (!isCompleted[i] &&
                    processes[i].arrivalTime < nextArrivalTime) {
                    nextArrivalTime = processes[i].arrivalTime;
                }
            }

            currentTime = nextArrivalTime;
            continue;
        }

        // Run the chosen process to completion.
        Process& process = processes[selectedIndex];

        int startTime = currentTime;
        int endTime = startTime + process.burstTime;

        timeline.push_back({
            process.pid,
            startTime,
            endTime
        });

        currentTime = endTime;
        isCompleted[selectedIndex] = true;
        ++completed;
    }

    return timeline;
}