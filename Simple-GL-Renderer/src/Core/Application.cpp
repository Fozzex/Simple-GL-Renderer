#include "Application.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

Application* Application::s_Instance = nullptr;

Application::Application(const std::string& title, int width, int height)
{
	ASSERT(s_Instance == nullptr, "Multiple instances of application class");
	s_Instance = this;

	m_Window = std::make_unique<Window>(title, width, height);
}

Application::~Application()
{

}

void Application::RegisterScene(Scene* scene)
{
	m_SceneManager.Push(scene);
}

void Application::Run()
{
	while (!m_Window->Closed())
	{
		Event e;
		while (m_Window->PollEvent(e))
		{
			m_SceneManager.GetActiveScene()->OnEvent(e);
		}

		m_Window->StartFrame();
		m_SceneManager.GetActiveScene()->Update();
		m_Window->EndFrame();
	}
}