#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
	GLCall(glGenBuffers(1, &m_ID));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_ID));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
}

void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void IndexBuffer::BufferData(GLsizei bytes, GLuint count, const void* data, GLenum drawUsage)
{
	this->Bind();
	m_Count = count;

	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bytes, data, drawUsage));
}