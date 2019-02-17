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
	glfwSetCharCallback(m_Window, Window::CharCallback);
	glfwSetCursorPosCallback(m_Window, Window::CursorPosCallback);
	glfwSetMouseButtonCallback(m_Window, Window::MouseButtonCallback);
	glfwSetScrollCallback(m_Window, Window::MouseScrollCallback);
	glfwSetWindowSizeCallback(m_Window, Window::WindowResizeCallback);
	glfwSetWindowCloseCallback(m_Window, Window::WindowCloseCallback);
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

bool Window::PollEvent(Event& e)
{
	if (!EventQueue::Empty())
	{
		e = EventQueue::Next();
		return true;
	}

	return false;
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Event e;
	switch (action)
	{
	case GLFW_PRESS:
		e.type = Event::Type::KeyPressed;
		break;

	case GLFW_RELEASE:
		e.type = Event::Type::KeyReleased;
		break;

	case GLFW_REPEAT:
		e.type = Event::Type::KeyPressed;
		break;

	}

	e.key.key_code = static_cast<Keyboard::KeyCode>(key);
	e.key.shift = mods & GLFW_MOD_SHIFT;
	e.key.ctrl = mods & GLFW_MOD_CONTROL;
	e.key.alt = mods & GLFW_MOD_ALT;
	e.key.option = mods & GLFW_MOD_SUPER;

	EventQueue::Add(e);
}

void Window::CharCallback(GLFWwindow* window, unsigned int codepoint)
{
	Event e;
	e.type = Event::Type::KeyTyped;

	e.text.character = (char)codepoint;
	EventQueue::Add(e);
}

void Window::CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	Event e;
	e.type = Event::Type::MouseMoved;

	e.mouse.x = xpos;
	e.mouse.y = ypos;

	EventQueue::Add(e);
}

void Window::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	Event e;
	switch (action)
	{
	case GLFW_PRESS:
		e.type = Event::Type::MouseButtonPressed;
		break;

	case GLFW_RELEASE:
		e.type = Event::Type::MouseButtonReleased;
		break;
	}

	e.button.button = static_cast<Mouse::Button>(button);
	e.button.shift  = mods & GLFW_MOD_SHIFT;
	e.button.ctrl   = mods & GLFW_MOD_CONTROL;
	e.button.alt    = mods & GLFW_MOD_ALT;
	e.button.option = mods & GLFW_MOD_SUPER;

	EventQueue::Add(e);
}

void Window::MouseScrollCallback(GLFWwindow* window, double xoff, double yoff)
{
	Event e;
	e.type = Event::Type::MouseScrolled;

	e.scroll.x_offset = xoff;
	e.scroll.y_offset = yoff;

	EventQueue::Add(e);
}

void Window::WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	Event e;
	e.type = Event::Type::WindowResized;

	e.window.width = width;
	e.window.height = height;

	EventQueue::Add(e);
}

void Window::WindowCloseCallback(GLFWwindow* window)
{
	Event e;
	e.type = Event::Type::WindowClosed;

	EventQueue::Add(e);
}