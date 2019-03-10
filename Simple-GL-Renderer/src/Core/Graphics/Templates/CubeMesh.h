#pragma once
#include <glm/glm.hpp>

#include "Core/Graphics/Mesh.h"
#include "Core/Core.h"

class CubeMesh : public Mesh
{
public:

	CubeMesh(const glm::vec3& position, const glm::vec3& colour);

};