#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Util/Singleton.h"
#include "Core/Window/Window.h"

class Camera : public Singleton
{
public:

	Camera(const glm::vec3& position, float fov = 65.0f, float renderDistance = 100.f);

	void Rotate(float pitch, float yaw, float roll);
	void Rotate(const glm::vec3& rotation);

	void Move(float xOff, float yOff, float zOff);
	void Move(const glm::vec3& offset);
	
	glm::mat4 GetViewMatrix();
	inline glm::mat4 GetProjMatrix() { return m_ProjMatrix; }

	inline glm::vec3 GetPosition() const { return m_Position; }

private:

	void UpdateAngles();

private:

	glm::vec3 m_Position;
	glm::vec3 m_Rotation;

	glm::vec3 m_RelativeUp;
	glm::vec3 m_RelativeRight;
	glm::vec3 m_RelativeForward;

	glm::mat4 m_ProjMatrix = glm::mat4(1);

	glm::vec3 m_GlobalUp = glm::vec3(0.0f, 1.0f, 0.0f);

};