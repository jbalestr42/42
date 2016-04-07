#ifndef HUD_HPP
# define HUD_HPP

# include "Transformable.hpp"
# include "Mesh.hpp"
# include "AnimatedTexture.hpp"
# include <memory>

class HUD : public Transformable
{
public:
	HUD(void);
	virtual ~HUD(void);

	void addScore(std::size_t score);
	std::size_t getScore(void) const;

	void draw(Shader & shader);
	void drawNumber(Shader & shader, int score, int depth);

private:
	std::unique_ptr<Mesh>				m_mesh;
	std::size_t							m_score;
	std::vector<std::shared_ptr<AnimatedTexture>>	m_texture;

	HUD(HUD const & hUD);
	HUD & operator=(HUD const & hUD);

};

#endif
