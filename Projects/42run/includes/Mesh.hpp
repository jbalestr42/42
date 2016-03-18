#ifndef MESH_HPP
# define MESH_HPP

# include <GL/glew.h>
# include <vector>
# include <memory>
# include <scene.h>
# include "Vertex.hpp"
# include "Texture.hpp"

class Mesh
{
public:
	class MeshEntry
	{
	public:
		MeshEntry(void) = delete;
		MeshEntry(aiMesh * mesh);
		virtual ~MeshEntry(void);

		std::size_t getMaterialIndex(void) const;
		void draw(void);

	private:
		static const std::size_t IndexCount = 2;
		enum VBOIndex : std::size_t
		{
			VertexBuffer = 0,
			Index = 1
		};

		GLuint				m_vertexArrayObject;
		GLuint				m_vertexBufferObject[IndexCount];
		std::size_t			m_indiceCount;
		std::size_t			m_materialIndex;

		void init(std::vector<Vertex> const & vertices, std::vector<GLuint> const & indices);

		MeshEntry(MeshEntry const & mesh);
		MeshEntry & operator=(MeshEntry const & mesh);
	};

	Mesh(void) = delete;
	Mesh(std::string const & filename);
	Mesh(Mesh const & mesh);
	Mesh(Mesh && mesh);
	virtual ~Mesh(void);

	Mesh & operator=(Mesh const & mesh);

	void draw(void);

private:
	std::vector<std::unique_ptr<MeshEntry>>		m_meshEntries;
	std::vector<std::shared_ptr<Texture>>		m_textures;

	void initMaterials(aiScene const * scene, std::string const & filename);
};

#endif
