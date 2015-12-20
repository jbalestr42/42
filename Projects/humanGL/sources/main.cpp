#include "Windows.hpp"
#include "Mesh.hpp"
#include "Color.hpp"
#include "Matrix.hpp"
#include "Math.hpp"
#include "Shader.hpp"
#include "Animation.hpp"
#include "Animator.hpp"
#include <iostream>

int main(void)
{
	Windows win(800, 600, "HumanGL");
	win.setClearColor(Color::White);

	Animation	anima;
	anima.pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Rotate>(Vector3(0.f, 45.f, 0.f), 0.f, 1.f)));

	std::unique_ptr<Animation>	animChild(new Animation());
	animChild->pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Scale>(Vector3(.5f, 0.5f, 0.5f), 0.f, -1.f)));
	animChild->pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Rotate>(Vector3(45.f, 0.f, 0.f), 0.f, 1.f)));
	animChild->pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Translate>(Vector3(0.5f, 0.5f, 0.f), 0.f, -1.f)));

	std::unique_ptr<Animation>	animChildB(new Animation());
	animChildB->pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Scale>(Vector3(.25f, 0.25f, 0.25f), 0.f, -1.f)));
	animChildB->pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Rotate>(Vector3(45.f, 0.f, 0.f), 0.f, 1.f)));
	animChildB->pushAnimator(std::unique_ptr<IAnimatorBase>(new Animator<Anim::Translate>(Vector3(0.5f, 0.5f, 0.f), 0.f, -1.f)));
	animChild->addChild(std::move(animChildB));
	anima.addChild(std::move(animChild));

	Shader shader("resources/default.frag" ,"resources/default.vert");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	//glFrontFace(GL_CCW);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_FOG);
	//glDepthMask(GL_TRUE);
	//glDisable(GL_LIGHTING);
	//glDisable(GL_FOG);
	Matrix		m_view;
	Matrix		m_projection;

	m_view.identity();
	m_view.translate(Vector3(0.f, 0.f, -3.f));
	shader.setParameter("ViewMatrix", m_view);
	m_projection.identity();
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 1.f, 100.f);
	shader.setParameter("ProjectionMatrix", m_projection);

	glfwSetTime(0.f);
	float lastTime = 0.f;
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frameTime = (currentTime - lastTime);
		lastTime = currentTime;

		if (glfwGetKey(win.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			win.close();

		// Update
		anima.update(frameTime);

		// Draw
		win.clear();

		anima.draw(shader);

		win.display();
		win.pollEvents();
	}
	return (0);
}
