#include "Window.h"

Window* Window::s_WindowInstance = nullptr;

Window::Window(const std::string& title, int width, int height) :
	m_Title(title), m_Width(width), m_Height(height)
{
	ASSERT(s_WindowInstance == nullptr, "Simple GL Renderer only supports one window");
	s_WindowInstance = this;
	
	VERIFY(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");

	m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (m_Window == nullptr)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_Window);

	glfwSetKeyCallback(m_Window, Window::KeyCallback);
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Window::StartFrame()
{
	glClearColor(0.4f, 0.7f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::EndFrame()
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
		break;
	}
}