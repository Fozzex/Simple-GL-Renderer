#pragma once
#include <memory>
#include <array>
#include <GL/glew.h>

#include "Util/Singleton.h"
#include "Core/Window/Window.h"
#include "Core/Graphics/SceneManager.h"
#include "Core.h"

#include "Core/Graphics/VertexShader.h"
#include "Core/Graphics/FragmentShader.h"
#include "Core/Graphics/ShaderProgram.h"

class Application : public Singleton
{
	static Application* s_Instance;
public:

	Application(const std::string& title, int width, int height);
	virtual ~Application();

	void RegisterScene(Scene* scene);

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;
	SceneManager m_SceneManager;

	// TEMPORARY
	std::unique_ptr<VertexShader>   m_VertexShader;
	std::unique_ptr<FragmentShader> m_FragmentShader;

	std::unique_ptr<ShaderProgram> m_Program;

	GLuint m_VBO, m_VAO, m_EBO;

	std::array<GLfloat, 12> m_QuadData =
	{
		-0.5f,  0.5f, 0.0f, // TOP LEFT
		 0.5f,  0.5f, 0.0f, // TOP RIGHT
		 0.5f, -0.5f, 0.0f, // BOTTOM RIGHT
		-0.5f, -0.5f, 0.0f  // BOTTOM LEFT
	};

	std::array<GLuint, 6> m_IndexData =
	{
		0, 1, 3,
		1, 2, 3
	};
};