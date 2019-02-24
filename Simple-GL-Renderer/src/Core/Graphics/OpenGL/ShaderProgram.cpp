#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	m_ID = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	GLCall(glDeleteProgram(m_ID));
}

void ShaderProgram::Attach(Shader* shader)
{
	GLCall(glAttachShader(m_ID, shader->GetID()));
}

void ShaderProgram::Link()
{
	GLCall(glLinkProgram(m_ID));

	GLint success;
	GLchar log[512];

	GLCall(glGetProgramiv(m_ID, GL_LINK_STATUS, &success));
	if (!success)
	{
		GLCall(glGetProgramInfoLog(m_ID, 512, nullptr, log));
		ASSERT(false, "Failed to link Shader Program\n" << log);
	}

	this->Bind();
}