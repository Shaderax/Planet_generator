#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "GraphicInstance.hpp"
#include "Math/vec4.hpp"

#include "Input.hpp"

#include "Planet.hpp"

#include "Scene.hpp"

#include "Camera3D.hpp"

static Input input;

void processInput(GLFWwindow *window)
{
	//if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	//	glfwSetWindowShouldClose(GraphicInstance::GetInstance()->GetWindow(), true);
}

int main()
{
	//// Init ////
	try
	{
		GraphicInstance::GetInstance()->Initialize();
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}

	GraphicInstance::GetInstance()->SetBackgroundColor(vec4<float>(0.2f, 0.3f, 0.3f, 1.0f));

	//// Setup ////
	
	Scene scene;
	Camera3D* camera = new Camera3D;
	scene.MakeCurrentCamera( camera );
	Planet* planet1 = reinterpret_cast<Planet*>(scene.AddObject(new Planet(100)));

	while(!GraphicInstance::GetInstance()->ShouldClose())
	{
		input.Update();
		//processInput(nullptr);

		GraphicInstance::GetInstance()->Update();

		scene.Draw();

		GraphicInstance::GetInstance()->PollEvent();
		GraphicInstance::GetInstance()->SwapBuffer();
	}

	delete planet1;

	GraphicInstance::GetInstance()->ReleaseInstance();
	return (0);
}
