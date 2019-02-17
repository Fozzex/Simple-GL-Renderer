#include "Mouse.h"
#include <GLFW/glfw3.h>
#include "Core/Window/Window.h"

void Mouse::GetPosition(double &x, double &y)
{
	glfwGetCursorPos(Window::Get()->Raw(), &x, &y);
}

bool Mouse::ButtonPressed(int button)
{
	return glfwGetMouseButton(Window::Get()->Raw(), button);
}