cmake_minimum_required(VERSION 3.16)

project(cpuScheduleSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpuScheduleSimulator
    src/main.cpp
    src/Scheduler.cpp
    src/FCFSScheduler.cpp
    src/Simulation.cpp
    src/Metrics.cpp
)

target_include_directories(cpuScheduleSimulator
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
