#include "BasicMeshRenderer.h"

BasicMeshRenderer::BasicMeshRenderer(const ShaderProgram* program) :
	m_Program(program)
{

}

BasicMeshRenderer::~BasicMeshRenderer()
{

}

void BasicMeshRenderer::Submit(Mesh* mesh)
{
	m_RenderQueue.push_back(mesh);
}

void BasicMeshRenderer::Flush()
{
	m_Program->Bind();
	while (!m_RenderQueue.empty())
	{
		Mesh* mesh = m_RenderQueue.front();
		
		mesh->UpdateModelMatrix();
		m_Program->SetMat4("uModelMatrix", mesh->GetModelMatrix());

		mesh->Draw();

		m_RenderQueue.pop_front();
	}
}