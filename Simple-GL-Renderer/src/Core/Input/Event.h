#pragma once
#include "Core/Input/Keyboard.h"
#include "Core/Input/Mouse.h"

class Event
{
public:

	struct KeyEvent
	{
		Keyboard::KeyCode key_code;

		bool alt;
		bool ctrl;
		bool shift;
		bool option;
	};

	struct KeyTypeEvent
	{
		char character;
	};

	struct MouseMoveEvent
	{
		double x, y;
	};

	struct MouseButtonEvent
	{
		Mouse::Button button;

		bool alt;
		bool ctrl;
		bool shift;
		bool option;
	};

	struct MouseScrollEvent
	{
		double x_offset, y_offset;
	};

	struct WindowResizeEvent
	{
		int width, height;
	};

	enum Type
	{
		KeyPressed,
		KeyReleased,
		KeyTyped,
		MouseMoved,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseScrolled,
		WindowResized,
		WindowClosed
	} type;

	union
	{
		KeyEvent key;
		KeyTypeEvent text;
		MouseMoveEvent mouse;
		MouseButtonEvent button;
		MouseScrollEvent scroll;
		WindowResizeEvent window;
	};

};