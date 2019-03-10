#version 330 core

out vec4 pixelColour;

in vec3 fColour;
in vec2 fTexCoord;
in vec3 fNormal;

in vec4 fNoTexture;

in vec3 fFragPos;

uniform sampler2D uTexture;
uniform float uAmbientStrength;
uniform vec3 uLightPosition;
uniform vec3 uLightColour;

void main()
{
	vec3 nNormal = normalize(fNormal);
	vec3 nLightDir = normalize(uLightPosition - fFragPos);

	float diffuseStrength = max(dot(nNormal, nLightDir), 0.0);

	vec4 texResult = texture(uTexture, fTexCoord);
	texResult = clamp(texResult + fNoTexture, 0.0, 1.0);
	texResult *= vec4(fColour, 1.0) * vec4(((uAmbientStrength * uLightColour) + (diffuseStrength * uLightColour)), 1.0);

	pixelColour = texResult;
}