#version 330 core

out vec4 pixelColour;

in vec3 fColour;

void main()
{
	pixelColour = vec4(fColour, 1.0);
}