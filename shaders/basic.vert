#version 440 core 

layout(location=0) in vec4 position;
layout(location=1) in vec2 l_textureCoord;
layout(location=2) in vec4 l_color;

uniform mat4 u_ProjectionMatrix = mat4(1.0);
uniform mat4 u_ModelMatrix = mat4(1.0);

out DATA 
{
    vec4 position;
    vec4 color;
    vec2 textureCoord;
} vs_out;

void main()
{
	gl_Position = u_ProjectionMatrix * u_ModelMatrix * position;
    vs_out.textureCoord = l_textureCoord;
    vs_out.position = u_ModelMatrix * position;
    vs_out.color = l_color;
  
}

