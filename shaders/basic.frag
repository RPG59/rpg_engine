#version 440 

layout(location=0) out vec4 fragColor;

in DATA 
{
    vec4 position;
    vec4 color;
    float tid;
    vec2 textureCoord;
} fs_in;

uniform vec2 light_pos;
uniform sampler2D textures[32];



void main()
{
    float intensity = 1.0 / length(fs_in.position.xy - light_pos);
    vec4 texColor = fs_in.color;
    if(fs_in.tid > .0)
    {
    	int tid = int(fs_in.tid - 0.5);
	texColor = texture(textures[tid], fs_in.textureCoord);
    }
    fragColor = texColor * intensity;

}

