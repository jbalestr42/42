#include "Node.hpp"
#include "IAnimatorBase.hpp"
#include "Shader.hpp"
#include <iostream>

Node::Node(void) :
	Transformable(),
	m_parent(nullptr),
	m_animation(nullptr)
{ }

Node::Node(Node const & node) :
	Transformable(node)
{
	*this = node;
}

Node::Node(Node && node) :
	Transformable(std::move(node))
{
	*this = std::move(node);
}

Node & Node::operator=(Node const & node)
{
	Transformable::operator=(node);
	m_parent = node.m_parent;
	removeChilds();
	for (auto & it : node.m_childs)
		addChild(it);
	setAnimation(node.m_animation);
	m_globalMatrix = node.m_globalMatrix;
	m_mesh = node.m_mesh;
	return (*this);
}

Node & Node::operator=(Node && node)
{
	Transformable::operator=(std::move(node));
	m_parent = node.m_parent;
	removeChilds();
	std::move(node.m_childs.begin(), node.m_childs.end(), std::back_inserter(m_childs));
	setAnimation(std::move(node.m_animation));
	m_globalMatrix = std::move(node.m_globalMatrix);
	m_mesh = std::move(node.m_mesh);
	node.m_parent = nullptr;
	node.removeChilds();
	node.m_animation = nullptr;
	return (*this);
}

void Node::play(void)
{
	if (m_animation)
		m_animation->play();
	for (auto & child : m_childs)
		child->play();
}

void Node::stop(void)
{
	if (m_animation)
		m_animation->stop();
	for (auto & child : m_childs)
		child->stop();
}

void Node::pause(void)
{
	if (m_animation)
		m_animation->pause();
	for (auto & child : m_childs)
		child->pause();
}

Matrix const & Node::getGlobalMatrix(void) const
{
	return m_globalMatrix;
}

void Node::setAnimation(AnimationPtr const & animation)
{
	setAnimation(std::move(AnimationPtr(new Animation(*animation))));
}

void Node::setAnimation(AnimationPtr && animation)
{
	m_animation = std::move(animation);
	m_animation->setTransformable(this);
}

Node::AnimationPtr const & Node::getAnimation(void) const
{
	return m_animation;
}

void Node::addChild(NodePtr const & node)
{
	addChild(std::move(NodePtr(new Node(*node))));
}

void Node::addChild(NodePtr && node)
{
	node->m_parent = this;
	m_childs.push_back(std::move(node));
}

void Node::removeChilds(void)
{
	m_childs.clear();
}

void Node::update(float frameTime)
{
	if (m_animation)
		m_animation->update(frameTime);
	if (m_parent)
	{
		setParentScale(m_parent->getParentScale());
		m_globalMatrix = getMatrix() * m_parent->getGlobalMatrix();
	}
	else
		m_globalMatrix = getMatrix();
	for (auto & child : m_childs)
		child->update(frameTime);
}

void Node::draw(Shader & shader)
{
	shader.setParameter("ModelMatrix", m_globalMatrix);
	m_mesh.draw();
	for (auto & it : m_childs)
		it->draw(shader);
}

Vector3 Node::getParentScale(void) const
{
	if (m_parent)
		return getScale() * m_parent->getParentScale();
	return getScale();
}
