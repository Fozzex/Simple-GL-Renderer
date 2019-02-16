#include "Application.h"
#include "Input/Keyboard.h"

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

void Application::Run()
{
	while (!m_Window->Closed())
	{
		m_Window->StartFrame();
		this->Update();
		m_Window->EndFrame();
	}
}