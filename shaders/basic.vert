#version 440 core 

layout(location=0) in vec4 position;
uniform mat4 u_ProjectionMatrix = mat4(1.0);
uniform mat4 u_ModelMatrix = mat4(1.0);
out vec4 pos;

void main()
{
	gl_Position = u_ProjectionMatrix * u_ModelMatrix * position;
    pos = position;
  
}

