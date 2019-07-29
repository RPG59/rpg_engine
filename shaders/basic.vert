#version 440 core 

layout(location=0) in vec4 position;
layout(location=1) in vec4 l_color;
uniform mat4 u_ProjectionMatrix = mat4(1.0);
uniform mat4 u_ModelMatrix = mat4(1.0);
out vec4 pos;
out vec4 color;

void main()
{
	gl_Position = u_ProjectionMatrix * u_ModelMatrix * position;
    	pos = position;
	color = l_color;
  
}

