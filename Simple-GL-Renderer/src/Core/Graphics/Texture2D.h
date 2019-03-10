#pragma once
#include <string>
#include <glm/glm.hpp>
#include <GL/glew.h>

#include <stb_image.h>

#include "Core/Core.h"

class Texture2D
{
public:

	Texture2D(const std::string& path);
	~Texture2D();

	void Bind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline glm::vec2 GetSize() const { return glm::vec2(m_Width, m_Height); }

	inline GLuint GetID() const { return m_ID; }

private:

	int m_Channels;
	int m_Width, m_Height;
	GLuint m_ID;

};