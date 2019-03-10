#include "QuadMesh.h"

QuadMesh::QuadMesh(const glm::vec3& position, const glm::vec3& colour) :
	Mesh({
			{ glm::vec3(-1.0f,  1.0f, 0.0f), colour, glm::vec2(0.0, 1.0), glm::vec3(0.0f, 1.0f, 0.0f) },
			{ glm::vec3( 1.0f,  1.0f, 0.0f), colour, glm::vec2(1.0, 1.0), glm::vec3(0.0f, 1.0f, 0.0f) },
			{ glm::vec3( 1.0f, -1.0f, 0.0f), colour, glm::vec2(1.0, 0.0), glm::vec3(0.0f, 1.0f, 0.0f) },
			{ glm::vec3(-1.0f, -1.0f, 0.0f), colour, glm::vec2(0.0, 0.0), glm::vec3(0.0f, 1.0f, 0.0f) }
		},
		{
			0, 1, 3,
			1, 2, 3
		})
{
	this->SetPosition(position);
}