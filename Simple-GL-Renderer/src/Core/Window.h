#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <memory>
#include <iostream>

#include "Core.h"
#include "Util/Singleton.h"

class Window : public Singleton
{
	static Window* s_WindowInstance;
public:

	Window(const std::string& title, int width, int height);
	~Window();

	void StartFrame();
	void EndFrame();

	inline bool Closed() const { return glfwWindowShouldClose(m_Window); }
	inline static Window* Get() { return s_WindowInstance; }

	inline GLFWwindow* Raw() const { return m_Window; }

private:

	GLFWwindow* m_Window;
	std::string m_Title;
	int m_Width, m_Height;

private:

	static void KeyCallback(GLFWwindow*, int, int, int, int);

};