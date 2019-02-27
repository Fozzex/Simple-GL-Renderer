#pragma once
#include <GL/glew.h>
#include "Core/Core.h"

class IndexBuffer
{
public:

	IndexBuffer();
	~IndexBuffer();

	void BufferData(GLsizei bytes, GLuint count, const void* data, GLenum drawUsage);

	void Bind() const;
	void Unbind() const;

	inline GLuint GetCount() const { return m_Count; }

private:

	GLuint m_ID;
	GLuint m_Count;

};