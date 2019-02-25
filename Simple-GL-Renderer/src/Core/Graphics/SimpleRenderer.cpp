#include "SimpleRenderer.h"

SimpleRenderer::SimpleRenderer()
{

}

SimpleRenderer::~SimpleRenderer()
{

}

void SimpleRenderer::Submit(Mesh* mesh)
{
	m_Queue.push_back(mesh);
}

void SimpleRenderer::Flush()
{
	while (!m_Queue.empty())
	{
		m_Queue.front()->Draw();

		m_Queue.pop_front();
	}
}