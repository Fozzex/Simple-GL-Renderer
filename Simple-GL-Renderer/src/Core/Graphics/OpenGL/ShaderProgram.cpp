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

GLint ShaderProgram::GetUniformLocation(const std::string& name) const
{
	return glGetUniformLocation(m_ID, name.c_str());
}

void ShaderProgram::SetVec3(const std::string& name, const glm::vec3& value) const
{
	GLCall(glUniform3fv(this->GetUniformLocation(name), 1, glm::value_ptr(value)));
}

void ShaderProgram::SetMat4(const std::string& name, const glm::mat4& value) const
{
	GLCall(glUniformMatrix4fv(this->GetUniformLocation(name), 1, false, glm::value_ptr(value)));
}

void ShaderProgram::SetInt(const std::string& name, int value) const
{
	GLCall(glUniform1i(this->GetUniformLocation(name), value));
}

void ShaderProgram::SetFloat(const std::string& name, float value) const
{
	GLCall(glUniform1f(this->GetUniformLocation(name), value));
}