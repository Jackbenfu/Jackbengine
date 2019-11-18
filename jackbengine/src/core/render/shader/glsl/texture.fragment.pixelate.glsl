precision mediump float;

uniform float uPixelResolution;
uniform sampler2D uTexture;

in vec3 vColor;
in vec2 vTexcoord;

out vec4 outColor;

void main()
{
    vec2 uv = round(vTexcoord * uPixelResolution) / uPixelResolution;

    outColor = texture(uTexture, uv) * vec4(vColor, 1.0);
}
