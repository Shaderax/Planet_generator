#include "Planet.hpp"
#include "Math/vec3.hpp"
#include "Math/vec2.hpp"

#include "GraphicInstance.hpp"

Planet::Planet( uint32_t resolution ) : _resolution(resolution)
{
	_vbo = 0;
	_elementBuffer = 0;

	_data.resize(3);
	_data[0] = vec3<float>(-0.5, -0.5, 0.0f);
	_data[1] = vec3<float>(0.5, -0.5, 0.0f);
	_data[2] = vec3<float>(0.0, 0.5, 0.0f);

	_index.resize(3);
	_index[0] = 0;
	_index[1] = 1;
	_index[2] = 2;
	
	//_data.resize(resolution * resolution * 6);
	//_index.resize((resolution -1) * (resolution -1) * 6);
	//GenerateCube();

	GraphicInstance::GetInstance()->CreateBuffer(&_vbo, _data.size() * 3, reinterpret_cast<float*>(_data.data()));
	GraphicInstance::GetInstance()->CreateVAO(&_vao, &_vbo);
	_shaderId = GraphicInstance::GetInstance()->CreateShaderProgram(
			"Ressources/Shaders/vertexShader.glsl", 
			"Ressources/Shaders/fragmentShader.glsl");

	// indices
	glGenBuffers(1, &_elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _index.size() * sizeof(unsigned int), reinterpret_cast<uint32_t*>(&_index[0]), GL_STATIC_DRAW);
}

Planet::~Planet( void )
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
}

void Planet::GenerateCube( void )
{
	vec3<float> directions[6];

	directions[0] = vec3<float>(0.0f, 1.0f, 0.0f);
	directions[1] = vec3<float>(0.0f, -1.0f, 0.0f);
	directions[2] = vec3<float>(-1.0f, 0.0f, 0.0f);
	directions[3] = vec3<float>(1.0f, 0.0f, 0.0f);
	directions[4] = vec3<float>(0.0f, 0.0f, -1.0f);
	directions[5] = vec3<float>(0.0f, 0.0f, 1.0f);

	for (uint32_t index = 0 ; index < 6 ; index++)
		GenerateFace(index, directions[index]);
}

void Planet::GenerateFace( uint32_t index, vec3<float> direction )
{
	vec3<float> axisA = vec3<float>(direction.y, direction.z, direction.x);
	vec3<float> axisB = direction.Cross(axisA);
	uint32_t indexCounter = 0;

	for (uint32_t y = 0 ; y < _resolution ; y++)
	{
		for (uint32_t x = 0 ; x < _resolution ; x++)
		{
			uint32_t index = x + y * _resolution;

			vec2<float> percent = vec2<float>(x / _resolution - 1, y / _resolution - 1);
			vec3<float> pointOnUnitCube = direction + (percent.x - 0.5f) * 2.0f * axisA + (percent.y - 0.5f) * 2.0f * axisB;
			//Vector3 pointOnUnitSphere = pointOnUnitCube.normalized;
			_data[index] = pointOnUnitCube;//pointOnUnitSphere;

			if (x != _resolution - 1 && y != _resolution - 1)
			{
				_index[indexCounter] = index;
				_index[indexCounter + 1] = index + _resolution + 1;
				_index[indexCounter + 2] = index + _resolution;

				_index[indexCounter + 3] = index;
				_index[indexCounter + 4] = index + 1;
				_index[indexCounter + 5] = index + _resolution + 1;
				indexCounter += 6;
			}
		}
	}
}
