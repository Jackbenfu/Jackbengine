#version 330 core

in vec3 color;
in vec2 texcoord;

uniform sampler2D tex;

out vec4 outColor;

void main()
{
    outColor = texture(tex, texcoord) * vec4(color, 1.0);
}
