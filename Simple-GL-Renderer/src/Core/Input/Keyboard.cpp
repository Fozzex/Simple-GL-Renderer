#include "Keyboard.h"
#include "Core/Window/Window.h"

bool Keyboard::KeyPressed(int key)
{
	return glfwGetKey(Window::Get()->Raw(), key);
}