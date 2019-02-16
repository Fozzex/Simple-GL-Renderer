#include "Keyboard.h"

bool Keyboard::KeyPressed(int key)
{
	return glfwGetKey(Window::Get()->Raw(), key);
}