#pragma once
#include "Core/Input/Event.h"

class Scene
{
public:

	Scene() = default;
	virtual ~Scene() = default;

	virtual void Update(float dt) = 0;
	virtual void OnEvent(Event& e) = 0;

	virtual void Pause() {}
	virtual void Resume() {}

};