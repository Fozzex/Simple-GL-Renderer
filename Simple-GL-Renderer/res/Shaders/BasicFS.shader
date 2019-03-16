#version 330 core

out vec4 pixelColour;

in vec3 fColour;
in vec2 fTexCoord;
in vec3 fNormal;

in vec4 fNoTexture;

in vec3 fFragPosition;

uniform sampler2D uTexture;

uniform float uAmbientStrength;
uniform float uSpecularStrength;

uniform vec3 uLightPosition;
uniform vec3 uLightColour;
uniform vec3 uViewPosition;

void main()
{
	vec3 nNormal = normalize(fNormal);
	vec3 nLightDir = normalize(uLightPosition - fFragPosition);

	vec3 nViewDir = normalize(uViewPosition - fFragPosition);
	vec3 nReflectDir = reflect(-nLightDir, nNormal);

	float diffuseStrength = max(dot(nNormal, nLightDir), 0.0);
	float specular = pow(max(dot(nViewDir, nReflectDir), 0.0), 128);

	vec4 texResult = texture(uTexture, fTexCoord);
	texResult = clamp(texResult + fNoTexture, 0.0, 1.0);
	texResult *= vec4(fColour, 1.0);
	texResult *= vec4(((uAmbientStrength * uLightColour) + (diffuseStrength * uLightColour) + (specular * uSpecularStrength * uLightColour)), 1.0);

	pixelColour = texResult;
}