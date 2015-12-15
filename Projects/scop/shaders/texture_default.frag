varying vec2 f_texcoord;
uniform sampler2D mytexture;

void main(void)
{
	  gl_FragColor = texture2D(mytexture, f_texcoord);
}
