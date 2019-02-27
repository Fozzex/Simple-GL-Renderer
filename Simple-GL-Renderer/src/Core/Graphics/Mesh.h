#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "OpenGL/ShaderProgram.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/VertexArray.h"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 colour;
};

class Mesh
{
public:

	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices);
	~Mesh();
	
	static void LayoutElements(const VertexBuffer* buffer);

	inline const std::vector<Vertex>* GetVertices() const { return &m_Vertices; }
	inline const std::vector<GLushort>* GetIndices() const { return &m_Indices; }

	inline void SetVertexBuffer(VertexBuffer* buffer) { m_VertexBuffer = buffer; }
	inline VertexBuffer* GetVertexBuffer() const { return m_VertexBuffer; }

	inline void SetIndexBuffer(IndexBuffer* buffer) { m_IndexBuffer = buffer; }
	inline IndexBuffer* GetIndexBuffer() const { return m_IndexBuffer; }

	inline const VertexArray* GetVertexArray() const { return &m_VertexArray; }

private:

	const std::vector<Vertex>& m_Vertices;
	const std::vector<GLushort>& m_Indices;

	VertexBuffer* m_VertexBuffer;
	IndexBuffer* m_IndexBuffer;
	VertexArray m_VertexArray;

};