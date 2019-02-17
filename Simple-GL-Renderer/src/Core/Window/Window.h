#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <memory>
#include <iostream>

#include "Core/Core.h"
#include "Core/Util/Singleton.h"
#include "Core/Input/Event.h"
#include "Core/Input/EventQueue.h"

class Window : public Singleton
{
	static Window* s_WindowInstance;
public:

	Window(const std::string& title, int width, int height);
	~Window();

	void StartFrame();
	void EndFrame();

	bool PollEvent(Event& e);

	inline bool Closed() const { return glfwWindowShouldClose(m_Window); }
	inline static Window* Get() { return s_WindowInstance; }

	inline GLFWwindow* Raw() const { return m_Window; }

private:

	GLFWwindow* m_Window;
	std::string m_Title;
	int m_Width, m_Height;

private:

	static void KeyCallback(GLFWwindow*, int, int, int, int);
	static void CharCallback(GLFWwindow*, unsigned int);
	static void CursorPosCallback(GLFWwindow*, double, double);
	static void MouseButtonCallback(GLFWwindow*, int, int, int);
	static void MouseScrollCallback(GLFWwindow*, double, double);
	static void WindowResizeCallback(GLFWwindow*, int, int);
	static void WindowCloseCallback(GLFWwindow*);

};