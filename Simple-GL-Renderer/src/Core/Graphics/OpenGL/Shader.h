#pragma once
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Core/Core.h"

class Shader
{
public:

	Shader(const std::string& path);
	virtual ~Shader();

	inline GLuint GetID() const { return m_ID; }

protected:

	virtual void Compile() = 0;

protected:

	GLuint m_ID;
	std::string m_Source;

};