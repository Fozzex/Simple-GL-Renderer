#include "Core/Graphics/Texture2D.h"

Texture2D::Texture2D(const std::string& path)
{
	GLCall(glGenTextures(1, &m_ID));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_ID));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	stbi_set_flip_vertically_on_load(1);
	unsigned char* data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channels, 0);

	if (data)
	{
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));
	}

	stbi_image_free(data);
}

Texture2D::~Texture2D()
{
	GLCall(glDeleteTextures(1, &m_ID));
}

void Texture2D::Bind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, m_ID));
}