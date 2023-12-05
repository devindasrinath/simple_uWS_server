cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -O0 -coverage")

include_directories(~/development/axp/nextgen/3rdparty/include
        ~/development/axp/nextgen/3rdparty/include/uWebSockets/
        ~/development/axp/nextgen/3rdparty/include/nats.c/)

link_directories(~/development/axp/nextgen/3rdparty/lib
        ~/development/axp/nextgen/lib
        /usr/local/lib64)

add_compile_definitions(ENABLE_METRICS_PREVIEW)

find_package(cpp-jwt REQUIRED)

add_executable(untitled2 main.cpp)


target_link_libraries(untitled2 cpp-jwt::cpp-jwt
        ssl
        z  # Add this line to link against zlib
        crypto
        uSockets
)


