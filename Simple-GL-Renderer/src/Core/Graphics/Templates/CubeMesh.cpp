#include "CubeMesh.h"

CubeMesh::CubeMesh(const glm::vec3& position, const glm::vec3& colour) :
	Mesh({
		{ glm::vec3(-0.5f, -0.5f, -0.5f), colour, glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  0.0f, -1.0f) },
		{ glm::vec3( 0.5f, -0.5f, -0.5f), colour, glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  0.0f, -1.0f) },
		{ glm::vec3( 0.5f,  0.5f, -0.5f), colour, glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  0.0f, -1.0f) },
		{ glm::vec3(-0.5f,  0.5f, -0.5f), colour, glm::vec2(0.0f, 1.0f), glm::vec3(0.0f,  0.0f, -1.0f) },
																		 
		{ glm::vec3(-0.5f, -0.5f,  0.5f), colour, glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  0.0f,  1.0f) },
		{ glm::vec3( 0.5f, -0.5f,  0.5f), colour, glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  0.0f,  1.0f) },
		{ glm::vec3( 0.5f,  0.5f,  0.5f), colour, glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  0.0f,  1.0f) },
		{ glm::vec3(-0.5f,  0.5f,  0.5f), colour, glm::vec2(0.0f, 1.0f), glm::vec3(0.0f,  0.0f,  1.0f) },
																		 
		{ glm::vec3(-0.5f,  0.5f,  0.5f), colour, glm::vec2(1.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
		{ glm::vec3(-0.5f,  0.5f, -0.5f), colour, glm::vec2(1.0f, 1.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
		{ glm::vec3(-0.5f, -0.5f, -0.5f), colour, glm::vec2(0.0f, 1.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
		{ glm::vec3(-0.5f, -0.5f,  0.5f), colour, glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
																		 
		{ glm::vec3( 0.5f,  0.5f,  0.5f), colour, glm::vec2(1.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
		{ glm::vec3( 0.5f,  0.5f, -0.5f), colour, glm::vec2(1.0f, 1.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
		{ glm::vec3( 0.5f, -0.5f, -0.5f), colour, glm::vec2(0.0f, 1.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
		{ glm::vec3( 0.5f, -0.5f,  0.5f), colour, glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f) },
																		 
		{ glm::vec3(-0.5f, -0.5f, -0.5f), colour, glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f,  0.0f) },
		{ glm::vec3( 0.5f, -0.5f, -0.5f), colour, glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f,  0.0f) },
		{ glm::vec3( 0.5f, -0.5f,  0.5f), colour, glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f,  0.0f) },
		{ glm::vec3(-0.5f, -0.5f,  0.5f), colour, glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f,  0.0f) },
																		 
		{ glm::vec3(-0.5f,  0.5f, -0.5f), colour, glm::vec2(0.0f, 1.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
		{ glm::vec3( 0.5f,  0.5f, -0.5f), colour, glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
		{ glm::vec3( 0.5f,  0.5f,  0.5f), colour, glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
		{ glm::vec3(-0.5f,  0.5f,  0.5f), colour, glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
	},
	{
			 0,  1,  3,  1,  2,  3,
			 4,  5,  7,  5,  6,  7,
			 8,  9, 11,  9, 10, 11,
			12, 13, 15, 13, 14, 15,
			16, 17, 19, 17, 18, 19,
			20, 21, 23, 21, 22, 23
	})
{
	this->SetPosition(position);
}