#pragma once
#include "Core/Graphics/Mesh.h"

class MeshRenderer
{
public:

	MeshRenderer() {}
	virtual ~MeshRenderer() {}

	virtual void Submit(Mesh* mesh) = 0;
	virtual void Flush() = 0;

};