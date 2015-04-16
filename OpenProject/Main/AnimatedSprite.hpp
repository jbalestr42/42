#ifndef ANIMATEDSPRITE_HPP
# define ANIMATEDSPRITE_HPP

# include "Main/Sprite.hpp"

class AnimatedSprite : public Sprite
{
private:
	float			mf_timer;
	float			mf_animationTotalDuration;
	float			mf_spriteDuration;
	int				mn_currentSprite;
	int				mn_nbSprite;
	int				mn_width;
	int				mn_height;
	int				mn_spriteId;
	sf::Vector2i	m_pos;

public:
	AnimatedSprite(void);
	AnimatedSprite(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width);
	AnimatedSprite(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width, int pn_height, sf::Vector2i const & p_pos);
	virtual ~AnimatedSprite(void);

	void init(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width);
	void init(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width, int pn_height, sf::Vector2i const & p_pos);

	void update(float pf_deltatime);

};

#endif
