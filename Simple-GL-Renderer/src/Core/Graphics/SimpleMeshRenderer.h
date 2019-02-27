#pragma once
#include <deque>

#include "Core/Graphics/Mesh.h"
#include "Core/Graphics/MeshRenderer.h"

#include "Core/Graphics/OpenGL/VertexArray.h"
#include "Core/Graphics/OpenGL/VertexBuffer.h"
#include "Core/Graphics/OpenGL/IndexBuffer.h"

class SimpleMeshRenderer : public MeshRenderer
{
public:

	SimpleMeshRenderer();
	~SimpleMeshRenderer();

	void Submit(Mesh* mesh) override;
	void Flush() override;

private:

	std::deque<const Mesh*> m_Queue;

};