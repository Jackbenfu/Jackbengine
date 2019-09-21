#version 330 core

in vec3 vColor;
in vec2 vTexcoord;

uniform sampler2D uTexture;

out vec4 outColor;

void main()
{
    outColor = texture(uTexture, vTexcoord) * vec4(vColor, 1.0);
}
