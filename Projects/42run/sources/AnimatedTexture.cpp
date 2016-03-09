#include "AnimatedTexture.hpp"
#include "Shader.hpp"

AnimatedTexture::AnimatedTexture(std::string const & filename, Vector2 const & rectSize, float frameDuration, std::size_t frameCount) :
	Texture(filename),
	m_rectSize(rectSize),
	m_timer(0.f),
	m_frameDuration(frameDuration),
	m_frameCount(frameCount),
	m_currentFrame(0u)
{
}

AnimatedTexture::AnimatedTexture(AnimatedTexture const & animatedTexture) :
	Texture(animatedTexture)
{
	*this = animatedTexture;
}

AnimatedTexture::~AnimatedTexture(void) { }

AnimatedTexture & AnimatedTexture::operator=(AnimatedTexture const & animatedTexture)
{
	(void)animatedTexture;
	return (*this);
}

void AnimatedTexture::update(float frametime)
{
	m_timer += frametime;
	if (m_timer > m_frameDuration)
	{
		m_currentFrame++;
		m_timer -= m_frameDuration;
		if (m_currentFrame >= m_frameCount)
			m_currentFrame = 0;
	}
}

void AnimatedTexture::setCurrentFrame(std::size_t frame)
{
	m_currentFrame = frame;
}

void AnimatedTexture::bind(Shader & shader)
{
	Texture::bind(shader);
	shader.setParameter("frame_size", m_rectSize / Vector2(getWidth(), getHeight()));
	shader.setParameter("current_frame", Vector2(m_rectSize.x * m_currentFrame / getWidth(), m_rectSize.y / getHeight()));
}
