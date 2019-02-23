#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices) :
	m_Vertices(vertices), m_Indices(indices)
{
	GLCall(glGenVertexArrays(1, &m_VertexArray));
	GLCall(glGenBuffers(1, &m_VertexBuffer));
	GLCall(glGenBuffers(1, &m_IndexBuffer));

	GLCall(glBindVertexArray(m_VertexArray));

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), m_Vertices.data(), GL_STATIC_DRAW));

	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0));
	GLCall(glEnableVertexAttribArray(0));

	GLCall(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour)));
	GLCall(glEnableVertexAttribArray(1));

	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(GLushort), m_Indices.data(), GL_STATIC_DRAW));
}

void Mesh::Draw() const
{
	GLCall(glBindVertexArray(m_VertexArray));
	GLCall(glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_SHORT, nullptr));
}