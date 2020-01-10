#pragma once

#include <list>

class Camera3D;
class Renderable;

class Scene
{
	private:
		Camera3D* _currentCam;
		std::list<Renderable*> _objects;
	public:
		Scene( void );
		void MakeCurrentCamera( Camera3D* camera );
		Renderable* AddObject( Renderable* object );
		void Draw( void );
};
