#pragma once

#include "glad/glad.h"
#include "Math/vec3.hpp"
#include <vector>
#include "Object.hpp"
#include "Math/mat4.hpp"

class Scene;

class Renderable : public Object
{
	friend Scene;

	protected:
		GLuint			_vbo;
		GLuint			_vao;
		uint32_t		_shaderId = 0;
		std::vector<vec3<float>> _data;
		std::vector<uint32_t>	_index;
		GLuint			_elementBuffer;
	public:
		void Draw( void );
		mat4<float> GetModelMatrix( void );
		uint32_t GetShaderProgram( void );
};
