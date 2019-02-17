#pragma once
#include <GLFW/glfw3.h>

class Mouse
{
public:

	static bool ButtonPressed(int button);

	static void GetPosition(double &x, double &y);

	enum Button
	{
		Left	= GLFW_MOUSE_BUTTON_1,
		Right	= GLFW_MOUSE_BUTTON_2,
		Middle	= GLFW_MOUSE_BUTTON_3,

		Mouse4  = GLFW_MOUSE_BUTTON_4,
		Mouse5  = GLFW_MOUSE_BUTTON_5
	};

};