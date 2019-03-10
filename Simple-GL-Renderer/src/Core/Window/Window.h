#pragma once
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <string>
#include <memory>
#include <iostream>
#include <functional>

#include "Core/Core.h"
#include "Core/Util/Singleton.h"
#include "Core/Input/Event.h"

class Window : public Singleton
{
	static Window* s_WindowInstance;
	using CallbackFn = std::function<void(Event&)>;
public:

	Window(const std::string& title, int width, int height);
	~Window();

	void StartFrame();
	void EndFrame();

	void SetVSync(bool enable);
	void SetTitle(const std::string& title);

	inline void SetEventCallback(const CallbackFn& callback) { m_Callback = callback; }

	inline bool Closed() const { return glfwWindowShouldClose(m_Window); }
	inline static Window* Get() { return s_WindowInstance; }

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

	inline float GetAspectRatio() const { return m_Width / (float)m_Height; }

	inline GLFWwindow* Raw() const { return m_Window; }

private:

	GLFWwindow* m_Window;
	std::string m_Title;
	int m_Width, m_Height;
	bool m_IsVSync;
	CallbackFn m_Callback;

private:

	static void KeyCallback(GLFWwindow*, int, int, int, int);
	static void CharCallback(GLFWwindow*, unsigned int);
	static void CursorPosCallback(GLFWwindow*, double, double);
	static void MouseButtonCallback(GLFWwindow*, int, int, int);
	static void MouseScrollCallback(GLFWwindow*, double, double);
	static void WindowResizeCallback(GLFWwindow*, int, int);
	static void WindowCloseCallback(GLFWwindow*);

};