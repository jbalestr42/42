#include "Mesh.hpp"
#include "Shader.hpp"
#include <iostream>
#include <cassert>

Mesh::Mesh(void) :
	Transformable(),
	m_vertexArrayObject(-1),
	m_indiceCount(0)
{
	for (std::size_t i = 0; i < IndexCount; i++)
		m_vertexBufferObject[i] = -1;

	// Create Cube
	std::vector<Vertex> vertices =
	{
		{ { -0.5f, -0.5f,  0.5f }, { 0.f, 0.f}, { 0, 0, 1, 1 } },
		{ { -0.5f,  0.5f,  0.5f }, { 0.f, 0.f}, { 1, 0, 0, 1 } },
		{ {  0.5f,  0.5f,  0.5f }, { 0.f, 0.f}, { 0, 1, 0, 1 } },
		{ {  0.5f, -0.5f,  0.5f }, { 0.f, 0.f}, { 1, 1, 0, 1 } },
		{ { -0.5f, -0.5f, -0.5f }, { 0.f, 0.f}, { 1, 1, 1, 1 } },
		{ { -0.5f,  0.5f, -0.5f }, { 0.f, 0.f}, { 1, 0, 0, 1 } },
		{ {  0.5f,  0.5f, -0.5f }, { 0.f, 0.f}, { 1, 0, 1, 1 } },
		{ {  0.5f, -0.5f, -0.5f }, { 0.f, 0.f}, { 0, 0, 1, 1 } }
	};

	std::vector<GLuint> indices =
	{
		0,2,1,  0,3,2,
		4,3,0,  4,7,3,
		4,1,5,  4,0,1,
		3,6,2,  3,7,6,
		1,6,5,  1,2,6,
		7,5,6,  7,4,5
	};
	init(vertices, indices);
}

Mesh::~Mesh(void)
{
	glDeleteBuffers(IndexCount, m_vertexBufferObject);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::init(std::vector<Vertex> const & vertices, std::vector<GLuint> const & indices)
{
	m_indiceCount = indices.size();
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);
	glGenBuffers(IndexCount, m_vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[VBOIndex::VertexIndex]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3) + sizeof(Vector2)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexBufferObject[VBOIndex::Index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "mesh " << error << std::endl;
	// Add Gl error check TODO
	glBindVertexArray(0);
}

void Mesh::draw(Shader & shader)
{
	shader.setParameter("ModelMatrix", getMatrix());
	glBindVertexArray(m_vertexArrayObject);
	glDrawElements(GL_TRIANGLES, m_indiceCount, GL_UNSIGNED_INT, (GLvoid*)0);
	glBindVertexArray(0);
}
