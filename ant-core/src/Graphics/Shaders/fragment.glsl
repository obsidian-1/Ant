#version 440 core

struct Material 
{
    
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
};

in vec2 vs_texcoord;
uniform Material material;
out vec4 fs_color;

void main()
{

    fs_color=texture(material.texture_diffuse1,vs_texcoord);
}