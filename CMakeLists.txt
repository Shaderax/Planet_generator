cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
set (CMAKE_CXX_STANDARD 17)

project(Planet_Generator)

set(SRC
	Sources/main.cpp
	)

add_subdirectory(ThirdParty)

add_executable(Planet_Generator ${SRC})
