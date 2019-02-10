#include "Renderer/Window.h"

int main()
{
	Window window("OpenGL Renderer", 1280, 720);

	while (!window.Closed())
	{
		window.StartFrame();

		window.EndFrame();
	}
} 