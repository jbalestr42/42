#include "Vertex.hpp"

Vertex::Vertex(void) { }

Vertex::Vertex(Vector3 const & pos, Vector2 const & u, Vector3 const & n, Color const & col)
{
	position = pos;
	uv = u;
	normal = n;
	color = col;
}

Vertex::Vertex(Vertex const & vertex)
{
	*this = vertex;
}

Vertex & Vertex::operator=(Vertex const & vertex)
{
	position = vertex.position;
	uv = vertex.uv;
	normal = vertex.normal;
	color = vertex.color;
	return (*this);
}
