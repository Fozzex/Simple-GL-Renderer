#include "Application.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

Application* Application::s_Instance = nullptr;

Application::Application(const std::string& title, int width, int height)
{
	ASSERT(s_Instance == nullptr, "Multiple instances of application class");
	s_Instance = this;

	m_Window = std::make_unique<Window>(title, width, height);

	glewExperimental = GL_TRUE;
	VERIFY(glewInit() == GLEW_OK, "Failed to initialize GLEW");

	m_VertexShader = std::make_unique<VertexShader>("res/Shaders/BasicVS.shader");
	m_FragmentShader = std::make_unique<FragmentShader>("res/Shaders/BasicFS.shader");

	m_Program = std::make_unique<ShaderProgram>();

	m_Program->Attach(m_VertexShader.get());
	m_Program->Attach(m_FragmentShader.get());

	m_Program->Link();

	m_QuadMesh = std::make_unique<Mesh>(m_Vertices, m_Indices);
}

Application::~Application()
{

}

void Application::RegisterScene(Scene* scene)
{
	m_SceneManager.Push(scene);
}

void Application::RegisterUIPanel(UIPanel* panel)
{
	m_UIRenderer.AddPanel(panel);
}

void Application::Run()
{
	while (!m_Window->Closed())
	{
		Event e;
		while (m_Window->PollEvent(e))
		{
			if (!m_UIRenderer.PassEvent(e))
				m_SceneManager.GetActiveScene()->OnEvent(e);
		}

		m_Window->StartFrame();
		m_SceneManager.GetActiveScene()->Update();
		m_UIRenderer.Update();

		m_Program->Bind();
		m_QuadMesh->Draw();

		m_Window->EndFrame();
	}
}