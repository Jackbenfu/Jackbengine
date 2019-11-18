precision mediump float;

uniform sampler2D uTexture;

in vec3 vColor;
in vec2 vTexcoord;

out vec4 outColor;

void main()
{
    outColor = texture(uTexture, vTexcoord) * vec4(vColor, 1.0);
}
