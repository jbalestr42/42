#include "Animation.hpp"
#include "IAnimatorBase.hpp"
#include "Shader.hpp"

Animation::Animation(void) :
	m_timer(0.f),
	m_duration(0.f),
	m_loopMode(true),
	m_parent(nullptr)
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
	m_animators.clear();
	for (auto & it : animation.m_animators)
		pushAnimator(it);
	m_localMatrix = animation.m_localMatrix;
	m_mesh = animation.m_mesh;
	m_parent = animation.m_parent;
	removeChilds();
	for (auto & it : animation.m_childs)
		addChild(it);
	return (*this);
}

Animation & Animation::operator=(Animation && animation)
{
	m_timer = animation.m_timer;
	m_duration = animation.m_duration;
	m_loopMode = animation.m_loopMode;
	m_animators.clear();
	std::move(animation.m_animators.begin(), animation.m_animators.end(), std::back_inserter(m_animators));
	animation.m_animators.clear();
	m_localMatrix = animation.m_localMatrix;
	m_mesh = std::move(animation.m_mesh);
	m_parent = animation.m_parent;
	animation.m_parent = nullptr;
	removeChilds();
	std::move(animation.m_childs.begin(), animation.m_childs.end(), std::back_inserter(m_childs));
	animation.removeChilds();
	return (*this);
}

void Animation::update(float frameTime)
{
	m_timer += frameTime;
	if (m_timer > m_duration)
	{
		if (m_loopMode)
			m_timer -= m_duration;
	}
	m_localMatrix.identity();
	for (auto & it : m_animators)
	{
		it->update(m_timer, frameTime);
		m_localMatrix.multiply(it->getMatrix());
	}
	if (m_parent)
		m_localMatrix.multiply(m_parent->m_localMatrix);
	for (auto & child : m_childs)
		child->update(frameTime);
}

void Animation::draw(Shader & shader)
{
	shader.setParameter("ModelMatrix", m_localMatrix);
	m_mesh.draw();
	for (auto & it : m_childs)
		it->draw(shader);
}

void Animation::addChild(std::unique_ptr<Animation> const & animation)
{
	m_childs.emplace_back(new Animation(*animation));
}

void Animation::addChild(std::unique_ptr<Animation> && animation)
{
	animation->m_parent = this;
	m_childs.push_back(std::move(animation));
}

void Animation::removeChilds(void)
{
	m_childs.clear();
}

void Animation::pushAnimator(std::unique_ptr<IAnimatorBase> const & animator)
{
	computeDuration(animator);
	m_animators.emplace_back(animator->clone());
}

void Animation::pushAnimator(std::unique_ptr<IAnimatorBase> && animator)
{
	computeDuration(animator);
	m_animators.push_back(std::move(animator));
}

void Animation::computeDuration(std::unique_ptr<IAnimatorBase> const & animator)
{
	if (animator->getTimerEnd() > m_duration)
		m_duration = animator->getTimerEnd();
}
