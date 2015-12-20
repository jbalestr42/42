#include "Vertex.hpp"

Vertex::Vertex(void) { }

Vertex::Vertex(Vector3 const & pos, Vector2 const & u, Color const & col)
{
	position = pos;
	uv = u;
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
	color = vertex.color;
	return (*this);
}
