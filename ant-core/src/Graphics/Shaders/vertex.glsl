#version 440 core

layout (location=0) in vec3 vertex_position;
layout(location = 1) in vec2 vertex_texcoord;

out vec2 vs_texcoord;

void main(){
    vs_texcoord = vertex_texcoord;
    gl_Position =vec4(vertex_position,1.0f);
}