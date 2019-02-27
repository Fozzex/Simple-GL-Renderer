#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices) :
	m_Vertices(vertices), m_Indices(indices)
{
	
}

Mesh::~Mesh()
{
	delete m_VertexBuffer;
	delete m_IndexBuffer;
}

void Mesh::LayoutElements(const VertexBuffer* buffer)
{
	buffer->SetElementLayout(0, 3, sizeof(Vertex), 0);
	buffer->SetElementLayout(1, 3, sizeof(Vertex), offsetof(Vertex, colour));
}