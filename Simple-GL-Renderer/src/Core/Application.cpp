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

	GLCall(glGenVertexArrays(1, &m_VAO));
	GLCall(glGenBuffers(1, &m_VBO));
	GLCall(glGenBuffers(1, &m_EBO));

	GLCall(glBindVertexArray(m_VAO));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, m_QuadData.size() * sizeof(GLfloat), m_QuadData.data(), GL_STATIC_DRAW));
	
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0));
	GLCall(glEnableVertexAttribArray(0));
	
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_IndexData.size() * sizeof(GLuint), m_IndexData.data(), GL_STATIC_DRAW));
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

		m_Program->Bind();
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		m_Window->EndFrame();
	}
}