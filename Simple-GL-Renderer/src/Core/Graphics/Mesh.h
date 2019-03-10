#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "OpenGL/ShaderProgram.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/VertexArray.h"
#include "Core/Graphics/Texture2D.h"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 colour;
	glm::vec2 textureCoord;
};

class Mesh
{
public:

	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLushort>& indices);
	~Mesh();

	void UpdateModelMatrix();
	void Draw();

	inline void SetTexture(Texture2D* texture) { m_Texture = texture; }
	inline Texture2D* GetTexture() const { return m_Texture; }

	inline void ResetModelMatrix() { m_ModelMatrix = glm::mat4(1); }
	inline glm::mat4 GetModelMatrix() const { return m_ModelMatrix; }

	inline void SetPosition(const glm::vec3& position) { m_Position = position; }
	inline glm::vec3 GetPosition() const { return m_Position; }

	void SetRotation(float angle, const glm::vec3& direction);

	inline void Move(const glm::vec3& offset) { m_Position = m_Position + offset; }

private:

	std::vector<Vertex> m_Vertices;
	std::vector<GLushort> m_Indices;

	VertexBuffer m_VertexBuffer;
	VertexArray m_VertexArray;
	IndexBuffer m_IndexBuffer;

	glm::vec3 m_Position;
	glm::mat4 m_Rotation;

	glm::mat4 m_ModelMatrix;

	Texture2D* m_Texture = nullptr;

};