#version 400 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 texCoords;

out vec2 fragmentTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    fragmentTexCoords = texCoords;
    gl_Position = projection * view * model * vec4(vertexPosition, 1.0f);
}