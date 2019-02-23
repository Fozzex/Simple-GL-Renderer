#include "FragmentShader.h"

FragmentShader::FragmentShader(const std::string& path)
	: Shader(path)
{
	this->Compile();
}

FragmentShader::~FragmentShader()
{
}

void FragmentShader::Compile()
{
	m_ID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* source = m_Source.c_str();
	glShaderSource(m_ID, 1, &source, nullptr);

	glCompileShader(m_ID);
	GLint success;
	GLchar log[512];

	glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_ID, 512, nullptr, log);
		ASSERT(false, "Failed to compile Fragment Shader\n" << log);
	}
}