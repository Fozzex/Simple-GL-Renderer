#include <iostream>

#include "Core/Window/Window.h"
#include "Core/Application.h"
#include "Core/Input/Keyboard.h"
#include "Core/Input/Mouse.h"
#include "Core/Graphics/Scene.h"
#include "Core/Graphics/UIPanel.h"

class TestScene : public Scene
{
public:

	TestScene() 
	{
		std::cout << "TestScene Registered" << std::endl;
	}

	~TestScene()
	{

	}

	void Update() override
	{

	}

	void OnEvent(Event& e) override
	{
		switch (e.type)
		{
		case Event::Type::KeyPressed:
			std::cout << "Key Pressed: " << e.key.key_code << std::endl;
		}
	}

};

class Sandbox : public Application
{
public:

	Sandbox() : Application("OpenGL Renderer", 1280, 720)
	{
		std::cout << "Sandbox Constructed" << std::endl;
		this->RegisterScene(new TestScene());
	}

	~Sandbox()
	{
		std::cout << "Sandbox Destroyed" << std::endl;
	}
	
};

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}