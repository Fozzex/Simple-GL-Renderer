#pragma once
#include <stack>
#include <memory>

#include "Scene.h"

class SceneManager
{
public:

	void Push(Scene* scene);
	void Pop();

	inline Scene* GetActiveScene() const { return m_Scenes.top().get(); }

private:

	std::stack<std::unique_ptr<Scene>> m_Scenes;

};