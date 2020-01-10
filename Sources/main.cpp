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

void processInput( Camera3D* cam )
{
	if(glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(GraphicInstance::GetInstance()->GetWindow(), true);

	vec3<float> dir;
	float rot = 0.0f;

	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
		dir.z += 0.01f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
		dir.z -= 0.1f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
		dir.x -= 0.01f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
		dir.x += 0.01f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
		dir.y += 0.01f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		dir.y -= 0.01f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
		rot = 1.0f;
	if (glfwGetKey(GraphicInstance::GetInstance()->GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		rot = -1.0f;

	cam->Translate(dir);
	cam->Rotate(0.0f, rot, 0.0f);
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

	GraphicInstance::GetInstance()->SetBackgroundColor(vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));

	//// Setup ////

	Scene scene;
	Camera3D* camera = new Camera3D;
	//camera->_pos.z = 3.0f;
	scene.MakeCurrentCamera( camera );
	Planet* planet1 = reinterpret_cast<Planet*>(scene.AddObject(new Planet(100)));

	while(!GraphicInstance::GetInstance()->ShouldClose())
	{
		input.Update();
		processInput(camera);

		GraphicInstance::GetInstance()->Update();

		scene.Draw();

		GraphicInstance::GetInstance()->PollEvent();
		GraphicInstance::GetInstance()->SwapBuffer();
	}

	delete planet1;

	GraphicInstance::GetInstance()->ReleaseInstance();
	return (0);
}
