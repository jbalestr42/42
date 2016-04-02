#ifndef TEXTURE_HPP
# define TEXTURE_HPP

# include <GL/glew.h>
# include <cstddef>
# include <string>

class Shader;

class Texture
{
public:
	Texture(std::string const & filename);
	virtual ~Texture(void);

	std::size_t getHeight(void) const;
	std::size_t getWidth(void) const;

	void bind(Shader & shader);
	void bind(GLenum textureUnit, GLenum textureTarget);
	bool load(void);

protected:
	Texture(Texture const & texture);
	Texture & operator=(Texture const & texture);

private:
	GLuint			m_textureID;
	std::size_t		m_width;
	std::size_t		m_height;

	Texture(void) = delete;

	unsigned char * loadBmp(std::string const & filename);

};

#endif
