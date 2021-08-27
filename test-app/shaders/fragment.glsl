#version 450 core

uniform sampler2D spriteTex;
in vec2 vs_texcoord;
out vec4 fs_color;

void main(void) 
{
	fs_color=texture(spriteTex,vec2(1.0f-vs_texcoord.x,1.0f-vs_texcoord.y));
}