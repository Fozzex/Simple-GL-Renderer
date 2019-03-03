#include "QuadMesh.h"

QuadMesh::QuadMesh(const glm::vec3& position, const glm::vec3& colour) :
	Mesh({
			{ glm::vec3(-1.0f,  1.0f, 0.0f), colour },
			{ glm::vec3( 1.0f,  1.0f, 0.0f), colour },
			{ glm::vec3( 1.0f, -1.0f, 0.0f), colour },
			{ glm::vec3(-1.0f, -1.0f, 0.0f), colour }
		},
		{
			0, 1, 3,
			1, 2, 3
		})
{
	this->SetPosition(position);
}