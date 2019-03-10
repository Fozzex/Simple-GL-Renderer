#include "BasicMeshRenderer.h"

BasicMeshRenderer::BasicMeshRenderer(const ShaderProgram* program, Camera* camera) :
	m_Program(program), m_Camera(camera)
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
		
		Texture2D* texture;
		if ((texture = mesh->GetTexture()) != nullptr)
		{
			GLCall(glActiveTexture(GL_TEXTURE0));
			texture->Bind();

			m_Program->SetInt("uNoTexture", 0);
		}
		else
		{
			m_Program->SetInt("uNoTexture", 1);
		}

		mesh->UpdateModelMatrix();
		
		m_Program->SetMat4("uModelMatrix", mesh->GetModelMatrix());
		m_Program->SetMat4("uProjMatrix", m_Camera->GetProjMatrix());
		m_Program->SetMat4("uViewMatrix", m_Camera->GetViewMatrix());

		mesh->Draw();

		m_RenderQueue.pop_front();
	}
}