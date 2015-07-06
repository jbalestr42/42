#include "FrameRate.hpp"
#include "ResourcesManager.hpp"

FrameRate::FrameRate(void) :
	m_graph(NULL),
	mf_timer(0.f),
	mn_nbFrame(0)
{
	m_text.setFont(ResourcesManager::getCurrent().getFont(FONT_CHUNKFIVE_EX));
	m_text.setColor(sf::Color::Yellow);
	m_text.setPosition(15.f, 190.f);

	m_graph = new Graph(10, 100.f, 100.f);
	m_graph->setPosition(15.f, 40.f);
}

FrameRate::~FrameRate(void)
{
	if (m_graph)
		delete m_graph;
	m_graph = NULL;
}

void FrameRate::update(float pf_deltatime)
{
	mf_timer += pf_deltatime;
	mn_nbFrame++;
	if (mf_timer > 1.f)
	{
		sprintf(mp_buffer, "%d", mn_nbFrame);
		m_graph->addValue(mn_nbFrame);
		mn_nbFrame = 0;
		mf_timer = 0.f;
		m_text.setString(mp_buffer);
	}
}

void FrameRate::draw(sf::RenderTarget & p_target, sf::RenderStates p_states) const
{
	p_target.draw(m_text);
	p_target.draw(*m_graph);
}
