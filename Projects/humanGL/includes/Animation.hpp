#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <vector>
# include <memory>
# include "Matrix.hpp"

class IAnimatorBase;
class Transformable;

class Animation
{
	enum State
	{
		Play,
		Pause,
		Stop
	};

public:
	typedef std::unique_ptr<IAnimatorBase>	AnimatorPtr;
	typedef std::vector<AnimatorPtr>		Animators;

	Animation(void);
	Animation(Animation const & animation);
	Animation(Animation && animation);
	virtual ~Animation(void) = default;

	Animation & operator=(Animation const & animation);
	Animation & operator=(Animation && animation);

	void play(void);
	void stop(void);
	void pause(void);
	void update(float frameTime);

	void setTransformable(Transformable * transformable);
	void setLoopMode(bool loopMode);
	void pushAnimator(AnimatorPtr const & animator);
	void pushAnimator(AnimatorPtr && animator);
	void removeAnimators(void);

private:
	float					m_timer;
	float					m_duration;
	bool					m_loopMode;
	Animators				m_animators;
	State					m_state;
	Transformable *			m_transformable;

	void computeDuration(std::unique_ptr<IAnimatorBase> const & animator);

};

#endif
