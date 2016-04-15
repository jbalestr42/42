#include "Mesh.hpp"
#include "ResourceManager.hpp"
#include <iostream>
#include <cassert>
#include <postprocess.h>
#include <Importer.hpp>

Mesh::MeshEntry::MeshEntry(aiMesh * mesh) :
	m_indiceCount(0u),
	m_materialIndex(0u)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	for (std::size_t i = 0; i < mesh->mNumVertices; i++)
	{
		const aiVector3D * pPos = &(mesh->mVertices[i]);
		const aiVector3D * pNormal = &(mesh->mNormals[i]);
		const aiVector3D * pTexCoord = mesh->HasTextureCoords(0) ? &(mesh->mTextureCoords[0][i]) : &Zero3D;
		vertices.emplace_back(Vector3(pPos->x, pPos->y, pPos->z),
				Vector2(pTexCoord->x, pTexCoord->y),
				Vector3(pNormal->x, pNormal->y, pNormal->z),
				Color());
	}

	for (std::size_t i = 0; i < mesh->mNumFaces; i++)
	{
		const aiFace& Face = mesh->mFaces[i];
		assert(Face.mNumIndices == 3);
		indices.push_back(Face.mIndices[0]);
		indices.push_back(Face.mIndices[1]);
		indices.push_back(Face.mIndices[2]);
	}

	m_indiceCount = mesh->mNumFaces * 3;
	m_materialIndex = mesh->mMaterialIndex;
	init(vertices, indices);
}

Mesh::MeshEntry::MeshEntry(MeshEntry const & mesh)
{
	*this = mesh;
}

Mesh::MeshEntry::~MeshEntry(void)
{
	glDeleteBuffers(IndexCount, m_vertexBufferObject);
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

Mesh::MeshEntry & Mesh::MeshEntry::operator=(MeshEntry const & mesh)
{
	(void)mesh;
	return (*this);
}

std::size_t Mesh::MeshEntry::getMaterialIndex(void) const
{
	return m_materialIndex;
}

void Mesh::MeshEntry::init(std::vector<Vertex> const & vertices, std::vector<GLuint> const & indices)
{
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);
	glGenBuffers(IndexCount, m_vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[VBOIndex::VertexBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3) + sizeof(Vector2)));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3) + sizeof(Vector2) + sizeof(Vector3)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexBufferObject[VBOIndex::Index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "mesh " << error << std::endl;
	// Add Gl error check TODO
	glBindVertexArray(0);
}

void Mesh::MeshEntry::draw(void)
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawElements(GL_TRIANGLES, m_indiceCount, GL_UNSIGNED_INT, (GLvoid*)0);
	glBindVertexArray(0);
}

Mesh::Mesh(std::string const & filename)
{
	//TODO check if file exist
	Assimp::Importer Importer;
	const aiScene * pScene = Importer.ReadFile(filename.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);
	if (!pScene)
		std::cout << "error pscene" << std::endl;
	for (std::size_t i = 0; i < pScene->mNumMeshes; i++)
		m_meshEntries.emplace_back(new MeshEntry(pScene->mMeshes[i]));

	initMaterials(pScene, filename);
	Importer.FreeScene();
}

Mesh::Mesh(Mesh const & mesh)
{
	*this = mesh;
}

Mesh::~Mesh(void) { }

Mesh & Mesh::operator=(Mesh const & mesh)
{
	(void)mesh;
	return (*this);
}

void Mesh::initMaterials(aiScene const * scene, std::string const & filename)
{
	// Extract the directory part from the file name
	std::string::size_type slashIndex = filename.find_last_of("/");
	std::string dirPath;
	std::string fullPath;

	if (slashIndex == std::string::npos)
		dirPath = ".";
	else if (slashIndex == 0)
		dirPath = "/";
	else
		dirPath = filename.substr(0, slashIndex);

	// Initialize the materials
	for (unsigned int i = 0 ; i < scene->mNumMaterials ; i++)
	{
		const aiMaterial* pMaterial = scene->mMaterials[i];

		if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0)
		{
			aiString path;
			if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS)
			{
				std::string fullPath = dirPath + "/" + path.data;
				m_textures.push_back(ResourceManager::getInstance().getTexture(fullPath));
			}
			else
				std::cout << "Error while loading texture : " << fullPath << std::endl;
		}
		else
			m_textures.push_back(ResourceManager::getInstance().getTexture("resources/nyan.bmp"));
	}
}

void Mesh::draw(void)
{
	for (auto & mesh : m_meshEntries)
	{
		if (mesh->getMaterialIndex() < m_textures.size() && mesh->getMaterialIndex())
		{
			m_textures[mesh->getMaterialIndex()]->bind(GL_TEXTURE0, GL_TEXTURE_2D);
		}
		mesh->draw();
	}
}
