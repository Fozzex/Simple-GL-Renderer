#include "Mouse.h"
#include <GLFW/glfw3.h>
#include "../Window.h"

void Mouse::GetPosition(double &x, double &y)
{
	glfwGetCursorPos(Window::Get()->Raw(), &x, &y);
}

bool Mouse::ButtonPressed(int button, bool repeat)
{
	int res = glfwGetMouseButton(Window::Get()->Raw(), button);
	return repeat ? res == GLFW_PRESS || res == GLFW_REPEAT : res == GLFW_PRESS;
}