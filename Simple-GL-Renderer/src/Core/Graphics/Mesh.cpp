#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices)
{
	m_VertexArray.Bind();

	m_VertexBuffer.BufferData(vertices.size() * sizeof(Vertex), vertices.data());

	m_VertexBuffer.SetElementLayout(0, 3, sizeof(Vertex), 0);
	m_VertexBuffer.SetElementLayout(1, 3, sizeof(Vertex), offsetof(Vertex, colour));

	m_IndexBuffer.BufferData(indices.size() * sizeof(GLushort), indices.size(), indices.data());
}

void Mesh::Draw()
{
	m_VertexArray.Bind();
	m_VertexArray.DrawElements(m_IndexBuffer.GetCount());
}