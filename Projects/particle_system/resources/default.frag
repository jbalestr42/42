#version 400

in float ex_Color;
out vec4 out_Color;

void main(void)
{
	vec3 col = mix(vec3(1.0, 0.0, 0.0), vec3(0.8, 0.2, 0.0), clamp(ex_Color / 3.f, 0.0, 1.0));
	out_Color = vec4(col, 1.0);
}
