#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_glfw.h"
#include "imgui/examples/imgui_impl_opengl3.h"

#include <iostream>

#include "GraphicInstance.hpp"
#include "Math/vec4.hpp"
#include "Input.hpp"
#include "Planet.hpp"
#include "Scene.hpp"
#include "Camera3D.hpp"

static Input input;

int main()
{
	srand(time(0));
	//// Init ////
	try
	{
		GraphicInstance::GetInstance()->Initialize();
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
		return (-1);
	}

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplGlfw_InitForOpenGL(GraphicInstance::GetInstance()->GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 130");
	ImGui::StyleColorsDark();

	GraphicInstance::GetInstance()->SetBackgroundColor(vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));

	//// Setup ////

	Scene scene;
	Camera3D* camera = new Camera3D;
	scene.MakeCurrentCamera( camera );
	Planet* planet1 = reinterpret_cast<Planet*>(scene.AddObject(new Planet(70)));

	while(!GraphicInstance::GetInstance()->ShouldClose())
	{
		input.Update();
		input.Process(camera);

		// feed inputs to dear imgui, start new frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		GraphicInstance::GetInstance()->Update();

		planet1->_center += vec3<float>(0.01f, 0.0f, 0.0f);
		planet1->RegenerateCube();

		scene.Draw();

		// Render GUI
		ImGui::Begin("Demo window");

		ImGui::SliderInt("Resolution", reinterpret_cast<int32_t*>(&planet1->_resolution), 1, 70);
		ImGui::SliderInt("Layers", reinterpret_cast<int32_t*>(&planet1->_nbLayers), 1, 10);
		ImGui::SliderFloat("Base Roughness", &planet1->_baseRoughness, 0, 5);
		ImGui::SliderFloat("Roughness", &planet1->_roughness, 0, 5);
		ImGui::SliderFloat("Persistence", &planet1->_persistence, 0, 5);
		ImGui::SliderFloat("Strength", &planet1->_strength, 0, 5);
		ImGui::SliderFloat("Min Value", &planet1->_minValue, 0, 5);
		//ImGui::SliderFloat3("Center", &planet1->_center, 0, 5);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		//

		GraphicInstance::GetInstance()->PollEvent();
		GraphicInstance::GetInstance()->SwapBuffer();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	delete planet1;

	GraphicInstance::GetInstance()->ReleaseInstance();
	return (0);
}
