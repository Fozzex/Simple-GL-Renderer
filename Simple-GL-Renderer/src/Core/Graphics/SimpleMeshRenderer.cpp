#include "SimpleMeshRenderer.h"

SimpleMeshRenderer::SimpleMeshRenderer()
{

}

SimpleMeshRenderer::~SimpleMeshRenderer()
{

}

void SimpleMeshRenderer::Submit(Mesh* mesh)
{
	mesh->GetVertexArray()->Bind();

	VertexBuffer* vertexBuffer = new VertexBuffer();
	IndexBuffer* indexBuffer = new IndexBuffer();

	vertexBuffer->BufferData(mesh->GetVertices()->size() * sizeof(Vertex), mesh->GetVertices()->data(), GL_STATIC_DRAW);
	Mesh::LayoutElements(vertexBuffer);

	indexBuffer->BufferData(mesh->GetIndices()->size() * sizeof(GLushort), mesh->GetIndices()->size(), mesh->GetIndices()->data(), GL_STATIC_DRAW);

	mesh->SetVertexBuffer(vertexBuffer);
	mesh->SetIndexBuffer(indexBuffer);

	m_Queue.push_back(mesh);
}

void SimpleMeshRenderer::Flush()
{
	while (!m_Queue.empty())
	{
		const Mesh* mesh = m_Queue.front();
		mesh->GetVertexArray()->Bind();

		mesh->GetVertexArray()->DrawElements(mesh->GetIndexBuffer()->GetCount());
		m_Queue.pop_front();
	}
}