#include "Animation.hpp"
#include "IAnimatorBase.hpp"
#include "Transformable.hpp"

Animation::Animation(void) :
	m_timer(0.f),
	m_duration(0.f),
	m_loopMode(true),
	m_state(State::Play),
	m_transformable(nullptr)
{ }

Animation::Animation(Animation const & animation)
{
	*this = animation;
}

Animation::Animation(Animation && animation)
{
	*this = std::move(animation);
}

Animation & Animation::operator=(Animation const & animation)
{
	m_timer = animation.m_timer;
	m_duration = animation.m_duration;
	m_loopMode = animation.m_loopMode;
	removeAnimators();
	for (auto & it : animation.m_animators)
		pushAnimator(it);
	m_state = animation.m_state;
	setTransformable(animation.m_transformable);
	return (*this);
}

Animation & Animation::operator=(Animation && animation)
{
	m_timer = animation.m_timer;
	m_duration = animation.m_duration;
	m_loopMode = animation.m_loopMode;
	removeAnimators();
	std::move(animation.m_animators.begin(), animation.m_animators.end(), std::back_inserter(m_animators));
	m_state = animation.m_state;
	setTransformable(animation.m_transformable);
	animation.removeAnimators();
	animation.m_transformable = nullptr;
	return (*this);
}

void Animation::play(void)
{
	m_state = State::Play;
}

void Animation::stop(void)
{
	m_state = State::Stop;
	m_timer = 0.f;
	for (auto & it : m_animators)
		it->restart();
}

void Animation::pause(void)
{
	m_state = State::Pause;
}

void Animation::update(float frameTime)
{
	if (m_state == State::Play)
	{
		m_timer += frameTime;
		if (m_timer > m_duration)
		{
			if (m_loopMode)
				m_timer -= m_duration;
			else
				m_state = State::Stop;
		}
		for (auto & it : m_animators)
		{
			if (m_transformable)
				it->update(m_timer, frameTime, *m_transformable);
		}
	}
}

void Animation::setTransformable(Transformable * transformable)
{
	m_transformable = transformable;
}

void Animation::setLoopMode(bool loopMode)
{
	m_loopMode = loopMode;
}

void Animation::pushAnimator(AnimatorPtr const & animator)
{
	computeDuration(animator);
	pushAnimator(std::move(AnimatorPtr(animator->clone())));
}

void Animation::pushAnimator(AnimatorPtr && animator)
{
	computeDuration(animator);
	m_animators.push_back(std::move(animator));
}

void Animation::computeDuration(std::unique_ptr<IAnimatorBase> const & animator)
{
	if (animator->getTimerEnd() > m_duration)
		m_duration = animator->getTimerEnd();
}

void Animation::removeAnimators(void)
{
	m_animators.clear();
}
