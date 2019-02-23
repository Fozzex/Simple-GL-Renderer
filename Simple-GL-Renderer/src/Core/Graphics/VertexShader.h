#pragma once
#include "Shader.h"

class VertexShader : public Shader
{
public:

	VertexShader(const std::string& path);
	~VertexShader();

	void Compile() override;

};