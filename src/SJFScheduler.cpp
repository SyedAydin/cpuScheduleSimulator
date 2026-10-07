#include "SJFScheduler.hpp"
//
#include <iostream>
#include <limits>
std::vector<ExecutionSlice>
SJFScheduler::schedule(std::vector<Process> processes)
{
    std::cout << "SJF SCHEDULER IS RUNNING\n";

    std::vector<ExecutionSlice> timeline;

std::vector<ExecutionSlice>
SJFScheduler::schedule(std::vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;

std::vector<ExecutionSlice> timeline;
    std::vector<bool> isCompleted(processes.size(), false);

int currentTime = 0;
int completed = 0;
    while (completed < static_cast<int>(processes.size())) {

std::vector<bool> isCompleted(processes.size(), false);
        int selectedIndex = -1;
        int shortestBurst = std::numeric_limits<int>::max();

while(completed < static_cast<int>(processes.size())){
        // Find the shortest process that has arrived
        for (int i = 0;
             i < static_cast<int>(processes.size());
             ++i) {

int selectedIndex = -1;
int shortestBurst = std::numeric_limits<int>::max();
            if (isCompleted[i]) {
                continue;
            }

// Loop finds the shortest burst time among the processes that have arrived and are not completed
for(int i = 0; i < static_cast<int>(processes.size()); ++i) {
    if (isCompleted[i]){
        continue;
    }
    
    if(processes[i].burstTime < shortestBurst) {
        shortestBurst = processes[i].burstTime;
        selectedIndex = i;
        continue;
    }
            if (processes[i].arrivalTime > currentTime) {
                continue;
            }

// No processes have arrived yet, so we can just increment the current time
if (selectedIndex == -1) {  
    int nextArrivalTime = std::numeric_limits<int>::max();
    for(int i = 0; i < static_cast<int>(processes.size()); ++i) {
        if (!isCompleted[i] && processes[i].arrivalTime < nextArrivalTime) {
            nextArrivalTime = processes[i].arrivalTime;
            if (processes[i].burstTime < shortestBurst) {
                shortestBurst = processes[i].burstTime;
                selectedIndex = i;
            }
        }
    }

    currentTime = nextArrivalTime;
    continue;
        // No process is ready yet
        if (selectedIndex == -1) {

            int nextArrivalTime =
                std::numeric_limits<int>::max();

Process& process =  processes[selectedIndex];
            for (int i = 0;
                 i < static_cast<int>(processes.size());
                 ++i) {

int startTime = currentTime;
int endTime = currentTime + process.burstTime;
                if (!isCompleted[i] &&
                    processes[i].arrivalTime < nextArrivalTime) {

timeline.push_back({process.pid, startTime, endTime});
                    nextArrivalTime =
                        processes[i].arrivalTime;
                }
            }

currentTime = endTime;
isCompleted[selectedIndex] = true;
++completed;
}
}
return timeline;
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

}
}
    return timeline;
}