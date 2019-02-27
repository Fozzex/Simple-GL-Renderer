#pragma once
#include <GL/glew.h>
#include <vector>

#include "VertexBuffer.h"
#include "Core/Core.h"

class VertexArray
{
public:

	VertexArray();
	~VertexArray();

	void DrawElements(GLuint count) const;

	void Bind() const;
	void Unbind() const;

private:

	GLuint m_ID;

};