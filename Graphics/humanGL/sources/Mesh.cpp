#include "Mesh.hpp"
#include <iostream>
#include <cassert>

Mesh::Mesh(void) :
	Mesh(Color::Black)
{}

Mesh::Mesh(Color const & color) :
	m_vertexArrayObject(-1),
	m_indiceCount(0)
{
	for (std::size_t i = 0; i < IndexCount; i++)
		m_vertexBufferObject[i] = -1;

	// Create Cube
	std::vector<Vertex> vertices =
	{
		{ { -0.5f, -0.5f,  0.5f }, { 0.f, 0.f}, color },
		{ { -0.5f,  0.5f,  0.5f }, { 0.f, 0.f}, color },
		{ {  0.5f,  0.5f,  0.5f }, { 0.f, 0.f}, color },
		{ {  0.5f, -0.5f,  0.5f }, { 0.f, 0.f}, color },
		{ { -0.5f, -0.5f, -0.5f }, { 0.f, 0.f}, color },
		{ { -0.5f,  0.5f, -0.5f }, { 0.f, 0.f}, color },
		{ {  0.5f,  0.5f, -0.5f }, { 0.f, 0.f}, color },
		{ {  0.5f, -0.5f, -0.5f }, { 0.f, 0.f}, color }
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

	std::copy(vertices.begin(), vertices.end(), std::back_inserter(m_vertices));
	std::copy(indices.begin(), indices.end(), std::back_inserter(m_indices));
	init();
}

Mesh::Mesh(Mesh && mesh)
{
	*this = std::move(mesh);
}

Mesh::Mesh(Mesh const & mesh)
{
	*this = mesh;
}

Mesh::~Mesh(void)
{
	glDeleteBuffers(IndexCount, m_vertexBufferObject);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

Mesh & Mesh::operator=(Mesh const & mesh)
{
	m_vertices.clear();
	m_indices.clear();
	std::copy(mesh.m_vertices.begin(), mesh.m_vertices.end(), std::back_inserter(m_vertices));
	std::copy(mesh.m_indices.begin(), mesh.m_indices.end(), std::back_inserter(m_indices));
	init();
	return (*this);
}

Mesh & Mesh::operator=(Mesh && mesh)
{
	m_vertexArrayObject = mesh.m_vertexArrayObject;
	mesh.m_vertexArrayObject = -1;
	for (std::size_t i = 0u; i < IndexCount; i++)
		m_vertexBufferObject[i] = std::move(mesh.m_vertexBufferObject[i]);
	m_indiceCount = std::move(mesh.m_indiceCount);
	m_vertices.clear();
	m_indices.clear();
	std::move(mesh.m_vertices.begin(), mesh.m_vertices.end(), std::back_inserter(m_vertices));
	std::move(mesh.m_indices.begin(), mesh.m_indices.end(), std::back_inserter(m_indices));
	mesh.m_vertices.clear();
	mesh.m_indices.clear();
	return (*this);
}

void Mesh::init(void)
{
	m_indiceCount = m_indices.size();
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);
	glGenBuffers(IndexCount, m_vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[VBOIndex::VertexIndex]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3) + sizeof(Vector2)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexBufferObject[VBOIndex::Index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_indices.size(), &m_indices[0], GL_STATIC_DRAW);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "mesh " << error << std::endl;
	// Add Gl error check TODO
	glBindVertexArray(0);
}

void Mesh::draw(void)
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawElements(GL_TRIANGLES, m_indiceCount, GL_UNSIGNED_INT, (GLvoid*)0);
	glBindVertexArray(0);
}
