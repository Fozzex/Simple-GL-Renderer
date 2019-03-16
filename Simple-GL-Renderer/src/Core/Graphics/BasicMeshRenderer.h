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
	inline void SetSpecularStrength(float strength) { m_SpecularStrength = strength; }

	inline void SetLightPosition(const glm::vec3& position) { m_LightPosition = position; }
	inline void SetLightColour(const glm::vec3& colour) { m_LightColour = colour; }

	inline glm::vec3 GetLightPosition() const { return m_LightPosition; }

private:

	std::deque<Mesh*> m_RenderQueue;

	const ShaderProgram* m_Program;
	Camera* m_Camera;

	float m_AmbientStrength = 1.0f;
	float m_SpecularStrength = 0.0f;

	glm::vec3 m_LightPosition = glm::vec3(0.0f);
	glm::vec3 m_LightColour = glm::vec3(1.0f, 1.0f, 1.0f);

};