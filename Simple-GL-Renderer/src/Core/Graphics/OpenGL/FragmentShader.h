#pragma once
#include "Shader.h"

class FragmentShader : public Shader
{
public:

	FragmentShader(const std::string& path);
	~FragmentShader();

	void Compile() override;

};