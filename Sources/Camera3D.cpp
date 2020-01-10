#include "Camera3D.hpp"
#include "Math/mat4.hpp"
#include "Math/vec3.hpp"
#include <math.h>
#include "GraphicInstance.hpp"

Camera3D::Camera3D( void )
{
	_target = vec3<float>(0.0f, 0.0f, 0.0f);
	_up = vec3<float>(0.0f, 1.0f, 0.0f);

	_fov = 45.0f;
	_near = 0.05f;
	_far = 100.0f;

	GraphicInstance::WindowAttribute win = GraphicInstance::GetInstance()->GetWindowAttribute();
	_aspect = win._width / win._height;
}

mat4<float> Camera3D::GetViewMatrix( void )
{
	mat4<float> view;

	view.elem[3][0] = -_pos.x;
	view.elem[3][1] = -_pos.y;
	view.elem[3][2] = _pos.z;

	return (view * _rot.GetRotationMatrix());
}

mat4< float >	Camera3D::GetProjectionMatrix( void )
{
	GraphicInstance::WindowAttribute win = GraphicInstance::GetInstance()->GetWindowAttribute();
	_aspect = (float)win._width / (float)win._height;

	mat4< float > proj;

	float scale = 1 / tan(_fov * M_PI / 180 / 2);

	proj(0, 0) = scale / _aspect;
	proj(1, 1) = -scale;
	proj(2, 2) = _far / (_near - _far);
	proj(2, 3) = -1;
	proj(3, 2) = (_near * _far) / (_near - _far);
	proj(3, 3) = 0;

	return (proj);
}

void Camera3D::SetTarget(vec3<float> target)
{
	_target = target;
}
