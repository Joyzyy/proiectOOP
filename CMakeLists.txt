cmake_minimum_required(VERSION 3.25.1)

set(CMAKE_OSX_ARCHITECTURES "arm64")

project(TicketApp LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(TicketApp "${PROJECT_SOURCE_DIR}/main.cpp"
"${PROJECT_SOURCE_DIR}/Locatie.cpp"
"${PROJECT_SOURCE_DIR}/Eveniment.cpp"
"${PROJECT_SOURCE_DIR}/Tichet.cpp"
"${PROJECT_SOURCE_DIR}/Meniu.cpp"
"${PROJECT_SOURCE_DIR}/Utils.cpp")

# /opt/homebrew/bin/python3

#set x86_64

find_package(Python REQUIRED Development)
target_link_libraries(TicketApp PRIVATE Python::Python)
target_include_directories(TicketApp PRIVATE /opt/homebrew/include/python3.9)

set_property(TARGET TicketApp PROPERTY CXX_STANDARD 17)
set_property(TARGET TicketApp PROPERTY CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})