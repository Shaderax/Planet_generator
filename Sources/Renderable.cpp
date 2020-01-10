#include "Renderable.hpp"
#include "Math/mat4.hpp"

void Renderable::Bind( void )
{

}

mat4<float> Renderable::GetModelMatrix( void )
{
	mat4<float> matModel;

	matModel = _rot.GetRotationMatrix();

	matModel(0,3) = _pos.x;
	matModel(1,3) = _pos.y;
	matModel(2,3) = _pos.z;

	matModel(0,0) *= _scale.x;
	matModel(1,1) *= _scale.y;
	matModel(2,2) *= _scale.z;

	return (matModel);
}

uint32_t Renderable::GetShaderProgram( void )
{
	return (_shaderId);
}
