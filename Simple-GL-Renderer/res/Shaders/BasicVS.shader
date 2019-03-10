#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColour;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in vec3 aNormal;

out vec3 fColour;
out vec2 fTexCoord;
out vec4 fNoTexture;
out vec3 fNormal;

out vec3 fFragPos;

uniform mat4 uModelMatrix = mat4(1);
uniform mat4 uProjMatrix = mat4(1);
uniform mat4 uViewMatrix = mat4(1);

uniform int uNoTexture = 0;

void main()
{
	fColour = aColour;
	fTexCoord = aTexCoord;
	fNormal = aNormal;
	gl_Position = uProjMatrix * uViewMatrix * uModelMatrix * vec4(aPosition, 1.0);

	fFragPos = vec3(uModelMatrix * vec4(aPosition, 1.0));

	if (uNoTexture == 1)
		fNoTexture = vec4(1.0, 1.0, 1.0, 1.0);
	else
		fNoTexture = vec4(0.0, 0.0, 0.0, 0.0);
}