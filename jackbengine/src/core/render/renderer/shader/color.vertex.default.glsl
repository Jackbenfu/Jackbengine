precision mediump float;

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inColor;

out vec3 vColor;

void main()
{
    gl_Position = vec4(inPosition, 1.0);
    vColor = inColor;
}
