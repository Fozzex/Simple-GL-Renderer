#version 330 core

out vec4 pixelColour;

in vec3 fColour;
in vec2 fTexCoord;

in vec4 fNoTexture;

uniform sampler2D uTexture;
uniform float uAmbientStrength;

void main()
{
	vec4 texResult = texture(uTexture, fTexCoord);
	texResult = clamp(texResult + fNoTexture, 0.0, 1.0);
	texResult *= vec4(fColour, 1.0) * uAmbientStrength;

	pixelColour = texResult;
}