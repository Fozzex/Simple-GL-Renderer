#pragma once
#include <GL/glew.h>

class VertexBuffer
{
public:

	VertexBuffer();
	~VertexBuffer();

	void BufferData(GLsizei bytes, const void* data, GLenum drawUsage) const;
	void SetElementLayout(GLuint location, GLuint elements, GLsizei byteStride, GLsizei byteOffset) const;

	void Bind() const;
	void Unbind() const;

private:

	GLuint m_ID;

};