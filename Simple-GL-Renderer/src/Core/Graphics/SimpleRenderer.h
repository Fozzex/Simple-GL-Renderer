#pragma once
#include <deque>

#include "Core/Graphics/Mesh.h"

class SimpleRenderer
{
public:

	SimpleRenderer();
	~SimpleRenderer();

	void Submit(Mesh* mesh);
	void Flush();

private:

	std::deque<Mesh*> m_Queue;

};