#version 400

layout(location=0) in vec3 in_Position;
layout(location=1) in float in_Color;

out float ex_Color;
out vec3 ex_Position;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	gl_Position = (ProjectionMatrix * ViewMatrix * ModelMatrix) * vec4(in_Position, 1.0);
	ex_Color = in_Color;
	ex_Position = in_Position;
}
