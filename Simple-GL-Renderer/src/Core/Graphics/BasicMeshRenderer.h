#pragma once
#include <deque>

#include "MeshRenderer.h"
#include "Core/Graphics/OpenGL/ShaderProgram.h"
#include "Core/Graphics/Camera.h"
#include "Core/Graphics/Texture2D.h"

class BasicMeshRenderer : public MeshRenderer
{
public:

	BasicMeshRenderer(const ShaderProgram* program, Camera* camera);
	~BasicMeshRenderer();

	void Submit(Mesh* mesh) override;
	void Flush() override;

	inline void SetAmbientStrength(float strength) { m_AmbientStrength = strength; }

private:

	std::deque<Mesh*> m_RenderQueue;

	const ShaderProgram* m_Program;
	Camera* m_Camera;

	float m_AmbientStrength = 1.0f;

};