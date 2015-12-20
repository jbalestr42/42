#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <vector>
# include <memory>
# include <type_traits>
# include "Matrix.hpp"
# include "Mesh.hpp"

class Shader;
class IAnimatorBase;

class Animation
{
public:
	Animation(void);
	Animation(Animation const & animation);
	Animation(Animation && animation);
	virtual ~Animation(void) = default;

	Animation & operator=(Animation const & animation);
	Animation & operator=(Animation && animation);

	//TODO
	void play(void);
	void stop(void);
	void pause(void);
	void update(float frameTime);
	void draw(Shader & shader);

	void addChild(std::unique_ptr<Animation> const & animation);
	void addChild(std::unique_ptr<Animation> && animation);
	void removeChilds(void);

	void setLoopMode(bool isLoop);
	void pushAnimator(std::unique_ptr<IAnimatorBase> const & animator);
	void pushAnimator(std::unique_ptr<IAnimatorBase> && animator);

private:
	typedef std::vector<std::unique_ptr<IAnimatorBase>>	AnimatorList;
	typedef std::vector<std::unique_ptr<Animation>>		AnimationList;

	float				m_timer;
	float				m_duration;
	bool				m_loopMode;
	AnimatorList		m_animators;
	Matrix				m_localMatrix;
	Mesh				m_mesh;
	Animation const *	m_parent;
	AnimationList		m_childs;

	void computeDuration(std::unique_ptr<IAnimatorBase> const & animator);

};

#endif
