#pragma once
#include "../deps.h"
#include "./Cube.h"
#include "./Mesh.h"
#include "./Vertex.h"
#include "./Texture.h"
#include "./Texture2D.h"

std::vector<Vertex> cube_vertices = {
    // Pos                                    //Texture            //Normals
    {glm::vec3(-1.0f, 1.0f, 1.f), glm::vec2(0.f, 1.f), glm::vec3(0.f, 0.f, +1.f)},
    {glm::vec3(-1.0f, -1.0f, 1.f), glm::vec2(0.f, 0.f), glm::vec3(0.f, 0.f, +1.f)},
    {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec2(1.f, 0.f), glm::vec3(0.f, 0.f, +1.f)}, //Front Face
    {glm::vec3(1.0f, 1.0f, 1.f), glm::vec2(1.f, 1.f), glm::vec3(0.f, 0.f, +1.f)},

    {glm::vec3(-1.0f, 1.0f, -1.f), glm::vec2(0.f, 1.f), glm::vec3(0.f, 0.f, -1.f)},
    {glm::vec3(-1.0f, -1.0f, -1.f), glm::vec2(0.f, 0.f), glm::vec3(0.f, 0.f, -1.f)},
    {glm::vec3(1.0f, -1.0f, -1.f), glm::vec2(1.f, 0.f), glm::vec3(0.f, 0.f, -1.f)}, //Front Face
    {glm::vec3(1.0f, 1.0f, -1.f), glm::vec2(1.f, 1.f), glm::vec3(0.f, 0.f, -1.f)},

    {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.f, 1.f), glm::vec3(+1.0f, 0.0f, 0.0f)},
    {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec2(0.f, 0.f), glm::vec3(+1.0f, 0.0f, 0.0f)},
    {glm::vec3(1.0f, -1.0f, -1.f), glm::vec2(1.f, 0.f), glm::vec3(+1.0f, 0.0f, 0.0f)}, //right Face
    {glm::vec3(1.0f, 1.0f, -1.f), glm::vec2(1.f, 1.f), glm::vec3(+1.0f, 0.0f, 0.0f)},

    {glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec2(0.f, 1.f), glm::vec3(-1.0f, 0.0f, 0.0f)},
    {glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec2(0.f, 0.f), glm::vec3(-1.0f, 0.0f, 0.0f)},
    {glm::vec3(-1.0f, -1.0f, -1.f), glm::vec2(1.f, 0.f), glm::vec3(-1.0f, 0.0f, 0.0f)}, //right Face
    {glm::vec3(-1.0f, 1.0f, -1.f), glm::vec2(1.f, 1.f), glm::vec3(-1.0f, 0.0f, 0.0f)},

    {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f)},
    {glm::vec3(1.0f, 1.0f, -1.f), glm::vec2(0.f, 0.f), glm::vec3(0.0f, 1.0f, 0.0f)},
    {glm::vec3(-1.0f, 1.0f, -1.f), glm::vec2(1.f, 0.f), glm::vec3(0.0f, 1.0f, 0.0f)}, //TOP Face
    {glm::vec3(-1.0f, 1.0f, 1.f), glm::vec2(1.f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f)},

    {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec2(0.f, 1.f), glm::vec3(0.0f, -1.0f, 0.0f)},
    {glm::vec3(1.0f, -1.0f, -1.f), glm::vec2(0.f, 0.f), glm::vec3(0.0f, -1.0f, 0.0f)},
    {glm::vec3(-1.0f, -1.0f, -1.f), glm::vec2(1.f, 0.f), glm::vec3(0.0f, -1.0f, 0.0f)}, //Bottom Face
    {glm::vec3(-1.0f, -1.0f, 1.f), glm::vec2(1.f, 1.f), glm::vec3(0.0f, -1.0f, 0.0f)}};

std::vector<unsigned int> indices = {0, 1, 2, 0, 2, 3, 7, 6, 4, 6, 5, 4, 8, 9, 10, 10, 11, 8, 12, 15, 14, 14, 13, 12, 16, 17, 18, 18, 19, 16, 20, 23, 22, 22, 21, 20};

namespace ant
{
    Cube::Cube(const char *tex)
    {
        // std::reverse(indices.begin(),indices.end());
        ant::Texture2D _tex(tex, GL_TEXTURE_2D);
        std::vector<Texture> tex_vec = {{_tex.getID(), "cubeTex"}};
        m_mesh = new ant::Mesh(cube_vertices, indices, tex_vec);
    }
    void Cube::Draw(Shader *_shader)
    {
        glm::mat4 m_modelMatrix(1.0f);
        m_modelMatrix=glm::scale(m_modelMatrix,glm::vec3(2.0f,2.0f,2.0f));
        _shader->setMat4("modelMatrix",m_modelMatrix);
        m_mesh->Draw(_shader,GL_TRIANGLES);
    }
}