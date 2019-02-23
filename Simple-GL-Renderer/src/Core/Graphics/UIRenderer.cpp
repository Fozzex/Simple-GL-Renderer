#include "UIRenderer.h"

UIRenderer::UIRenderer()
{
}

void UIRenderer::Update()
{
	for (auto& panel : m_Panels)
	{
		if (panel->IsActive())
			panel->Update();
	}
}

void UIRenderer::AddPanel(UIPanel* panel)
{
	m_Panels.push_back(std::unique_ptr<UIPanel>(panel));
}

bool UIRenderer::PassEvent(Event& e)
{
	if (!e.handled)
	{
		for (auto& panel : m_Panels)
		{
			if (panel->IsActive())
			{
				e.handled = panel->OnEvent(e);

				if (e.handled)
					break;
			}
		}
	}

	return e.handled;
}