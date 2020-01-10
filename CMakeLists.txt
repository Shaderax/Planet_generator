cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
set (CMAKE_CXX_STANDARD 17)

project(Planet_Generator)

set(SRC
	ThirdParty/glad/glad.c
	Sources/main.cpp
	Sources/GraphicInstance.cpp
	Sources/Input.cpp
	Sources/Planet.cpp
	Sources/Scene.cpp
	Sources/Camera3D.cpp
	)


if (WIN32)
	find_package(OpenGL 4.1 REQUIRED)
elseif (UNIX AND NOT APPLE)
	find_package(OpenGL 4.1 REQUIRED)
	#link_directories(/usr/lib/)
elseif (APPLE)
	find_package(OpenGL 4.1 REQUIRED)
	#link_directories(/usr/lib/)
endif()

include_directories(Extern/)
include_directories(ThirdParty/glfw/include/)
include_directories(ThirdParty/glad/include/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(ThirdParty)

add_executable(Planet_Generator ${SRC})

include_directories( ${OPENGL_INCLUDE_DIRS} ) 

target_link_libraries(Planet_Generator glfw ${OPENGL_LIBRARIES})
