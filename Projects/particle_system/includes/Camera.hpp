#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "Matrix.hpp"
# include "Shader.hpp"
# include <memory>

class Camera
{
public:
	Camera(void);
	virtual ~Camera(void);

	Matrix const & getProjection(void) const;
	Matrix const & getView(void) const;
	Matrix const & getModel(void) const;
	Vector3 unProject(Vector2 const & inPosition, float depth);

private:
	Matrix						m_view;
	Matrix						m_projection;
	Matrix						m_model;
	std::unique_ptr<Shader>		m_shader;

	Camera(Camera const & camera);
	Camera & operator=(Camera const & camera);

};

#endif
