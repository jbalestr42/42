#ifndef MESH_HPP
# define MESH_HPP

# include <GL/glew.h>
# include <vector>
# include "Transformable.hpp"
# include "Vertex.hpp"

class Shader;

class Mesh : public Transformable
{
public:
	Mesh(void);
	Mesh(Mesh const & mesh) = delete;
	virtual ~Mesh(void);

	Mesh & operator=(Mesh const & mesh) = delete;
	void draw(Shader & shader);

private:
	static const std::size_t IndexCount = 2;
	enum VBOIndex : std::size_t
	{
		VertexIndex = 0,
		Index = 1
	};

	GLuint		m_vertexArrayObject;
	GLuint		m_vertexBufferObject[IndexCount];
	int			m_indiceCount;

	void init(std::vector<Vertex> const & vertices, std::vector<GLuint> const & indices);

};

#endif
