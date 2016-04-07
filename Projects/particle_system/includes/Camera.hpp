#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "Shader.hpp"
# include "Transformable.hpp"
# include <memory>

class Camera : public Transformable
{
public:
	Camera(void);
	virtual ~Camera(void);

	Matrix const & getProjection(void) const;
	Matrix const & getView(void) const;
	Matrix const & getModel(void);
	Shader & getShader(void) const;
	Vector3 unProject(Vector2 const & inPosition, float depth);

	void update(float frametime);

private:
	Matrix						m_view;
	Matrix						m_projection;
	Vector3						m_up;
	Vector3						m_target;
	Vector3						m_position;
	Vector2						m_mousePos;
	std::unique_ptr<Shader>		m_shader;

	Camera(Camera const & camera);
	Camera & operator=(Camera const & camera);

};

#endif
