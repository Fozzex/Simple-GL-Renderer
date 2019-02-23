#include "VertexShader.h"

VertexShader::VertexShader(const std::string& path)
	: Shader(path)
{
	this->Compile();
}

VertexShader::~VertexShader()
{
}

void VertexShader::Compile()
{
	m_ID = glCreateShader(GL_VERTEX_SHADER);

	const char* source = m_Source.c_str();
	GLCall(glShaderSource(m_ID, 1, &source, nullptr));

	GLCall(glCompileShader(m_ID));
	GLint success;
	GLchar log[512];

	GLCall(glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success));
	if (!success)
	{
		GLCall(glGetShaderInfoLog(m_ID, 512, nullptr, log));
		ASSERT(false, "Failed to compile Vertex Shader\n" << log);
	}
}