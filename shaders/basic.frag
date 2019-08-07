#version 440 

layout(location=0) out vec4 fragColor;

uniform vec2 light_pos;

in DATA 
{
    vec4 position;
    vec4 color;
    vec2 textureCoord;
} fs_in;

uniform sampler2D tex;

void main()
{
    float intensity = 1.0 / length(fs_in.position.xy - light_pos);
    fragColor = fs_in.color * intensity; 
    fragColor = texture(tex, fs_in.textureCoord);
}

