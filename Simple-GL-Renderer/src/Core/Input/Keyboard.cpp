#include "Keyboard.h"
#include "Core/Window/Window.h"

bool Keyboard::KeyPressed(Keyboard::KeyCode key)
{
	return glfwGetKey(Window::Get()->Raw(), static_cast<int>(key));
}