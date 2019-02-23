#pragma once
#include <memory>
#include <GL/glew.h>

#include "Util/Singleton.h"
#include "Core/Window/Window.h"
#include "Core/Graphics/SceneManager.h"
#include "Core.h"

class Application : public Singleton
{
	static Application* s_Instance;
public:

	Application(const std::string& title, int width, int height);
	virtual ~Application();

	void RegisterScene(Scene* scene);

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;
	SceneManager m_SceneManager;

};
