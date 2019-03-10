#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices) :
	m_Vertices(vertices), m_Indices(indices), m_ModelMatrix(1), m_Rotation(1)
{
	m_VertexArray.Bind();
	m_VertexBuffer.Bind();

	m_VertexBuffer.BufferData(m_Vertices.size() * sizeof(Vertex), m_Vertices.data(), GL_STATIC_DRAW);

	m_VertexBuffer.SetElementLayout(0, 3, sizeof(Vertex), offsetof(Vertex, position));
	m_VertexBuffer.SetElementLayout(1, 3, sizeof(Vertex), offsetof(Vertex, colour));
	m_VertexBuffer.SetElementLayout(2, 2, sizeof(Vertex), offsetof(Vertex, textureCoord));
	m_VertexBuffer.SetElementLayout(3, 3, sizeof(Vertex), offsetof(Vertex, normal));

	m_IndexBuffer.Bind();
	m_IndexBuffer.BufferData(m_Indices.size() * sizeof(GLushort), m_Indices.size(), m_Indices.data(), GL_STATIC_DRAW);
}

Mesh::~Mesh()
{
}

void Mesh::Draw()
{
	m_VertexArray.Bind();
	m_VertexArray.DrawElements(m_IndexBuffer.GetCount());
}

void Mesh::SetRotation(float angle, const glm::vec3& direction)
{
	m_Rotation = glm::rotate(glm::mat4(1), glm::radians(angle), direction);
}

void Mesh::UpdateModelMatrix()
{
	glm::mat4 translation = glm::mat4(1);
	translation = glm::translate(translation, m_Position);

	m_ModelMatrix = translation * m_Rotation;
	
	m_Rotation = glm::mat4(1);
}