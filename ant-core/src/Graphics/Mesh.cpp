#pragma once
#include "../deps.h"
#include "./Vertex.h"
#include "./Texture.h"
#include "./Shader.h"
#include "./Mesh.h"
namespace ant
{

    Mesh::Mesh(std::vector<Vertex> in_vertices,
               std::vector<unsigned int> in_indices,
               std::vector<Texture> in_textures)
    {
        this->vertices = in_vertices;
        this->indices = in_indices;
        this->textures = in_textures;
        setupMesh();
    }
    Mesh::Mesh(){}

    void Mesh::Draw(Shader *in_shader, GLenum mode = GL_TRIANGLES)
    {
        in_shader->use();
        for (size_t i = 0; i < textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
            in_shader->setInt(textures[i].name.c_str(), i);
        }
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(VAO);
        glDrawElements(mode, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void Mesh::setupMesh()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size() * sizeof(unsigned int),
                     &indices[0],
                     GL_STATIC_DRAW);

        //Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);

        //TexCoords
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, TexCoords));

        //Normals
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, Normal));

        glBindVertexArray(0);
    }
}