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
	glfwSetWindowUserPointer(m_Window, &m_Callback);
	glViewport(0, 0, m_Width, m_Height);

	GLCall(glEnable(GL_DEPTH_TEST));

	glfwSetKeyCallback(m_Window, Window::KeyCallback);
	glfwSetCharCallback(m_Window, Window::CharCallback);
	glfwSetCursorPosCallback(m_Window, Window::CursorPosCallback);
	glfwSetMouseButtonCallback(m_Window, Window::MouseButtonCallback);
	glfwSetScrollCallback(m_Window, Window::MouseScrollCallback);
	glfwSetWindowSizeCallback(m_Window, Window::WindowResizeCallback);
	glfwSetWindowCloseCallback(m_Window, Window::WindowCloseCallback);

	m_IsVSync = true;
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Window::StartFrame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::EndFrame()
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Window::SetVSync(bool enable)
{
	m_IsVSync = enable;
	glfwSwapInterval(static_cast<int>(enable));
}

void Window::SetTitle(const std::string& title)
{
	glfwSetWindowTitle(m_Window, title.c_str());
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));

	switch (action)
	{
	case GLFW_PRESS:
		{
			KeyPressedEvent evnt((Keyboard::KeyCode)key, 0);
			callback(evnt);
			break;
		}
	case GLFW_RELEASE:
		{
			KeyReleasedEvent evnt((Keyboard::KeyCode)key);
			callback(evnt);
			break;
		}
	case GLFW_REPEAT:
		{
			KeyPressedEvent evnt((Keyboard::KeyCode)key, 1);
			callback(evnt);
			break;
		}
	}
}

void Window::CharCallback(GLFWwindow* window, unsigned int codepoint)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));

	KeyTypedEvent evnt((char)codepoint);
	evnt.SetTypeIndex<KeyTypedEvent>();
	callback(evnt);
}

void Window::CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));

	MouseMovedEvent evnt(xpos, ypos);
	evnt.SetTypeIndex<MouseMovedEvent>();
	callback(evnt);
}

void Window::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));
	
	switch (action)
	{
	case GLFW_PRESS:
		{
			MouseButtonPressedEvent evnt(button);
			evnt.SetTypeIndex<MouseButtonPressedEvent>();
			callback(evnt);
			break;
		}
	case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent evnt(button);
			evnt.SetTypeIndex<MouseButtonReleasedEvent>();
			callback(evnt);
			break;
		}
	}
}

void Window::MouseScrollCallback(GLFWwindow* window, double xoff, double yoff)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));
	
	MouseScrolledEvent evnt(xoff, yoff);
	evnt.SetTypeIndex<MouseScrolledEvent>();
	callback(evnt);
}

void Window::WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));

	WindowResizedEvent evnt(width, height);
	evnt.SetTypeIndex<WindowResizedEvent>();
	callback(evnt);
}

void Window::WindowCloseCallback(GLFWwindow* window)
{
	CallbackFn callback = *reinterpret_cast<CallbackFn*>(glfwGetWindowUserPointer(window));
	
	WindowClosedEvent evnt;
	evnt.SetTypeIndex<WindowClosedEvent>();
	callback(evnt);
}