#include "Texture.hpp"
#include "Shader.hpp"

Texture::Texture(std::string const & filename) :
	m_textureID(0),
	m_width(0),
	m_height(0)
{
	//TODO check if file exist and use lib to load png
	unsigned char * data = loadBmp(filename);
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	if (data)
		delete data;
}

Texture::Texture(Texture const & texture)
{
	*this = texture;
}

Texture::~Texture(void)
{
	glDeleteTextures(1, &m_textureID);
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

unsigned char * Texture::loadBmp(std::string const & filename)
{
	unsigned char	header[54];
	unsigned int	imageSize;
	unsigned char *	data = nullptr;

	FILE *file = fopen(filename.c_str(), "rb");
	if (!file || fread(header, 1, 54, file) != 54 || header[0] != 'B' || header[1] != 'M')
		return (nullptr);
	imageSize = *(int*)&(header[0x22]);
	m_width = *(int*)&(header[0x12]);
	m_height = *(int*)&(header[0x16]);
	if (imageSize == 0)
		imageSize = m_width * m_height * 3;
	data = new unsigned char[imageSize + 1];
	data[imageSize] = '\0';
	fread(data, 1, imageSize, file);
	fclose(file);
	return (data);
}

std::size_t Texture::getHeight(void) const
{
	return m_height;
}

std::size_t Texture::getWidth(void) const
{
	return m_width;
}
