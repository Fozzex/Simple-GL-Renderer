#include "QuadMesh.h"

QuadMesh::QuadMesh(const glm::vec3& position, const glm::vec3& colour) :
	Mesh({
			{ glm::vec3(-0.5f,  0.5f, 0.0f) + position, colour },
			{ glm::vec3( 0.5f,  0.5f, 0.0f) + position, colour },
			{ glm::vec3( 0.5f, -0.5f, 0.0f) + position, colour },
			{ glm::vec3(-0.5f, -0.5f, 0.0f) + position, colour }
		},
		{
			0, 1, 3,
			1, 2, 3
		})
{
}