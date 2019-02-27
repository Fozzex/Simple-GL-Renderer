#include "VertexBuffer.h"
#include "Core/Core.h"

VertexBuffer::VertexBuffer()
{
	GLCall(glGenBuffers(1, &m_ID));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_ID));
}

void VertexBuffer::BufferData(GLsizei bytes, const void* data, GLenum drawUsage)
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, bytes, data, drawUsage));
}

void VertexBuffer::SetElementLayout(GLuint location, GLuint elements, GLsizei byteStride, GLsizei byteOffset) const
{
	this->Bind();
	GLCall(glVertexAttribPointer(location, elements, GL_FLOAT, GL_FALSE, byteStride, (void*)byteOffset));
	GLCall(glEnableVertexAttribArray(location));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}