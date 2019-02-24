#pragma once
#include "Shader.h"
#include "Core/Util/Singleton.h"

class ShaderProgram : public Singleton
{
public:

	ShaderProgram();
	~ShaderProgram();

	void Attach(Shader* shader);
	void Link();
	inline void Bind() const { glUseProgram(m_ID); }

private:

	GLuint m_ID;

};