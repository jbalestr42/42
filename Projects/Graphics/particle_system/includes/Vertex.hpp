#ifndef VERTEX_HPP
# define VERTEX_HPP

# include <initializer_list>
# include "Color.hpp"
# include "Vector2.hpp"
# include "Vector3.hpp"


class Vertex
{
public:
	Vertex(void);
	Vertex(Vector3 const & position, Vector2 const & uv, Vector3 const & n, Color const & color);
	Vertex(Vertex const & vertex);
	~Vertex(void) = default;

	Vertex & operator=(Vertex const & vertex);

	Vector3		position;
	Vector2		uv;
	Vector3		normal;
	Color		color;

};

#endif
