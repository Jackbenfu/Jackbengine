#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 inTexcoord;

out vec3 vColor;
out vec2 vTexcoord;

void main()
{
    gl_Position = vec4(inPosition, 1.0);
    vColor = inColor;
    vTexcoord = vec2(inTexcoord.x, -inTexcoord.y);
}
