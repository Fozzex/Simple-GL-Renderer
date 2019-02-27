#include <iostream>

#include "Core/Window/Window.h"
#include "Core/Application.h"
#include "Core/Input/Keyboard.h"
#include "Core/Input/Mouse.h"
#include "Core/Graphics/Scene.h"
#include "Core/Graphics/UIPanel.h"
#include "Core/Graphics/Mesh.h"
#include "Core/Graphics/BasicMeshRenderer.h"
#include "Core/Graphics/Templates/QuadMesh.h"

class TestScene : public Scene
{
public:

	TestScene() 
	{
		std::cout << "TestScene Registered" << std::endl;
		m_Renderer = std::make_unique<BasicMeshRenderer>(Application::Get()->GetProgram());
		m_QuadMesh = std::make_unique<QuadMesh>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.9f, 0.7f, 0.3f));
	}

	~TestScene()
	{

	}

	void Update() override
	{
		m_Renderer->Submit(m_QuadMesh.get());

		m_Renderer->Flush();
	}

	void OnEvent(Event& e) override
	{
		switch (e.type)
		{
		case Event::Type::KeyPressed:
			if (e.key.key_code == Keyboard::A)
				m_QuadMesh->Move(glm::vec3(-0.001f, 0.0f, 0.0f));
			if (e.key.key_code == Keyboard::D)
				m_QuadMesh->Move(glm::vec3(0.001f, 0.0f, 0.0f));
			if (e.key.key_code == Keyboard::W)
				m_QuadMesh->Move(glm::vec3(0.0f, 0.001f, 0.0f));
			if (e.key.key_code == Keyboard::S)
				m_QuadMesh->Move(glm::vec3(0.0f, -0.001f, 0.0f));
		}
	}

private:

	std::unique_ptr<BasicMeshRenderer> m_Renderer;
	std::unique_ptr<QuadMesh> m_QuadMesh;

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