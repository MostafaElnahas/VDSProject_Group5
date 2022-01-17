cmake_minimum_required(VERSION 3.10)

project(VDSProject_Group5    CXX C)

project(VDSProject_Group5    CXX C)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -std=c++14 ${LLVM_CXX_FLAGS} ")
add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)


include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/src/test/)
link_directories(${CMAKE_SOURCE_DIR}/src/test/)

include_directories(${CMAKE_SOURCE_DIR}/src/bench/)
link_directories(${CMAKE_SOURCE_DIR}/src/bench/)

include_directories(${CMAKE_SOURCE_DIR}/src/verify/)
link_directories(${CMAKE_SOURCE_DIR}/src/verify/)



add_subdirectory(src)
add_executable(VDSProject_Group5 src/main.cpp)

target_link_libraries(VDSProject_Group5 gtest gtest_main)

target_link_libraries(VDSProject_Group5 gtest gtest_main)

target_link_libraries(VDSProject_Group5 Manager)


