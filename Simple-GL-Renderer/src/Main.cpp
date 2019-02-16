#include <iostream>

#include "Core/Window.h"
#include "Core/Application.h"
#include "Core/Input/Keyboard.h"
#include "Core/Input/Mouse.h"

class Sandbox : public Application
{
public:

	Sandbox() : Application("OpenGL Renderer", 1280, 720)
	{
		std::cout << "Sandbox Constructed" << std::endl;
	}

	~Sandbox()
	{
		std::cout << "Sandbox Destroyed" << std::endl;
	}
	
	void Update() override
	{
		if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "Left mouse button pressed" << std::endl;
		}
	}

};

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}