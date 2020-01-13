#include "Planet.hpp"
#include "Math/vec3.hpp"
#include "Math/vec2.hpp"

#include "GraphicInstance.hpp"

Planet::Planet( uint32_t resolution ) : _resolution(resolution)
{
	_vbo = 0;
	_elementBuffer = 0;
	_roughness = 1.0f;
	_strength = 0.5f;
	_baseRoughness = 1.0f;
	_nbLayers = 5;
	_persistence = 0.5f;
	_minValue = 0.5f;

	_data.resize(resolution * resolution * 6);
	_index.resize((resolution -1) * (resolution -1) * 6 * 6);
	GenerateCube();

	GraphicInstance::GetInstance()->CreateBuffer(&_vbo, _data.size() * 3, reinterpret_cast<float*>(_data.data()));
	GraphicInstance::GetInstance()->CreateVAO(&_vao, &_vbo);
	_shaderId = GraphicInstance::GetInstance()->CreateShaderProgram(
			"Ressources/Shaders/vertexShader.glsl", 
			"Ressources/Shaders/fragmentShader.glsl");

	// indices
	glGenBuffers(1, &_elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _index.size() * sizeof(unsigned int), reinterpret_cast<uint32_t*>(&_index[0]), GL_DYNAMIC_DRAW);
}

Planet::~Planet( void )
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
}

void Planet::RegenerateCube( void )
{
	_data.resize(_resolution * _resolution * 6);
	_index.resize((_resolution -1) * (_resolution -1) * 6 * 6);
	GenerateCube();

        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, 0, _data.size() * 3 * sizeof(float), reinterpret_cast<float*>(_data.data()));

	// indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuffer);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, _index.size() * sizeof(unsigned int), reinterpret_cast<uint32_t*>(&_index[0]));
}

void Planet::GenerateCube( void )
{
	vec3<float> directions[6];

	directions[0] = vec3<float>(0.0f, 1.0f, 0.0f);
	directions[1] = vec3<float>(0.0f, -1.0f, 0.0f);
	directions[2] = vec3<float>(-1.0f, 0.0f, 0.0f);
	directions[3] = vec3<float>(1.0f, 0.0f, 0.0f);
	directions[4] = vec3<float>(0.0f, 0.0f, 1.0f);
	directions[5] = vec3<float>(0.0f, 0.0f, -1.0f);

	for (uint32_t index = 0 ; index < 6 ; index++)
		GenerateFace(index, directions[index]);
}

float Planet::Evaluate( vec3<float> point )
{
	float noiseValue = 0;
	float frequency = _baseRoughness;
	float amplitude = 1;

	for ( uint32_t index = 0 ; index < _nbLayers ; index++)
	{
		float v = _noise.Evaluate(point * frequency + _center);
		noiseValue += (v + 1) * 0.5f * amplitude;
		frequency *= _roughness;
		amplitude *= _persistence;
	}

	noiseValue = ((noiseValue - _minValue) < 0) ? 0 : noiseValue - _minValue;
	return noiseValue * _strength;
}

void Planet::GenerateFace( uint32_t nbFace, vec3<float> direction )
{
	vec3<float> axisA = vec3<float>(direction.y, direction.z, direction.x);
	vec3<float> axisB = direction.Cross(axisA);
	uint32_t indexCounter = nbFace * ((_resolution - 1) * (_resolution - 1) * 6);

	for (uint32_t y = 0 ; y < _resolution ; y++)
	{
		for (uint32_t x = 0 ; x < _resolution ; x++)
		{
			uint32_t index = nbFace * (_resolution) * (_resolution) + x + y * _resolution;

			vec2<float> percent = vec2<float>(x, y) / (_resolution - 1);
			vec3<float> pointOnUnitCube = direction + (percent.x - 0.5f) * 2.0f * axisA + (percent.y - 0.5f) * 2.0f * axisB;
			vec3<float> pointOnUnitSphere = pointOnUnitCube.Normalize();
			_data[index] = pointOnUnitSphere * (1 + Evaluate(pointOnUnitSphere));

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
