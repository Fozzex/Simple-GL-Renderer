#pragma once
#include "Core/Input/Event.h"

class UIPanel
{
public:

	virtual void Update() = 0;
	virtual bool OnEvent(Event& e) = 0;

	virtual bool IsActive() = 0;
	virtual void SetActive(bool active) = 0;

};