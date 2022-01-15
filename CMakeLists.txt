cmake_minimum_required(VERSION 3.10)
<<<<<<< HEAD
project(VDSProject_Group5    CXX C)
=======
project(VDSProject_Group5    CXX C)
>>>>>>> parent of 51577b1 (CMAKE)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 ${LLVM_CXX_FLAGS} ")
add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)


include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/src/test/)
link_directories(${CMAKE_SOURCE_DIR}/src/test/)

add_subdirectory(src)
add_executable(VDSProject_Group5 src/main.cpp)
<<<<<<< HEAD
target_link_libraries(VDSProject_Group5 gtest gtest_main)
=======
target_link_libraries(VDS_ProjectGroup5 gtest gtest_main)
>>>>>>> parent of 51577b1 (CMAKE)
target_link_libraries(VDSProject_Group5 Manager)
