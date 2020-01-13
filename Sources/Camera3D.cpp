#include "Camera3D.hpp"
#include "Math/mat4.hpp"
#include "Math/vec3.hpp"
#include <math.h>
#include "GraphicInstance.hpp"

Camera3D::Camera3D( void )
{
	_fov = 45.0f;
	_near = 0.01f;
	_far = 1000.0f;

	GraphicInstance::WindowAttribute win = GraphicInstance::GetInstance()->GetWindowAttribute();
	_aspect = win._width / win._height;
}

mat4<float> Camera3D::GetViewMatrix( void )
{
	mat4<float> view = _rot.GetRotationMatrix();

	view.elem[0][3] = -_pos.x;
	view.elem[1][3] = -_pos.y;
	view.elem[2][3] = _pos.z;

	return (view/* * _rot.GetRotationMatrix()*/);
}

mat4< float >	Camera3D::GetProjectionMatrix( void )
{
	GraphicInstance::WindowAttribute win = GraphicInstance::GetInstance()->GetWindowAttribute();
	_aspect = (float)win._width / (float)win._height;

	mat4< float > proj;

	float scale;

	scale = 1 / tan(_fov * 0.5 * (M_PI / 180));

	proj(0, 0) = scale / _aspect;
	proj(1, 1) = scale;
	proj(2, 2) = -(_far + _near) / (_far - _near);
	proj(3, 2) = -1;
	proj(2, 3) = -(_near * _far) / (_far - _near) + 0.5f;

	return (proj);
}
























