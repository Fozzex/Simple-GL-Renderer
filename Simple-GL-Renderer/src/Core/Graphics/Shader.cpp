#include "Shader.h"

Shader::Shader(const std::string& path)
{
	std::ifstream file(path, std::ios::in);
	ASSERT(file, "Failed to open file: " << path);

	std::stringstream ss;

	ss << file.rdbuf();

	m_Source = ss.str();
}

Shader::~Shader()
{
	GLCall(glDeleteShader(m_ID));
}