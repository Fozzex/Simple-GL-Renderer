#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Window/Window.h"

class Camera
{
public:

	Camera(const glm::vec3& position, float fov = 65.0f, float renderDistance = 100.f);

	inline void Move(const glm::vec3& offset) { m_Position += offset; }
	
	inline glm::mat4 GetViewMatrix() { this->UpdateMatrices(); return m_ViewMatrix; }
	inline glm::mat4 GetProjMatrix() { this->UpdateMatrices(); return m_ProjMatrix; }

private:

	void UpdateMatrices();

private:

	glm::vec3 m_Position;

	glm::mat4 m_ViewMatrix = glm::mat4(1);
	glm::mat4 m_ProjMatrix = glm::mat4(1);

};