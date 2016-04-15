#version 400

in vec4 ex_Color;
in vec2 ex_TexCoord;
out vec4 out_Color;

uniform sampler2D tex;
uniform vec2 frame_size;
uniform vec2 current_frame;

void main(void)
{
	vec2 coord = current_frame + (ex_TexCoord * frame_size);
	out_Color = texture(tex, coord);
}
