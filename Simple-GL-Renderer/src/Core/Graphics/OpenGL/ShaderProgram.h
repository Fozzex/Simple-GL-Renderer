#pragma once
#include <string>

#include "Shader.h"
#include "Core/Util/Singleton.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

class ShaderProgram : public Singleton
{
public:

	ShaderProgram();
	~ShaderProgram();

	void Attach(Shader* shader);
	void Link();
	inline void Bind() const { glUseProgram(m_ID); }

	void SetMat4(const std::string& name, const glm::mat4& value) const;

private:

	GLint GetUniformLocation(const std::string& name) const;

private:

	GLuint m_ID;

};