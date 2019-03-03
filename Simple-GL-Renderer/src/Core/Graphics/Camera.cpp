#include "Camera.h"

Camera::Camera(const glm::vec3& position, float fov, float renderDistance) :
	m_Position(position)
{
	m_ProjMatrix = glm::perspective(glm::radians(fov), Window::Get()->GetAspectRatio(), 0.1f, renderDistance);
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::UpdateMatrices()
{
	m_ViewMatrix = glm::lookAt(m_Position, m_Position + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}