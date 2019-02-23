#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	m_ID = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_ID);
}

void ShaderProgram::Attach(Shader* shader)
{
	glAttachShader(m_ID, shader->GetID());
}

void ShaderProgram::Link()
{
	glLinkProgram(m_ID);

	GLint success;
	GLchar log[512];

	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_ID, 512, nullptr, log);
		ASSERT(false, "Failed to link Shader Program\n" << log);
	}

	this->Bind();
}