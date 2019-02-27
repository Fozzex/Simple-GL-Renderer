#pragma once
#include <deque>

#include "MeshRenderer.h"
#include "Core/Graphics/OpenGL/ShaderProgram.h"

class BasicMeshRenderer : public MeshRenderer
{
public:

	BasicMeshRenderer(const ShaderProgram* program);
	~BasicMeshRenderer();

	void Submit(Mesh* mesh) override;
	void Flush() override;

private:

	std::deque<Mesh*> m_RenderQueue;
	const ShaderProgram* m_Program;

};