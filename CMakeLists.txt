cmake_minimum_required(VERSION 3.10)

project(VDSProject1    CXX C)

project(VDSProject1    CXX C)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -std=c++14 ${LLVM_CXX_FLAGS} ")


include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/src/test/)
link_directories(${CMAKE_SOURCE_DIR}/src/test/)
include_directories(${CMAKE_SOURCE_DIR}/src/Reachability/)
link_directories(${CMAKE_SOURCE_DIR}/src/Reachability/)

include_directories(${CMAKE_SOURCE_DIR}/src/bench/)
link_directories(${CMAKE_SOURCE_DIR}/src/bench/)

include_directories(${CMAKE_SOURCE_DIR}/src/verify/)
link_directories(${CMAKE_SOURCE_DIR}/src/verify/)



add_subdirectory(src)
add_executable(VDSProject1 src/main.cpp)



target_link_libraries(VDSProject1 Manager)


