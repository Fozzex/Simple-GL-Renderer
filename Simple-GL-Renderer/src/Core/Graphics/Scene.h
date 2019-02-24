#pragma once
#include "Core/Input/Event.h"
#include "Core/Graphics/UIRenderer.h"

class Scene
{
public:

	Scene() = default;
	virtual ~Scene() = default;

	virtual void Update() = 0;
	virtual void OnEvent(Event& e) = 0;

	virtual void Pause() {}
	virtual void Resume() {}

};