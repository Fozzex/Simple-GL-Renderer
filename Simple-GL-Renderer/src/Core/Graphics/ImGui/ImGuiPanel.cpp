#include "ImGuiPanel.h"
#include "Core/Input/EventDispatcher.h"

ImGuiPanel::ImGuiPanel()
{
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplOpenGL3_Init("#version 330");

	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

	io.KeyMap[ImGuiKey_Tab]		    = static_cast<int>(Keyboard::KeyCode::Tab);
	io.KeyMap[ImGuiKey_LeftArrow]   = static_cast<int>(Keyboard::KeyCode::Left);
	io.KeyMap[ImGuiKey_RightArrow]  = static_cast<int>(Keyboard::KeyCode::Right);
	io.KeyMap[ImGuiKey_UpArrow]	    = static_cast<int>(Keyboard::KeyCode::Up);
	io.KeyMap[ImGuiKey_DownArrow]   = static_cast<int>(Keyboard::KeyCode::Down);
	io.KeyMap[ImGuiKey_PageUp]	    = static_cast<int>(Keyboard::KeyCode::PageUp);
	io.KeyMap[ImGuiKey_PageDown]    = static_cast<int>(Keyboard::KeyCode::PageDown);
	io.KeyMap[ImGuiKey_Home]	    = static_cast<int>(Keyboard::KeyCode::Home);
	io.KeyMap[ImGuiKey_End]		    = static_cast<int>(Keyboard::KeyCode::End);
	io.KeyMap[ImGuiKey_Insert]	    = static_cast<int>(Keyboard::KeyCode::Insert);
	io.KeyMap[ImGuiKey_Delete]	    = static_cast<int>(Keyboard::KeyCode::Delete);
	io.KeyMap[ImGuiKey_Backspace]   = static_cast<int>(Keyboard::KeyCode::BackSpace);
	io.KeyMap[ImGuiKey_Space]	    = static_cast<int>(Keyboard::KeyCode::Space);
	io.KeyMap[ImGuiKey_Enter]	    = static_cast<int>(Keyboard::KeyCode::Enter);
	io.KeyMap[ImGuiKey_Escape]	    = static_cast<int>(Keyboard::KeyCode::Escape);
	io.KeyMap[ImGuiKey_A]		    = static_cast<int>(Keyboard::KeyCode::A);
	io.KeyMap[ImGuiKey_C]		    = static_cast<int>(Keyboard::KeyCode::C);
	io.KeyMap[ImGuiKey_V]		    = static_cast<int>(Keyboard::KeyCode::V);
	io.KeyMap[ImGuiKey_X]		    = static_cast<int>(Keyboard::KeyCode::X);
	io.KeyMap[ImGuiKey_Y]		    = static_cast<int>(Keyboard::KeyCode::Y);
	io.KeyMap[ImGuiKey_Z]		    = static_cast<int>(Keyboard::KeyCode::Z);
}

void ImGuiPanel::StartFrame()
{
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2((float)Window::Get()->GetWidth(), (float)Window::Get()->GetHeight());

	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();
}

void ImGuiPanel::Render(float dt)
{
	ImGuiIO& io = ImGui::GetIO();
	io.DeltaTime = dt;

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());  
}

bool ImGuiPanel::IsActive()
{
	return m_ShowMainWindow;
}

bool ImGuiPanel::OnKeyPressed(KeyPressedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureKeyboard)
	{
		io.KeysDown[(int)e.GetKeyCode()] = true;

		io.KeyCtrl = Keyboard::KeyPressed(Keyboard::KeyCode::LeftCtrl) || Keyboard::KeyPressed(Keyboard::KeyCode::RightCtrl);
		io.KeyShift = Keyboard::KeyPressed(Keyboard::KeyCode::LeftShift) || Keyboard::KeyPressed(Keyboard::KeyCode::RightShift);
		io.KeyAlt = Keyboard::KeyPressed(Keyboard::KeyCode::LeftAlt) || Keyboard::KeyPressed(Keyboard::KeyCode::RightAlt);
		io.KeySuper = Keyboard::KeyPressed(Keyboard::KeyCode::LeftSuper) || Keyboard::KeyPressed(Keyboard::KeyCode::RightSuper);

		return true;
	}

	return false;
}

bool ImGuiPanel::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);

	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnKeyPressed));
	dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnKeyReleased));
	dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnKeyTyped));
	dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnMousePressed));
	dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnMouseReleased));
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnMouseMoved));
	dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnMouseScrolled));
	dispatcher.Dispatch<WindowResizedEvent>(BIND_EVENT_CALLBACK(ImGuiPanel::OnWindowResized));

	return dispatcher.Handled();
}

bool ImGuiPanel::OnKeyReleased(KeyReleasedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureKeyboard)
	{
		io.KeysDown[(int)e.GetKeyCode()] = false;
		return true;
	}

	return false;
}

bool ImGuiPanel::OnKeyTyped(KeyTypedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantTextInput)
	{
		io.AddInputCharacter(e.GetKey());
		return true;
	}

	return false;
}

bool ImGuiPanel::OnMousePressed(MouseButtonPressedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureMouse)
	{
		io.MouseDown[(int)e.GetMouseButton()] = true;
		return true;
	}

	return false;
}

bool ImGuiPanel::OnMouseReleased(MouseButtonReleasedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureMouse)
	{
		io.MouseDown[(int)e.GetMouseButton()] = false;
		return true;
	}

	return false;
}

bool ImGuiPanel::OnMouseMoved(MouseMovedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MousePos = ImVec2((float)e.GetX(), (float)e.GetY());

	return false;
}

bool ImGuiPanel::OnMouseScrolled(MouseScrolledEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureMouse)
	{
		io.MouseWheel += (float)e.GetYOffset();
		io.MouseWheelH += (float)e.GetXOffset();
		return true;
	}

	return false;
}

bool ImGuiPanel::OnWindowResized(WindowResizedEvent& e)
{
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2((float)e.GetWidth(), (float)e.GetHeight());
	io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

	return false;
}