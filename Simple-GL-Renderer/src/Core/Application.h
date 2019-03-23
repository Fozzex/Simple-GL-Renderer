#pragma once
#include <functional>
#include <memory>
#include <array>
#include <GL/glew.h>

#include "Core/Util/Singleton.h"
#include "Core/Util/Timer.h"
#include "Core/Window/Window.h"
#include "Core/Graphics/SceneManager.h"
#include "Core/Input/EventDispatcher.h"
#include "Core.h"

#include "Core/Graphics/OpenGL/VertexShader.h"
#include "Core/Graphics/OpenGL/FragmentShader.h"
#include "Core/Graphics/OpenGL/ShaderProgram.h"

#include "Core/Graphics/Mesh.h"

class Application : public Singleton
{
	static Application* s_Instance;
public:

	Application(const std::string& title, int width, int height);
	virtual ~Application();

	void RegisterScene(Scene* scene);
	
	void OnEvent(Event& e);

	inline ShaderProgram* GetProgram() const { return m_Program.get(); }

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;
	SceneManager m_SceneManager;

	Timer m_Timer;

	std::unique_ptr<VertexShader>   m_VertexShader;
	std::unique_ptr<FragmentShader> m_FragmentShader;

	std::unique_ptr<ShaderProgram> m_Program;

};