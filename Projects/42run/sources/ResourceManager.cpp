#include "ResourceManager.hpp"

std::unique_ptr<ResourceManager> ResourceManager::m_instance = nullptr;

ResourceManager::ResourceManager(void)
{
	ilInit();
}

ResourceManager::ResourceManager(ResourceManager const & meshManager)
{
	*this = meshManager;
}

ResourceManager::~ResourceManager(void) { }

ResourceManager & ResourceManager::operator=(ResourceManager const & meshManager)
{
	(void)meshManager;
	return (*this);
}

ResourceManager & ResourceManager::getInstance(void)
{
	if (m_instance == nullptr)
		m_instance.reset(new ResourceManager());
	return *m_instance;
}

std::shared_ptr<Mesh> ResourceManager::getMesh(std::string const & name)
{
	auto it = m_meshes.find(name);
	if (it != m_meshes.end())
		return it->second;
	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(name);
	m_meshes[name] = mesh;
	std::cout << "Add new mesh : " << name << std::endl;
	return (mesh);
}

std::shared_ptr<Texture> ResourceManager::getTexture(std::string const & name)
{
	auto it = m_textures.find(name);
	if (it != m_textures.end())
		return it->second;
	std::shared_ptr<Texture> texture = std::make_shared<Texture>(name);
	m_textures[name] = texture;
	std::cout << "Add new texture : " << name << std::endl;
	return (texture);
}
