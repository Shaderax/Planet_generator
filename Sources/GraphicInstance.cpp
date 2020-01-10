#include "GraphicInstance.hpp"
#include <iostream>
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "Math/vec4.hpp"

GLFWwindow* GraphicInstance::GetWindow( void )
{
	return (_window);
}

void GraphicInstance::FramebufferResizeCallback(GLFWwindow *window, int width, int height)
{
	std::cout << "Resize window : " << width << " " << height << std::endl;
	auto app = reinterpret_cast<GraphicInstance*>(glfwGetWindowUserPointer(window));
        glViewport(0, 0, width, height);
	app->_windowAttribute._width = width;
	app->_windowAttribute._height = height;
}

GraphicInstance* GraphicInstance::_instance = nullptr;

GraphicInstance* GraphicInstance::GetInstance( void )
{
	if (!_instance)
		_instance = new GraphicInstance;

	return _instance;
}

void GraphicInstance::ReleaseInstance( void )
{
	if (_instance)
	{
		delete _instance;
		_instance = nullptr;
	}
}

GraphicInstance::GraphicInstance( void )
{
	std::cout << "GraphicInstance Created" << std::endl;
	_window = nullptr;
	_initialized = false;
}

GraphicInstance::~GraphicInstance( void )
{
	if (_window)
		glfwDestroyWindow(_window);
	if (_initialized)
		glfwTerminate();
}

void GraphicInstance::PollEvent( void )
{
	glfwPollEvents();
}

bool GraphicInstance::ShouldClose( void )
{
	return (glfwWindowShouldClose(_window));
}

void GraphicInstance::SwapBuffer( void )
{
	glfwSwapBuffers(_window);
}

GraphicInstance::WindowAttribute GraphicInstance::GetWindowAttribute( void )
{
	return (_windowAttribute);
}

void GraphicInstance::Initialize( void )
{
	glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For Mac OS
	_initialized = true;

	_window = glfwCreateWindow(_windowAttribute._width, _windowAttribute._height, _windowAttribute._name.c_str(), NULL, NULL);

        if (_window == nullptr)
		throw std::runtime_error("Can't Create GLFW Window");

        glfwMakeContextCurrent(_window);
	glfwSetWindowUserPointer(_window, this);
        glfwSetFramebufferSizeCallback(_window, FramebufferResizeCallback);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize GLAD");
}

void GraphicInstance::SetBackgroundColor( vec4<float> color )
{
	_backgroundColor = color;
}

void GraphicInstance::Draw( void )
{
	glClearColor(_backgroundColor.x, _backgroundColor.y, _backgroundColor.z, _backgroundColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
}
