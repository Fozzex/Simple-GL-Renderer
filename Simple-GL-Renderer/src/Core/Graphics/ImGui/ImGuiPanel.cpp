#include "ImGuiPanel.h"

ImGuiPanel::ImGuiPanel()
{
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplOpenGL3_Init("#version 330");

	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
	io.KeyMap[ImGuiKey_Tab]		    = Keyboard::Tab;
	io.KeyMap[ImGuiKey_LeftArrow]   = Keyboard::Left;
	io.KeyMap[ImGuiKey_RightArrow]  = Keyboard::Right;
	io.KeyMap[ImGuiKey_UpArrow]	    = Keyboard::Up;
	io.KeyMap[ImGuiKey_DownArrow]   = Keyboard::Down;
	io.KeyMap[ImGuiKey_PageUp]	    = Keyboard::PageUp;
	io.KeyMap[ImGuiKey_PageDown]    = Keyboard::PageDown;
	io.KeyMap[ImGuiKey_Home]	    = Keyboard::Home;
	io.KeyMap[ImGuiKey_End]		    = Keyboard::End;
	io.KeyMap[ImGuiKey_Insert]	    = Keyboard::Insert;
	io.KeyMap[ImGuiKey_Delete]	    = Keyboard::Delete;
	io.KeyMap[ImGuiKey_Backspace]   = Keyboard::BackSpace;
	io.KeyMap[ImGuiKey_Space]	    = Keyboard::Space;
	io.KeyMap[ImGuiKey_Enter]	    = Keyboard::Enter;
	io.KeyMap[ImGuiKey_Escape]	    = Keyboard::Escape;
	io.KeyMap[ImGuiKey_A]		    = Keyboard::A;
	io.KeyMap[ImGuiKey_C]		    = Keyboard::C;
	io.KeyMap[ImGuiKey_V]		    = Keyboard::V;
	io.KeyMap[ImGuiKey_X]		    = Keyboard::X;
	io.KeyMap[ImGuiKey_Y]		    = Keyboard::Y;
	io.KeyMap[ImGuiKey_Z]		    = Keyboard::Z;
}

void ImGuiPanel::Update()
{
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2((float)Window::Get()->GetWidth(), (float)Window::Get()->GetHeight());

	float time = (float)glfwGetTime();
	io.DeltaTime = time - m_LastFrameTime;
	m_LastFrameTime = time;

	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Render Engine GUI", &m_ShowMainWindow);

	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool ImGuiPanel::OnEvent(Event& e)
{
	ImGuiIO& io = ImGui::GetIO();
	switch (e.type)
	{
	case Event::Type::KeyPressed:
		if (io.WantCaptureKeyboard)
		{
			io.KeysDown[e.key.key_code] = true;

			io.KeyCtrl = e.key.ctrl;
			io.KeyShift = e.key.shift;
			io.KeyAlt = e.key.alt;
			io.KeySuper = e.key.option;

			return true;
		}
		break;

	case Event::Type::KeyReleased:
		if (io.WantCaptureKeyboard)
		{
			io.KeysDown[e.key.key_code] = false;
			return true;
		}
		break;

	case Event::Type::KeyTyped:
		if (io.WantTextInput)
		{
			io.AddInputCharacter(e.text.character);
			return true;
		}
		break;

	case Event::Type::MouseButtonPressed:
		if (io.WantCaptureMouse)
		{
			io.MouseDown[e.button.button] = true;
			return true;
		}
		break;

	case Event::Type::MouseButtonReleased:
		if (io.WantCaptureMouse)
		{
			io.MouseDown[e.button.button] = false;
			return true;
		}
		break;

	case Event::Type::MouseMoved:
		io.MousePos = ImVec2((float)e.mouse.x, (float)e.mouse.y);
		break;

	case Event::Type::MouseScrolled:
		if (io.WantCaptureMouse)
		{
			io.MouseWheel += (float)e.scroll.y_offset;
			io.MouseWheelH += (float)e.scroll.x_offset;
			return true;
		}
		break;

	case Event::Type::WindowResized:
		io.DisplaySize = ImVec2((float)e.window.width, (float)e.window.height);
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		break;
	}

	return false;
}

bool ImGuiPanel::IsActive()
{
	return m_ShowMainWindow;
}