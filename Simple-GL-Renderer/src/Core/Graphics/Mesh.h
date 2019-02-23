#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "ShaderProgram.h"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 colour;
};

class Mesh
{
public:

	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices);
	void Draw() const;

private:

	GLuint m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	std::vector<Vertex> m_Vertices;
	std::vector<GLushort> m_Indices;

};