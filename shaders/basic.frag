#version 440 

layout(location=0) out vec4 fragColor;

in DATA 
{
    vec4 position;
    vec4 color;
    vec2 textureCoord;
} fs_in;

uniform vec2 light_pos;
uniform sampler2D tex;



void main()
{
    float intensity = 1.0 / length(fs_in.position.xy - light_pos);
    fragColor = texture(tex, fs_in.textureCoord) * intensity;
}

