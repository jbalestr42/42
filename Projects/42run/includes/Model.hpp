#ifndef MODEL_HPP
# define MODEL_HPP

# include "Transformable.hpp"
# include "Mesh.hpp"
# include "Texture.hpp"
# include <memory>

class Shader;

class Model : public Transformable
{
public:
	Model(void);
	Model(std::string const & meshName, std::string const & textureName);
	virtual ~Model(void) = default;

	void setTexture(Texture * texture);
	void setMesh(Mesh * mesh);

	virtual void draw(Shader & shader);

protected:
	Model(Model const & model);
	Model & operator=(Model const & model);

private:
	std::unique_ptr<Mesh>		m_mesh;
	std::unique_ptr<Texture>	m_texture;

};

#endif
