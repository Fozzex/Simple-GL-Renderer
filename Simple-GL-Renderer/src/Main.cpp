#include <iostream>

#include "Core/Window/Window.h"
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
		if (Mouse::ButtonPressed(Mouse::Button::Right))
		{
			std::cout << "Right mouse button pressed" << std::endl;
		}
	}

	void OnEvent(Event& e) override
	{
		switch (e.type)
		{
		case Event::Type::KeyPressed:
			if (e.key.key_code == Keyboard::A)
			{
				std::cout << "A Key Pressed (Event)" << std::endl;
			}
			break;
		case Event::Type::WindowResized:
			std::cout << e.window.width << ", " << e.window.height << std::endl;
		}
	}

};

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}