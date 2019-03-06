#pragma once
#include <GLFW/glfw3.h>

class Mouse
{
public:
	enum class Button;

	static bool ButtonPressed(Button button);

	static void GetPosition(double &x, double &y);
	static void SetPosition(double x, double y);

	static void SetCursorHidden(bool hidden);

	enum class Button
	{
		Left	= GLFW_MOUSE_BUTTON_1,
		Right	= GLFW_MOUSE_BUTTON_2,
		Middle	= GLFW_MOUSE_BUTTON_3,

		Mouse4  = GLFW_MOUSE_BUTTON_4,
		Mouse5  = GLFW_MOUSE_BUTTON_5
	};

};