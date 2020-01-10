#pragma once

#include "Math/vec3.hpp"
#include "Math/Quaternion.hpp"

struct Transform3D
{
	Transform3D( void )
	{
		_pos = vec3<float>(0.0f, 0.0f, 0.0f);
		_rot = Quaternion(vec3<float>(0.0f, 0.0f, 0.0f), 1.0f);
		_scale = vec3<float>(1.0f, 1.0f, 1.0f);
	}

	void Translate(vec3<float> dir)
	{
		mat4<float> mat = _rot.GetRotationMatrix();

		vec3<float> x(mat(0, 0), mat(0, 1), mat(0, 2));
		vec3<float> y(mat(1, 0), mat(1, 1), mat(1, 2));
		vec3<float> z(mat(2, 0), mat(2, 1), mat(2, 2));

		_pos += (x * dir.x);
		_pos += (y * dir.y);
		_pos += (z * dir.z);
	}
	
	void Rotate(float x, float y, float z)
	{
		if (x)
			_rot *= Quaternion(vec3<float>(1.0f, 0.0f, 0.0f), x);
		if (y)
			_rot *= Quaternion(vec3<float>(0.0f, 1.0f, 0.0f), y);
		if (z)
			_rot *= Quaternion(vec3<float>(0.0f, 0.0f, 1.0f), z);
	}

	vec3<float>	_pos;
	Quaternion	_rot;
	vec3<float>	_scale;
};
