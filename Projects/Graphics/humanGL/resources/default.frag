#version 400

in vec4 ex_Color;
in vec2 ex_TexCoord;
out vec4 out_Color;

void main(void)
{
	//out_Color = mix(ex_Color, texture(tex, ex_TexCoord), 0.0);
	out_Color = ex_Color;
}
