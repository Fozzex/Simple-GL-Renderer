#pragma once
#include <vector>
#include <memory>

#include "UIPanel.h"
#include "Core/Input/Event.h"

class UIRenderer
{
public:

	UIRenderer();

	void AddPanel(UIPanel* panel);
	bool PassEvent(Event& e);
	
	void Update();

private:

	std::vector<std::unique_ptr<UIPanel>> m_Panels;

};