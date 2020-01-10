#version 410 core

out vec4 Color;

void main()
{
	// Ambient
	float ambientStrength = 0.5;
	vec3 ambient = ambientStrength * vec3(1.0f, 1.0f, 1.0f);

	Color = vec4(ambient, 1.0f);
}
