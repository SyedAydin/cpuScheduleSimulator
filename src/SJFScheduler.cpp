#include "SJFScheduler.hpp"

#include <algorithm>
#include <limits>


std::vector<ExecutionSlice>
SJFScheduler::schedule(std::vector<Process>& processes) {

std::vector<ExecutionSlice> timeline;

int currentTime = 0;
int completed = 0;

std::vector<bool> isCompleted(processes.size(), false);

while(completed < static_cast<int>(processes.size())){

int selectedIndex = -1;
int shortestBurst = std::numeric_limits<int>::max();

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

// No processes have arrived yet, so we can just increment the current time
if (selectedIndex == -1) {  
    int nextArrivalTime = std::numeric_limits<int>::max();
    for(int i = 0; i < static_cast<int>(processes.size()); ++i) {
        if (!isCompleted[i] && processes[i].arrivalTime < nextArrivalTime) {
            nextArrivalTime = processes[i].arrivalTime;
        }
    }

    currentTime = nextArrivalTime;
    continue;

Process& process =  processes[selectedIndex];

int startTime = currentTime;
int endTime = currentTime + process.burstTime;

timeline.push_back({process.pid, startTime, endTime});

currentTime = endTime;
isCompleted[selectedIndex] = true;
++completed;
}
}
return timeline;

}
}
