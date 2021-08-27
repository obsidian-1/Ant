#pragma once
#include "../deps.h"
#include "./Vertex.h"
#include "./Texture.h"
#include "./Shader.h"

namespace ant
{
    class Mesh
    {
    public:
        
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        Mesh(
            std::vector<Vertex> in_vertices,
            std::vector<unsigned int> in_indices,
            std::vector<Texture> in_textures
            );
        Mesh();
        void Draw(Shader *in_shader, GLenum mode);

    private:
        unsigned int VAO, VBO, EBO;
        void setupMesh();
    };
}
