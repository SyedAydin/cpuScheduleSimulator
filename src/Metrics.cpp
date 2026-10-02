    #include "Metrics.hpp"

        #include <unordered_map>
        #include <vector>


        std::vector<ProcessMetrics> calculateMetrics(
            const std::vector<Process>& processes, 
            const std::vector<ExecutionSlice>& timeline 
        )
        
        {
            std::unordered_map<int, int> completionTimes;
            std::unordered_map<int, int> firstStartTimes;

            // Find completion time and first start time
            for (const auto& slice : timeline) 
            { completionTimes[slice.pid] = slice.endTime; 
                auto it = firstStartTimes.find(slice.pid); 

                if (it == firstStartTimes.end()){
                    firstStartTimes[slice.pid] = slice.startTime;
                }
            } 
            

            
            std::vector<ProcessMetrics> results; 
            for (const auto& process : processes) { int completion = completionTimes[process.pid]; 
                int turnaround = completion - process.arrivalTime; 
                int waiting = turnaround - process.burstTime; 
                int response = firstStartTimes[process.pid] - process.arrivalTime;

            results.push_back({process.pid, turnaround, waiting, response, completion});
            
            }

            return results;
        };