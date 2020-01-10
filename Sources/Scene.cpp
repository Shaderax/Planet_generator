#include "Scene.hpp"

Scene::Scene( void )
{
	_currentCam = nullptr;
}

Renderable* Scene::AddObject( Renderable* object )
{
	_objects.push_back(object);
	return object;
}

void Scene::MakeCurrentCamera( Camera3D* camera )
{
	_currentCam = camera;
}

void Scene::Draw( void )
{

}
