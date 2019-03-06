#include "Camera.h"

Camera::Camera(const glm::vec3& position, float fov, float renderDistance) :
	m_Position(position), m_Rotation(-90.0f, 0.0f, 0.0f)
{
	m_ProjMatrix = glm::perspective(glm::radians(fov), Window::Get()->GetAspectRatio(), 0.1f, renderDistance);
}

void Camera::Move(float xOff, float yOff, float zOff)
{
	m_Position += m_RelativeRight * xOff;
	m_Position += m_GlobalUp * yOff;
	m_Position -= m_RelativeForward * zOff;
}

void Camera::Move(const glm::vec3& offset)
{
	m_Position += m_RelativeRight * offset.x;
	m_Position += m_RelativeUp * offset.y;
	m_Position -= m_RelativeForward * offset.z;
}

void Camera::Rotate(float pitch, float yaw, float roll)
{
	m_Rotation.x += pitch;
	m_Rotation.y += yaw;
	m_Rotation.z += roll;
}

void Camera::Rotate(const glm::vec3& angle)
{
	m_Rotation.x += angle.x;
	m_Rotation.y += angle.y;
	m_Rotation.z += angle.z;
}

void Camera::UpdateAngles()
{

	if (m_Rotation.y > 89.0f)
		m_Rotation.y = 89.0f;
	if (m_Rotation.y < -89.0f)
		m_Rotation.y = -89.0f;


	float cosY = glm::cos(glm::radians(m_Rotation.y));

	m_RelativeForward.x = glm::cos(glm::radians(m_Rotation.x)) * cosY;
	m_RelativeForward.y = glm::sin(glm::radians(m_Rotation.y));
	m_RelativeForward.z = glm::sin(glm::radians(m_Rotation.x)) * cosY;

	m_RelativeForward = glm::normalize(m_RelativeForward);

	m_RelativeRight = glm::normalize(glm::cross(m_RelativeForward, m_GlobalUp));
	m_RelativeUp = glm::normalize(glm::cross(m_RelativeRight, m_RelativeForward));
}

glm::mat4 Camera::GetViewMatrix()
{
	this->UpdateAngles();
	return glm::lookAt(m_Position, m_Position + m_RelativeForward, m_GlobalUp);
}