#version 400

layout(location=0) in vec3 in_Position;
layout(location=1) in vec2 in_TexCoord;
layout(location=2) in vec2 in_Normal;
layout(location=3) in vec4 in_Color;

out vec4 ex_Color;
out vec2 ex_TexCoord;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main(void)
{
	gl_Position = (ProjectionMatrix * ViewMatrix * ModelMatrix) * vec4(in_Position, 1.0);
	ex_Color = in_Color;
	ex_TexCoord = in_TexCoord;
}
