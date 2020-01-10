#pragma once

#include "Math/mat4.hpp"
#include "Math/vec3.hpp"
#include "Object.hpp"

class Camera3D : public Object
{
	public:
		Camera3D( void );
		void MakeCurrent( void );
		mat4<float> GetViewMatrix( void );
		mat4< float >	GetProjectionMatrix( void );
		void SetTarget(vec3<float> target);
	private:
		vec3<float>	_target;
		vec3<float>	_up;

		float _fov;
		float _near;
		float _far;
		float _aspect;
};
