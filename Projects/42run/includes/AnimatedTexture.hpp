#ifndef ANIMATEDTEXTURE_HPP
# define ANIMATEDTEXTURE_HPP

# include "Texture.hpp"
# include "Vector2.hpp"

class AnimatedTexture : public Texture
{
public:
	AnimatedTexture(std::string const & filename, Vector2 const & rectSize, float frameDuration, std::size_t frameCount);
	virtual ~AnimatedTexture(void);

	void update(float frametime);
	void bind(Shader & shader);
	void bind(GLenum textureUnit, GLenum textureTarget);

	void setCurrentFrame(std::size_t frame);

private:
	Vector2		m_rectSize;
	float		m_timer;
	float		m_frameDuration;
	std::size_t	m_frameCount;
	std::size_t	m_currentFrame;

	AnimatedTexture(void) = delete;
	AnimatedTexture(AnimatedTexture const & animatedTexture);
	AnimatedTexture & operator=(AnimatedTexture const & animatedTexture);

};

#endif
