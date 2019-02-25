#include <iostream>

#include "Core/Window/Window.h"
#include "Core/Application.h"
#include "Core/Input/Keyboard.h"
#include "Core/Input/Mouse.h"
#include "Core/Graphics/Scene.h"
#include "Core/Graphics/UIPanel.h"
#include "Core/Graphics/Mesh.h"
#include "Core/Graphics/SimpleRenderer.h"

class TestScene : public Scene
{
public:

	TestScene() 
	{
		std::cout << "TestScene Registered" << std::endl;
		m_QuadMesh = std::make_unique<Mesh>(m_QuadVertices, m_QuadIndices);
	}

	~TestScene()
	{

	}

	void Update() override
	{
		m_Renderer.Submit(m_QuadMesh.get());

		m_Renderer.Flush();
	}

	void OnEvent(Event& e) override
	{
		switch (e.type)
		{
		case Event::Type::MouseButtonPressed:
			std::cout << "[TestScene]: Mouse Pressed" << std::endl;
		}
	}

private:

	std::vector<Vertex> m_QuadVertices
	{
		{ glm::vec3(-0.5f,  0.5f, 0.0), glm::vec3(0.2f, 0.2f, 0.2f) },
		{ glm::vec3( 0.5f,  0.5f, 0.0), glm::vec3(0.2f, 0.2f, 0.2f) },
		{ glm::vec3( 0.5f, -0.5f, 0.0), glm::vec3(0.2f, 0.2f, 0.2f) },
		{ glm::vec3(-0.5f, -0.5f, 0.0), glm::vec3(0.2f, 0.2f, 0.2f) }
	};

	std::vector<GLushort> m_QuadIndices
	{
		0, 1, 3,
		1, 2, 3
	};

	SimpleRenderer m_Renderer;
	std::unique_ptr<Mesh> m_QuadMesh;

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