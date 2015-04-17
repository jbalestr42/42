#include "AnimatedSprite.hpp"
#include "ResourcesManager.hpp"

AnimatedSprite::AnimatedSprite(void) :
	mf_timer(0.0f),
	mf_animationTotalDuration(0.0f),
	mf_spriteDuration(0.0f),
	mn_currentSprite(0),
	mn_nbSprite(0),
	mn_width(0),
	mn_height(0),
	mn_spriteId(0),
	m_pos(sf::Vector2i(0, 0))
{}

AnimatedSprite::AnimatedSprite(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width) :
	mf_timer(0.0f),
	mf_animationTotalDuration(pf_animatiomTotalDuration),
	mf_spriteDuration(pf_animatiomTotalDuration / static_cast<float>(pn_nbSprite)),
	mn_currentSprite(0),
	mn_nbSprite(pn_nbSprite),
	mn_width(pn_width),
	mn_height(0),
	mn_spriteId(pn_spriteId),
	m_pos(sf::Vector2i(0, 0))
{
	setTexture(ResourcesManager::getCurrent().getTexture(pn_spriteId));
	mn_height = getTexture()->getSize().y;
	setTextureRect(sf::IntRect(m_pos.x, m_pos.y, pn_width, mn_height));
}

AnimatedSprite::AnimatedSprite(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width, int pn_height, sf::Vector2i const & p_pos) :
	mf_timer(0.0f),
	mf_animationTotalDuration(pf_animatiomTotalDuration),
	mf_spriteDuration(pf_animatiomTotalDuration / pn_nbSprite),
	mn_currentSprite(0),
	mn_nbSprite(pn_nbSprite),
	mn_width(pn_width),
	mn_height(pn_height),
	mn_spriteId(pn_spriteId),
	m_pos(p_pos)
{
	setTexture(ResourcesManager::getCurrent().getTexture(pn_spriteId));
	setTextureRect(sf::IntRect(p_pos.x, p_pos.y, pn_width, mn_height));
}

void AnimatedSprite::init(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width, int pn_height, sf::Vector2i const & p_pos)
{
	init(pn_spriteId, pf_animatiomTotalDuration, pn_nbSprite, pn_width);
	mn_height = pn_height;
	m_pos = p_pos;
}

void AnimatedSprite::init(int pn_spriteId, float pf_animatiomTotalDuration, int pn_nbSprite, int pn_width)
{
	mn_spriteId = pn_spriteId;
	mf_animationTotalDuration = pf_animatiomTotalDuration;
	mn_nbSprite = pn_nbSprite;
	mf_spriteDuration = mf_animationTotalDuration / static_cast<float>(mn_nbSprite);
	mn_width = pn_width;
	setTexture(ResourcesManager::getCurrent().getTexture(mn_spriteId));
	setTextureRect(sf::IntRect(m_pos.x, m_pos.y, mn_width, mn_height));
}

AnimatedSprite::~AnimatedSprite(void) { }

void AnimatedSprite::update(float pf_deltatime)
{
	mf_timer += pf_deltatime;

	if (mf_timer >= mf_spriteDuration)
	{
		mf_timer = 0.0f;
		mn_currentSprite = (mn_currentSprite + 1) % mn_nbSprite;
		setTextureRect(sf::IntRect(m_pos.x + mn_currentSprite * mn_width, m_pos.y, mn_width, mn_height));
	}
}
