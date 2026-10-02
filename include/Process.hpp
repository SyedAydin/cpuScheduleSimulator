#pragma once 

#include <string>

struct Process{
    
int pid; // process id
int arrivalTime;    
int burstTime;
int priority;


// Runtime state variables
int remainingTime;
int startTime = -1;
int completionTime = -1;



};


