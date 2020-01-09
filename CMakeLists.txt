cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
set (CMAKE_CXX_STANDARD 17)

project(Planet_Generator)

set(SRC
	Sources/main.cpp
	)

include_directories(ThirdParty/glfw/include/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(ThirdParty)

add_executable(Planet_Generator ${SRC})

target_link_libraries(Planet_Generator glfw)
