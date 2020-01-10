#include "Scene.hpp"
#include "Math/mat4.hpp"
#include "Camera3D.hpp"
#include "Renderable.hpp"

Scene::Scene( void )
{
	_currentCam = nullptr;
}

Renderable* Scene::AddObject( Renderable* object )
{
	_objects.push_back(object);
	return object;
}

void Scene::MakeCurrentCamera( Camera3D* camera )
{
	_currentCam = camera;
}

void Scene::Draw( void )
{
	mat4<float> vp = _currentCam->GetProjectionMatrix() * _currentCam->GetViewMatrix();

	for (Renderable* obj : _objects)
	{
		mat4<float> mvp = vp * obj->GetModelMatrix();
		/*
		   for (uint32_t y = 0 ; y < 4 ; y++)
		   {
		   for (uint32_t x = 0 ; x < 4 ; x++)
		   std::cout << mvp(y, x) << " ";
		   std::cout << std::endl;
		   }
		   std::cout << std::endl;
		   */
		uint32_t shaderProgram = obj->GetShaderProgram();
		glUseProgram(shaderProgram);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "mvp"), 1,
				GL_TRUE, reinterpret_cast<const GLfloat *>(&mvp(0, 0)));
		glBindVertexArray(obj->_vao);
		//glDrawArrays(GL_TRIANGLES, 0, obj->_data.size() );

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->_elementBuffer);

		// Draw the triangles !
		glDrawElements(
				GL_TRIANGLES,      // mode
				obj->_index.size(),    // count
				GL_UNSIGNED_INT,   // type
				(void*)0           // element array buffer offset
			      );


	}
}












