#version 400 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    fragmentColor = vertexColor;
    gl_Position = projection * view * model * vec4(vertexPosition, 1.0f);
}