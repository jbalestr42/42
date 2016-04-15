#ifndef TRANSFORMABLE_HPP
# define TRANSFORMABLE_HPP

# include <list>
# include "Matrix.hpp"

class Transformable
{
public:
	Transformable(void);
	Transformable(Transformable const & transformable);
	Transformable(Transformable && transformable);
	virtual ~Transformable(void) = default;

	Transformable & operator=(Transformable const & transformable);
	Transformable & operator=(Transformable && transformable);

	void setOrigin(Vector3 const & origin);
	void setPosition(Vector3 const & position);
	void setRotation(Vector3 const & rotation);
	void setScale(Vector3 const & scale);
	void setParentScale(Vector3 const & parentScale);

	Vector3 const & getOrigin(void) const;
	Vector3 const & getPosition(void) const;
	Vector3 const & getRotation(void) const;
	Vector3 const & getScale(void) const;
	Vector3 const & getParentScale(void) const;

	void translate(Vector3 const & translation);
	void rotate(Vector3 const & rotation);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	void scale(Vector3 const & scale);

	void setEulerOrder(Matrix::EulerOrder order);
	Matrix const & getMatrix(void);

private:
	Vector3				m_origin;
	Vector3				m_position;
	Vector3				m_rotation;
	Vector3				m_scale;
	Vector3				m_parentScale;
	Matrix				m_model;
	Matrix::EulerOrder	m_eulerOrder;
	bool				m_needRecompute;

};

#endif
