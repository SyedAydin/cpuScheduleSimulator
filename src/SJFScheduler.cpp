#include "SJFScheduler.hpp"

#include <iostream>
#include <limits>

std::vector<ExecutionSlice>
SJFScheduler::schedule(std::vector<Process> processes)
{
    std::cout << "SJF SCHEDULER IS RUNNING\n";

    std::vector<ExecutionSlice> timeline;

    int currentTime = 0;
    int completed = 0;

    std::vector<bool> isCompleted(processes.size(), false);

    while (completed < static_cast<int>(processes.size())) {

        int selectedIndex = -1;
        int shortestBurst = std::numeric_limits<int>::max();

        // Find the shortest process that has arrived
        for (int i = 0;
             i < static_cast<int>(processes.size());
             ++i) {

            if (isCompleted[i]) {
                continue;
            }

            if (processes[i].arrivalTime > currentTime) {
                continue;
            }

            if (processes[i].burstTime < shortestBurst) {
                shortestBurst = processes[i].burstTime;
                selectedIndex = i;
            }
        }

        // No process is ready yet
        if (selectedIndex == -1) {

            int nextArrivalTime =
                std::numeric_limits<int>::max();

            for (int i = 0;
                 i < static_cast<int>(processes.size());
                 ++i) {

                if (!isCompleted[i] &&
                    processes[i].arrivalTime < nextArrivalTime) {

                    nextArrivalTime =
                        processes[i].arrivalTime;
                }
            }

            currentTime = nextArrivalTime;
            continue;
        }

        Process& process = processes[selectedIndex];

        int startTime = currentTime;
        int endTime = currentTime + process.burstTime;

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