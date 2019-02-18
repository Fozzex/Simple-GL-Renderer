#include "SceneManager.h"

void SceneManager::Push(Scene* scene)
{
	if (!m_Scenes.empty())
		m_Scenes.top()->Pause();

	m_Scenes.push(std::unique_ptr<Scene>(scene));
}

void SceneManager::Pop()
{
	if (!m_Scenes.empty())
	{
		m_Scenes.pop();
		
		if (!m_Scenes.empty())
			m_Scenes.top()->Resume();
	}
}