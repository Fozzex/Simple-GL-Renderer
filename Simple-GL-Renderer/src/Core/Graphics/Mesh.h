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
	void Draw();

private:

	VertexArray m_VertexArray;
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;

	std::vector<Vertex> m_Vertices;
	std::vector<GLushort> m_Indices;

};