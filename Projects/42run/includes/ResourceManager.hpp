#ifndef RESOURCEMANAGER_HPP
# define RESOURCEMANAGER_HPP

# include "Mesh.hpp"
# include "Texture.hpp"
# include <map>

class ResourceManager
{
public:
	virtual ~ResourceManager(void);

	static ResourceManager & getInstance(void);
	std::shared_ptr<Mesh> getMesh(std::string const & name);
	std::shared_ptr<Texture> getTexture(std::string const & name);

private:
	typedef std::map<std::string, std::shared_ptr<Mesh>>	MeshMap;
	typedef std::map<std::string, std::shared_ptr<Texture>>	TextureMap;
	MeshMap									m_meshes;
	TextureMap								m_textures;

	static std::unique_ptr<ResourceManager>	m_instance;

	ResourceManager(void);
	ResourceManager(ResourceManager const & meshManager);
	ResourceManager & operator=(ResourceManager const & meshManager);

};

#endif
