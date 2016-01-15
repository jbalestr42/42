#include "Windows.hpp"
#include "Mesh.hpp"
#include "Color.hpp"
#include "Matrix.hpp"
#include "Math.hpp"
#include "Shader.hpp"
#include "Animation.hpp"
#include "AddAnimator.hpp"
#include "SetAnimator.hpp"
#include "LerpAnimator.hpp"
#include "CerpAnimator.hpp"
#include "Node.hpp"
#include "Keyboard.hpp"
#include <iostream>

Node::NodePtr createMan(void)
{
	std::unique_ptr<Animation>	trunkAnim(new Animation());
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.f, 0.f, 0.f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.1f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateY>(45.f, 0.f, 4.f)));

	std::unique_ptr<Animation>	armRightAnim(new Animation());
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.5f, 0.45f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.f, 0.f, -90.f), 0.f)));

	std::unique_ptr<Animation>	armLeftAnim(new Animation());
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.5f, 0.45f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.f, 0.f, 90.f), 0.f)));

	std::unique_ptr<Animation>	subArmLeftAnim(new Animation());
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.5f, 0.0f), 0.f)));

	std::unique_ptr<Animation>	legLeftAnim(new Animation());
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.3f, -0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), 0.f)));

	std::unique_ptr<Animation>	subLegLeftAnim(new Animation());
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), 1.f)));

	std::unique_ptr<Animation>	legRightAnim(new Animation());
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.3f, -0.5f, 0.0f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), 0.f)));

	std::unique_ptr<Animation>	headAnim(new Animation());
	headAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.5f, 0.25f, 1.2f), 0.f)));
	headAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.63f, 0.f), 0.f)));

	Node::NodePtr trunk(new Node());
	trunk->setAnimation(std::move(trunkAnim));

	Node::NodePtr armLeft(new Node());
	armLeft->setAnimation(std::move(armLeftAnim));

	Node::NodePtr subArmLeft(new Node());
	subArmLeft->setAnimation(std::move(subArmLeftAnim));

	Node::NodePtr armRight(new Node());
	armRight->setAnimation(std::move(armRightAnim));

	Node::NodePtr legLeft(new Node());
	legLeft->setAnimation(std::move(legLeftAnim));

	Node::NodePtr subLegLeft(new Node());
	subLegLeft->setAnimation(std::move(subLegLeftAnim));

	Node::NodePtr legRight(new Node());
	legRight->setAnimation(std::move(legRightAnim));

	Node::NodePtr head(new Node());
	head->setAnimation(std::move(headAnim));

	armRight->addChild(subArmLeft);
	armLeft->addChild(std::move(subArmLeft));
	legRight->addChild(subLegLeft);
	legLeft->addChild(std::move(subLegLeft));
	trunk->addChild(std::move(armLeft));
	trunk->addChild(std::move(armRight));
	trunk->addChild(std::move(legLeft));
	trunk->addChild(std::move(legRight));
	trunk->addChild(std::move(head));

	return (trunk);
}

Node::NodePtr createManWalk(void)
{
	std::unique_ptr<Animation>	trunkAnim(new Animation());
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.f, 0.f, 0.f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.1f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateY>(45.f, 0.f, 4.f)));

	std::unique_ptr<Animation>	armRightAnim(new Animation());
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.62f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(-Vector3(135.f, 0.f, 0.f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(145.0f, 0.0f, 0.0f), Vector3(215.f, 0.f, 0.f), 0.f, 1.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(215.0f, 0.0f, 0.0f), Vector3(145.f, 0.f, 0.f), 1.f, 1.f)));

	std::unique_ptr<Animation>	armLeftAnim(new Animation());
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.62f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(135.f, 0.f, 0.f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(215.0f, 0.0f, 0.0f), Vector3(145.f, 0.f, 0.f), 0.f, 1.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(145.0f, 0.0f, 0.0f), Vector3(215.f, 0.f, 0.f), 1.f, 1.f)));

	std::unique_ptr<Animation>	subArmLeftAnim(new Animation());
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(45.0f, 0.0f, 0.0f), 0.f)));

	std::unique_ptr<Animation>	legLeftAnim(new Animation());
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.3f, -0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new LerpAnimator<Anim::Rotate>(Vector3(145.0f, 0.0f, 0.0f), Vector3(215.f, 0.f, 0.f), 0.f, 1.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(215.0f, 0.0f, 0.0f), Vector3(145.f, 0.f, 0.f), 1.f, 1.f)));

	std::unique_ptr<Animation>	subLegLeftAnim(new Animation());
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(-25.f, 0.f, 0.f), 0.f, 0.5f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(-25.0f, 0.0f, 0.0f), Vector3(0.f, 0.f, 0.f), 0.5f, 0.5f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), 1.f, 1.f)));

	std::unique_ptr<Animation>	legRightAnim(new Animation());
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.3f, -0.5f, 0.0f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(215.0f, 0.0f, 0.0f), Vector3(145.f, 0.f, 0.f), 0.f, 1.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new LerpAnimator<Anim::Rotate>(Vector3(145.0f, 0.0f, 0.0f), Vector3(215.f, 0.f, 0.f), 1.f, 1.f)));

	std::unique_ptr<Animation>	subLegRightAnim(new Animation());
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), 0.f, 0.5f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(-25.f, 0.f, 0.f), 0.5f, 1.f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(-25.0f, 0.0f, 0.0f), Vector3(0.f, 0.f, 0.f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	headAnim(new Animation());
	headAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.5f, 0.25f, 1.2f), 0.f)));
	headAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.63f, 0.f), 0.f)));

	Node::NodePtr trunk(new Node());
	trunk->setAnimation(std::move(trunkAnim));

	Node::NodePtr armLeft(new Node());
	armLeft->setAnimation(std::move(armLeftAnim));

	Node::NodePtr subArmLeft(new Node());
	subArmLeft->setAnimation(std::move(subArmLeftAnim));

	Node::NodePtr armRight(new Node());
	armRight->setAnimation(std::move(armRightAnim));

	Node::NodePtr legLeft(new Node());
	legLeft->setAnimation(std::move(legLeftAnim));

	Node::NodePtr subLegLeft(new Node());
	subLegLeft->setAnimation(std::move(subLegLeftAnim));

	Node::NodePtr legRight(new Node());
	legRight->setAnimation(std::move(legRightAnim));

	Node::NodePtr subLegRight(new Node());
	subLegRight->setAnimation(std::move(subLegRightAnim));

	Node::NodePtr head(new Node());
	head->setAnimation(std::move(headAnim));

	armRight->addChild(subArmLeft);
	armLeft->addChild(std::move(subArmLeft));
	legRight->addChild(std::move(subLegRight));
	legLeft->addChild(std::move(subLegLeft));
	trunk->addChild(std::move(armLeft));
	trunk->addChild(std::move(armRight));
	trunk->addChild(std::move(legLeft));
	trunk->addChild(std::move(legRight));
	trunk->addChild(std::move(head));

	return (trunk);
}

Node::NodePtr createMonkeyWalk(void)
{
	Node::NodePtr trunk = createManWalk();

	std::unique_ptr<Animation>	tailAnim(new Animation());
	tailAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	tailAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.25f, 0.25f), 0.f)));
	tailAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, -0.5f, -0.5f), 0.f)));
	tailAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(25.f, 0.f, 0.f), 0.f)));

	std::unique_ptr<Animation>	tailPieceAnim(new Animation());
	tailPieceAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	tailPieceAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.5f, 0.0f), 0.f)));
	tailPieceAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(35.f, 0.f, 0.f), 0.f)));
	tailPieceAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::Rotate>(Vector3(5.f, 0.f, 0.f), 0.f, 2.f)));
	tailPieceAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::Rotate>(Vector3(-5.f, 0.f, 0.f), 2.f, 2.f)));

	Node::NodePtr tail(new Node());
	tail->setAnimation(std::move(tailAnim));

	Node::NodePtr tailPiece(new Node());
	tailPiece->setAnimation(std::move(tailPieceAnim));

	tailPiece->addChild(tailPiece);
	tailPiece->addChild(tailPiece);
	tailPiece->addChild(tailPiece);
	tailPiece->addChild(tailPiece);
	tail->addChild(tailPiece);
	trunk->addChild(std::move(tail));

	return (trunk);
}

Node::NodePtr createManJump(void)
{
	std::unique_ptr<Animation>	trunkAnim(new Animation());
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.f, 45.f, 0.f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.1f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateY>(45.f, 0.f, 2.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Translate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.f, -0.18f, 0.f), 0.f, 1.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Translate>(Vector3(0.0f, -0.18f, 0.0f), Vector3(0.f, 0.45f, 0.f), 1.f, 0.5f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Translate>(Vector3(0.0f, 0.45f, 0.0f), Vector3(0.f, 0.f, 0.f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	armRightAnim(new Animation());
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.62f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), Vector3(125.f, 0.f, 0.f), 0.f, 1.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(125.0f, 0.0f, 0.0f), Vector3(350.f, 0.f, 0.f), 1.f, 0.5f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(350.0f, 0.0f, 0.0f), Vector3(180.f, 0.f, 0.f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	armLeftAnim(new Animation());
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.62f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), Vector3(125.f, 0.f, 0.f), 0.f, 1.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(125.0f, 0.0f, 0.0f), Vector3(350.f, 0.f, 0.f), 1.f, 0.5f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(350.0f, 0.0f, 0.0f), Vector3(180.f, 0.f, 0.f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	subArmLeftAnim(new Animation());
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(85.f, 0.f, 0.f), 0.f, 1.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(85.0f, 0.0f, 0.0f), Vector3(0.f, 0.f, 0.f), 1.f, 0.5f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(85.f, 0.f, 0.f), 1.5f, 0.25f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(85.0f, 0.0f, 0.0f), Vector3(0.f, 0.f, 0.f), 1.75f, 0.25f)));

	std::unique_ptr<Animation>	legLeftAnim(new Animation());
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.3f, -0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), Vector3(235.f, 0.f, 0.f), 0.f, 1.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(235.0f, 0.0f, 0.0f), Vector3(180.f, 0.f, 0.f), 1.f, 0.5f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	legRightAnim(new Animation());
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.3f, -0.5f, 0.0f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), Vector3(235.f, 0.f, 0.f), 0.f, 1.f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(235.0f, 0.0f, 0.0f), Vector3(180.f, 0.f, 0.f), 1.f, 0.5f)));
	legRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(180.0f, 0.0f, 0.0f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	subLegRightAnim(new Animation());
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), 0.f, 0.5f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(-85.f, 0.f, 0.f), 0.f, 1.f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(-85.0f, 0.0f, 0.0f), Vector3(0.f, 0.f, 0.f), 1.f, 0.5f)));
	subLegRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), 1.5f, 0.5f)));

	std::unique_ptr<Animation>	headAnim(new Animation());
	headAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.5f, 0.25f, 1.2f), 0.f)));
	headAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.63f, 0.f), 0.f)));

	Node::NodePtr trunk(new Node());
	trunk->setAnimation(std::move(trunkAnim));

	Node::NodePtr armLeft(new Node());
	armLeft->setAnimation(std::move(armLeftAnim));

	Node::NodePtr subArmLeft(new Node());
	subArmLeft->setAnimation(std::move(subArmLeftAnim));

	Node::NodePtr armRight(new Node());
	armRight->setAnimation(std::move(armRightAnim));

	Node::NodePtr legLeft(new Node());
	legLeft->setAnimation(std::move(legLeftAnim));

	Node::NodePtr legRight(new Node());
	legRight->setAnimation(std::move(legRightAnim));

	Node::NodePtr subLegRight(new Node());
	subLegRight->setAnimation(std::move(subLegRightAnim));

	Node::NodePtr head(new Node());
	head->setAnimation(std::move(headAnim));

	armRight->addChild(subArmLeft);
	armLeft->addChild(std::move(subArmLeft));
	legRight->addChild(subLegRight);
	legLeft->addChild(std::move(subLegRight));
	trunk->addChild(std::move(armLeft));
	trunk->addChild(std::move(armRight));
	trunk->addChild(std::move(legLeft));
	trunk->addChild(std::move(legRight));
	trunk->addChild(std::move(head));

	return (trunk);
}

int main(void)
{
	Windows win(800, 600, "OpenGL");
	win.setClearColor(Color::White);

	std::size_t index = 0;
	std::vector<Node::NodePtr> animations;
	animations.push_back(createMan());
	animations.push_back(createManWalk());
	animations.push_back(createMonkeyWalk());
	animations.push_back(createManJump());

	Shader shader("resources/default.frag" ,"resources/default.vert");
	Matrix m_view;
	Matrix m_projection;
	m_view.translate(Vector3(0.f, 0.f, -3.f));
	shader.setParameter("ViewMatrix", m_view);
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 0.1f, 100.f);
	shader.setParameter("ProjectionMatrix", m_projection);

	glfwSetTime(0.f);
	float lastTime = 0.f;
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frameTime = (currentTime - lastTime);
		lastTime = currentTime;

		if (Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
			win.close();

		if (Keyboard::isKeyPressed(GLFW_KEY_A))
			animations[index]->play();

		if (Keyboard::isKeyPressed(GLFW_KEY_Z))
			animations[index]->pause();

		if (Keyboard::isKeyPressed(GLFW_KEY_E))
			animations[index]->stop();

		if (Keyboard::isKeyPressed(GLFW_KEY_LEFT))
			index = index == 0 ? animations.size() - 1 : index - 1;

		if (Keyboard::isKeyPressed(GLFW_KEY_RIGHT))
			index = (index + 1) % animations.size();

		// Update
		animations[index]->update(frameTime);

		// Draw
		win.clear();

		animations[index]->draw(shader);

		win.display();
		win.pollEvents();
	}
	return (0);
}
