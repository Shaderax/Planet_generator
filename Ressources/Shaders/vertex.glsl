#version 410 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 anormal;
layout (location = 2) in vec2 text_coord;

uniform mat4 mvp;
uniform mat4 model;

out	vec3 color_obj;
out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoord;

void main()
{
	FragPos = vec3(model * vec4(vertex, 1.0));
	Normal = mat3(transpose(inverse(model))) * anormal;  

	TexCoord = vec2(text_coord.x, text_coord.y);

	color_obj = vertex * 0.4f + 0.4f;

	gl_Position = mvp * vec4(vertex, 1.0f);
}
