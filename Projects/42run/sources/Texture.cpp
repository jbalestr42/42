#include "Texture.hpp"
#include "Shader.hpp"

Texture::Texture(std::string const & filename) :
	m_textureID(0),
	m_width(0),
	m_height(0)
{
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	ilGenImages(1, &m_id);
	ilBindImage(m_id);
	ilLoadImage(filename.c_str());
	m_width = ilGetInteger(IL_IMAGE_WIDTH);
	m_height = ilGetInteger(IL_IMAGE_HEIGHT);

	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0); // rows are tightly packed
	glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
	glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // pixels are tightly packep

	int err = ilGetError();
	std::cout << err << " " << " "<<filename << std::endl;

	if (!ilGetData())
		return ;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE), ilGetData());
	ilBindImage(0);
}

Texture::Texture(Texture const & texture)
{
	*this = texture;
}

Texture::~Texture(void)
{
	glDeleteTextures(1, &m_textureID);
	ilDeleteImage(m_id);
	ilBindImage(0);
}

Texture & Texture::operator=(Texture const & texture)
{
	(void)texture;
	return (*this);
}

void Texture::bind(Shader & shader)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	shader.setParameter("tex", 0);
}

void Texture::bind(GLenum textureUnit, GLenum textureTarget)
{
	glActiveTexture(textureUnit);
	glBindTexture(textureTarget, m_textureID);
}

bool Texture::load(void)
{
	return (true);
}

std::size_t Texture::getHeight(void) const
{
	return m_height;
}

std::size_t Texture::getWidth(void) const
{
	return m_width;
}
