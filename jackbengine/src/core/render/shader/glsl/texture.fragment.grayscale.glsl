precision mediump float;

uniform sampler2D uTexture;

in vec3 vColor;
in vec2 vTexcoord;

out vec4 outColor;

void main()
{
    vec4 color = texture(uTexture, vTexcoord);
    float gray = dot(color.rgb, vec3(0.21, 0.71, 0.07));
    outColor = vec4(vec3(gray), 1.0);
}
