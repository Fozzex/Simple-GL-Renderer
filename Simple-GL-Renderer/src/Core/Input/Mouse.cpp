#include "Mouse.h"
#include <GLFW/glfw3.h>
#include "Core/Window/Window.h"

void Mouse::GetPosition(double &x, double &y)
{
	glfwGetCursorPos(Window::Get()->Raw(), &x, &y);
}

bool Mouse::ButtonPressed(Mouse::Button button)
{
	return glfwGetMouseButton(Window::Get()->Raw(), static_cast<int>(button));
}

void Mouse::SetPosition(double x, double y)
{
	glfwSetCursorPos(Window::Get()->Raw(), x, y);
}

void Mouse::SetCursorHidden(bool hidden)
{
	glfwSetInputMode(Window::Get()->Raw(), GLFW_CURSOR, 
		hidden ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);
}