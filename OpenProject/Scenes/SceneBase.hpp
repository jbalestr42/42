#ifndef SCENEBASE_HPP
# define SCENEBASE_HPP

# include <SFML/Graphics.hpp>

enum EScene
{
	e_scene_noise,

	e_scene_nb
};

class ASceneBase : public sf::Drawable
{
protected:
	ASceneBase(void);
	virtual ~ASceneBase(void);
	virtual void draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const {};

public:
	virtual void init(void) = 0;
	virtual void update(float pf_Deltatime) = 0;
	virtual void pollEvent(sf::Event p_event) = 0;
};

#endif
