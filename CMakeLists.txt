cmake_minimum_required(VERSION 3.20)
project(Task_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_3 main.cpp)

include_directories("${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/include_curl"
        "${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/include_cpr")

target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/libcpr.dll.a"
        "${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/libcurl-d_imp.lib")
