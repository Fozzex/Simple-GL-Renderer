#pragma once
#include <memory>

#include "Util/Singleton.h"
#include "Core/Window/Window.h"
#include "Core.h"

class Application : public Singleton
{
	static Application* s_Instance;
public:

	Application(const std::string& title, int width, int height);
	virtual ~Application();

	virtual void OnEvent(Event& e) = 0;
	virtual void Update() = 0;

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;

};
