#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec3 v_Position;
out vec3 v_Normal;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0);
	v_Position = vec3(u_Model * vec4(position, 1.0));
	v_Normal = normal;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Position;
in vec3 v_Normal;

uniform vec3 u_LightPosition;
uniform vec3 u_LightColor;
uniform vec3 u_Color;

void main()
{
	vec3 lightDirection = u_LightPosition - v_Position;
	float lightDistance = sqrt(length(lightDirection)) / 22.f;
	lightDirection = normalize(lightDirection);
	float diffuse = max(dot(lightDirection, v_Normal), 0.0) / lightDistance;
	color = vec4(u_Color * u_LightColor  * diffuse, 1.0);
}
