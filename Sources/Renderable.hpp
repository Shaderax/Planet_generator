#pragma once

#include "glad/glad.h"
#include "Math/vec3.hpp"
#include <vector>
#include "Object.hpp"

class Renderable : public Object
{
	protected:
		GLuint  _vbo;
		GLuint	_vao;
		uint32_t _shaderId = 0;
		std::vector<vec3<float>> _data;
		std::vector<uint32_t> _index;
	public:
		void Bind( void );
		void Draw( void );
};
