#version 440 

layout(location=0) out vec4 fragColor;
uniform vec2 light_pos;
in vec4 pos;
in vec4 color;

void main()
{
    float intensity = 1.0 / length(pos.xy - light_pos);
    fragColor = color * intensity; 
}

