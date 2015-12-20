#ifndef TRANSFORMABLE_HPP
# define TRANSFORMABLE_HPP

# include <list>
# include "Matrix.hpp"

class Mesh;

class Transformable
{
public:
	Transformable(void);
	Transformable(Transformable const & transformable) = delete;
	virtual ~Transformable(void) = default;

	Transformable & operator=(Transformable const & transformable) = delete;

	void setPosition(Vector3 const & position);
	void setRotation(Vector3 const & rotation);
	void setScale(Vector3 const & scale);
	void translate(Vector3 const & translation);
	void rotate(Vector3 const & rotation);
	void scale(Vector3 const & scale);

	void setEulerOrder(Matrix::EulerOrder order);
	Matrix const & getMatrix(void);

private:
	Vector3				m_position;
	Vector3				m_rotation;
	Vector3				m_scale;
	Matrix				m_model;
	Matrix::EulerOrder	m_eulerOrder;
	bool				m_needRecompute;

	Mesh				*m_parent;
	std::list<Mesh*>	m_childs;

};

#endif
