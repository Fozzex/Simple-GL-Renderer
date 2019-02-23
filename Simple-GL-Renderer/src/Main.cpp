#include <iostream>

#include "Core/Window/Window.h"
#include "Core/Application.h"
#include "Core/Input/Keyboard.h"
#include "Core/Input/Mouse.h"
#include "Core/Graphics/Scene.h"
#include "Core/Graphics/UIPanel.h"

class MyGUI : public UIPanel
{
public:

	MyGUI() {}
	~MyGUI() {}

	void Update() override
	{

	}

	bool OnEvent(Event& e) override
	{
		if (e.type == Event::Type::MouseButtonPressed)
		{
			if (e.button.button == Mouse::Button::Left)
			{
				std::cout << "[GUI] Left Mouse Button Pressed!" << std::endl;
				return true;
			}
		}

		return false;
	}

	bool IsActive() override
	{
		return true;
	}

};

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
		this->RegisterUIPanel(new MyGUI());
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