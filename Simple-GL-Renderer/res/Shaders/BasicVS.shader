#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColour;

out vec3 fColour;

uniform mat4 uModelMatrix = mat4(1);
uniform mat4 uProjMatrix = mat4(1);
uniform mat4 uViewMatrix = mat4(1);

void main()
{
	fColour = aColour;
	gl_Position = uProjMatrix * uViewMatrix * uModelMatrix * vec4(aPosition, 1.0);
}