cmake_minimum_required(VERSION 3.10)
project(StacktraceExample)

# Specify the Boost library directory (adjust this if necessary)
set(BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu")

# Only useful in Debug mode.
set(CMAKE_BUILD_TYPE Debug)

# Manually find Boost stacktrace libraries
find_library(BOOST_STACKTRACE_LIB boost_stacktrace_backtrace PATHS ${BOOST_LIBRARYDIR})
find_library(BOOST_STACKTRACE_ADDR2LINE_LIB boost_stacktrace_addr2line PATHS ${BOOST_LIBRARYDIR})

# Include Boost headers
include_directories(include "/usr/include/boost")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(StacktraceExample main.cpp)

# Link Boost stacktrace libraries
target_link_libraries(StacktraceExample ${BOOST_STACKTRACE_LIB} ${BOOST_STACKTRACE_ADDR2LINE_LIB} dl)
