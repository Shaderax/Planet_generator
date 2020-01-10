#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicInstance.hpp"
#include "Math/vec4.hpp"

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

void processInput(GLFWwindow *window)
{
	//if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	//	glfwSetWindowShouldClose(GraphicInstance::GetInstance()->GetWindow(), true);
}

int main()
{
	try
	{
		GraphicInstance::GetInstance()->Initialize();
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}

	GraphicInstance::GetInstance()->SetBackgroundColor(vec4<float>(0.2f, 0.3f, 0.3f, 1.0f));

	while(!GraphicInstance::GetInstance()->ShouldClose())
	{
		processInput(nullptr);

		GraphicInstance::GetInstance()->Draw();

		GraphicInstance::GetInstance()->PollEvent();
		GraphicInstance::GetInstance()->SwapBuffer();
	}

	GraphicInstance::GetInstance()->ReleaseInstance();
	return (0);
}
