#ifndef SHADER_HPP
# define SHADER_HPP

# include <GL/glew.h>
# include <string>
# include <map>
# include "Matrix.hpp"
# include "Vector2.hpp"

class Shader
{
public:
	enum Attribute : std::size_t
	{
		Position = 0,
		TexCoord = 1,
		Normal = 2,
		Color = 3
	};

	Shader(std::string const & fragShader, std::string const & vertShader);
	Shader(Shader const & shader);
	virtual ~Shader(void);

	Shader & operator=(Shader const & shader);

	void bind(void);
	void unbind(void);
	void setParameter(std::string const & name, Vector2 const & vector);
	void setParameter(std::string const & name, Matrix const & matrix);
	void setParameter(std::string const & name, int value);
	void setParameter(std::string const & name, float value);
	int getAttribute(Attribute attribute) const;

private:
	typedef std::map<std::string, int>	ParamMap;
	static const std::size_t AttributeCount = 4;

	GLint		m_program;
	GLint		m_shaders[2];
	GLint		m_uniforms[5];
	GLint		m_attributes[AttributeCount];
	Matrix		m_model;
	Matrix		m_view;
	Matrix		m_projection;
	ParamMap	m_params;

	Shader(void);
	int getParamIndex(std::string const & name);
	void init(std::string const & fragShader, std::string const & vertShader);
	std::string readShader(std::string const & fileName);
	GLuint loadShader(std::string const & filename, GLenum shaderType);

};

#endif
