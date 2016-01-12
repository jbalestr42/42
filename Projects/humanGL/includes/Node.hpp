#ifndef NODE_HPP
# define NODE_HPP

# include "Transformable.hpp"
# include "Animation.hpp"
# include "Mesh.hpp"

class Shader;

class Node : public Transformable
{
public:
	typedef std::unique_ptr<Animation>	AnimationPtr;
	typedef std::unique_ptr<Node>		NodePtr;
	typedef std::vector<NodePtr>		Childs;

	Node(void);
	Node(Node const & node);
	Node(Node && node);
	virtual ~Node(void) = default;

	Node & operator=(Node const & node);
	Node & operator=(Node && node);

	void play(void);
	void stop(void);
	void pause(void);

	Matrix const & getGlobalMatrix(void) const;
	void setAnimation(AnimationPtr const & animation);
	void setAnimation(AnimationPtr && animation);
	AnimationPtr const & getAnimation(void) const;
	void addChild(NodePtr const & node);
	void addChild(NodePtr && node);
	void removeChilds(void);

	void update(float frameTime);
	void draw(Shader & shader);

private:
	Node const *	m_parent;
	Childs			m_childs;
	AnimationPtr	m_animation;
	Matrix			m_globalMatrix;
	Mesh			m_mesh;

	Vector3 getParentScale(void) const;

};

#endif
