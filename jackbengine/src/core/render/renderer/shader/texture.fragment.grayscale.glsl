precision mediump float;

in vec3 vColor;
in vec2 vTexcoord;

uniform sampler2D uTexture;

out vec4 outColor;

void main()
{
    vec4 color = texture(uTexture, vTexcoord);
    float gray = dot(color.rgb, vec3(0.299, 0.587, 0.114));
    outColor = vec4(vec3(gray), 1.0);
}
