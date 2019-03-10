#include <iostream>
#include "Core/RenderEngine.h"

class TestScene : public Scene
{
public:

	TestScene() 
	{
		m_Camera = std::make_unique<Camera>(glm::vec3(0.0f, 0.0f, 3.0f));
		m_Renderer = std::make_unique<BasicMeshRenderer>(Application::Get()->GetProgram(), m_Camera.get());
		m_CubeMesh = std::make_unique<CubeMesh>(glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.9f, 0.7f, 0.3f));

		m_CubeTexture = std::make_unique<Texture2D>("res/Textures/pavement.jpg");
		m_CubeMesh->SetTexture(m_CubeTexture.get());

		m_ImGuiPanel = std::make_unique<ImGuiPanel>();

		m_WindowCentre.x = Window::Get()->GetWidth() / 2.0f;
		m_WindowCentre.y = Window::Get()->GetHeight() / 2.0f;

		m_MousePosition = m_WindowCentre;

		Window::Get()->SetVSync(false);

		m_Renderer->SetAmbientStrength(1.0f);
	}

	~TestScene()
	{

	}

	void Update(float dt) override
	{
		Window::Get()->SetTitle("Render Engine | FPS: " + std::to_string(1 / dt));
		m_DeltaTime = dt;
		float frameSpeed = m_CamSpeed * dt;

		if (Keyboard::KeyPressed(Keyboard::KeyCode::A))
			m_Camera->Move(-frameSpeed, 0.0f, 0.0f);
		if (Keyboard::KeyPressed(Keyboard::KeyCode::D))
			m_Camera->Move(frameSpeed, 0.0f, 0.0f);
		if (Keyboard::KeyPressed(Keyboard::KeyCode::W))
			m_Camera->Move(0.0f, 0.0f, -frameSpeed);
		if (Keyboard::KeyPressed(Keyboard::KeyCode::S))
			m_Camera->Move(0.0f, 0.0f, frameSpeed);
		if (Keyboard::KeyPressed(Keyboard::KeyCode::LeftShift))
			m_Camera->Move(0.0f, -frameSpeed, 0.0f);
		if (Keyboard::KeyPressed(Keyboard::KeyCode::Space))
			m_Camera->Move(0.0f, frameSpeed, 0.0f);

		m_Renderer->Submit(m_CubeMesh.get());
		m_CubeMesh->SetRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));

		m_Renderer->Flush();

		m_ImGuiPanel->StartFrame();
		ImGui::Begin("Render Engine", &m_MenuOpen);

		ImGui::Text("FPS: %.2f", 1 / dt);

		ImGui::End();
		m_ImGuiPanel->Render(dt);
	}

	void OnEvent(Event& e) override
	{
		if (m_ImGuiPanel->OnEvent(e))
			return;

		switch (e.type)
		{
		case Event::Type::KeyPressed:
			if (e.key.key_code == Keyboard::KeyCode::Z)
			{
				m_HasCursor = !m_HasCursor;
				Mouse::SetPosition(m_WindowCentre.x, m_WindowCentre.y);
				Mouse::SetCursorHidden(!m_HasCursor);
			}
			break;
		case Event::Type::MouseMoved:
			if (!m_HasCursor)
			{
				glm::vec3 offset;

				m_MousePosition.x = (float)e.mouse.x;
				m_MousePosition.y = (float)e.mouse.y;

				offset.x = m_MousePosition.x - m_WindowCentre.x;
				offset.y = m_WindowCentre.y - m_MousePosition.y;
				offset.z = 0.0f;

				offset *= m_Sensitivity;

				m_Camera->Rotate(offset);
				Mouse::SetPosition(m_WindowCentre.x, m_WindowCentre.y);
			}
			break;
		}
	}

private:

	std::unique_ptr<BasicMeshRenderer> m_Renderer;
	std::unique_ptr<CubeMesh> m_CubeMesh;
	std::unique_ptr<Texture2D> m_CubeTexture;
	std::unique_ptr<Camera> m_Camera;

	std::unique_ptr<ImGuiPanel> m_ImGuiPanel;
	bool m_MenuOpen = true;

	float m_DeltaTime;
	float m_Sensitivity = 0.1f;
	glm::vec3 m_MousePosition;
	glm::vec3 m_WindowCentre;

	bool m_HasCursor = true;
	const float m_CamSpeed = 1.0f;
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
	}
	
};

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}