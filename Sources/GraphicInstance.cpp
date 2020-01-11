#include "GraphicInstance.hpp"
#include <iostream>
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "Math/vec4.hpp"
#include <vector>
#include <string>
#include <fstream>

static std::vector<char> ReadFile(const std::string& filename);

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

	glEnable(GL_DEPTH_TEST);
	glfwSwapInterval(1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void GraphicInstance::SetBackgroundColor( vec4<float> color )
{
	_backgroundColor = color;
}

void GraphicInstance::Update( void )
{
	glClearColor(_backgroundColor.x, _backgroundColor.y, _backgroundColor.z, _backgroundColor.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicInstance::ShowCursor( bool select )
{
	glfwSetInputMode(_window, GLFW_CURSOR, (select) ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
}

void GraphicInstance::GetCursorPosition( double* x, double* y)
{
	glfwGetCursorPos(_window, x, y);
}

void GraphicInstance::CreateBuffer( GLuint* vbo, uint32_t size, float* array)
{
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), array, GL_DYNAMIC_DRAW);
}

void GraphicInstance::CreateVAO( GLuint* vao, GLuint* vboToBind )
{
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vboToBind);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

GLuint GraphicInstance::CompileShader( std::vector<char>& shaderCode, int shaderType )
{
	GLuint			shader_id;
	int			success;
	char			infolog[512];

	shader_id = glCreateShader(shaderType);
	const char *cstr = shaderCode.data();
	glShaderSource(shader_id, 1, &cstr, NULL);
	glCompileShader(shader_id);
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader_id, 512, NULL, infolog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED : " << infolog << std::endl;
	}

	return (shader_id);
}

uint32_t GraphicInstance::CreateShaderProgram( std::string vertPath, std::string fragPath )
{
	int	success;
	char	infolog[512];

	std::vector<char>&& vertCode = ReadFile(vertPath);
	std::vector<char>&& fragCode = ReadFile(fragPath);

	GLuint vShaderId = CompileShader(vertCode, GL_VERTEX_SHADER);
	GLuint fShaderId = CompileShader(fragCode, GL_FRAGMENT_SHADER);

	uint32_t shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vShaderId);
	glAttachShader(shaderProgram, fShaderId);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		throw std::runtime_error(infolog);
	}
	glDeleteShader(vShaderId);
	glDeleteShader(fShaderId);

	return (shaderProgram);
}

static std::vector<char> ReadFile(const std::string& filename)
{
	std::ifstream file(filename, std::ios::ate | std::ios::binary);

	if (!file.is_open())
		throw std::runtime_error("failed to open file!" + filename);

	size_t fileSize = (size_t) file.tellg();
	std::vector<char> buffer(fileSize);

	file.seekg(0);
	file.read(buffer.data(), fileSize);

	file.close();

	return buffer;
}
