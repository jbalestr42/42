#ifndef MESH_HPP
# define MESH_HPP

# include <GL/glew.h>
# include <vector>
# include "Vertex.hpp"

class Mesh
{
public:
	Mesh(void);
	Mesh(std::string const & filename);
	Mesh(Mesh const & mesh);
	Mesh(Mesh && mesh);
	virtual ~Mesh(void);

	Mesh & operator=(Mesh const & mesh);
	Mesh & operator=(Mesh && mesh);
	void draw(void);

private:
	static const std::size_t IndexCount = 2;
	enum VBOIndex : std::size_t
	{
		VertexIndex = 0,
		Index = 1
	};

	GLuint				m_vertexArrayObject;
	GLuint				m_vertexBufferObject[IndexCount];
	int					m_indiceCount;
	std::vector<Vertex>	m_vertices;
	std::vector<GLuint>	m_indices;

	void init(void);

};

#endif
