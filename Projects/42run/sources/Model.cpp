#include "Model.hpp"
#include "Shader.hpp"

Model::Model(void) :
	Transformable(),
	m_mesh(nullptr),
	m_texture(nullptr)
{
}

Model::Model(std::string const & meshName, std::string const & textureName) :
	Transformable(),
	m_mesh(nullptr),
	m_texture(nullptr)
{
	m_mesh.reset(new Mesh(meshName));
	m_texture.reset(new Texture(textureName));
}

Model::Model(Model const & model) :
	Transformable(model)
{
	*this = model;
}

Model & Model::operator=(Model const & model)
{
	(void)model;
	return (*this);
}

void Model::setTexture(Texture * texture)
{
	m_texture.reset(texture);
}

void Model::setMesh(Mesh * mesh)
{
	m_mesh.reset(mesh);
}

void Model::draw(Shader & shader)
{
	m_texture->bind(shader);
	shader.setParameter("ModelMatrix", getMatrix());
	m_mesh->draw();
}
