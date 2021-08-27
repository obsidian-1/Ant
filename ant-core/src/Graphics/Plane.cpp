#pragma once
#include "../deps.h"
#include "./Plane.h"
#include "./Mesh.h"
#include "./Vertex.h"
#include "./Texture.h"
#include "./Texture2D.h"

std::vector<Vertex> plane_vertices = {
    // Pos                                    //Texture            //Normals
    {glm::vec3(1.0f, -1.0f, 1.0f), glm::vec2(0.f, 1.f), glm::vec3(0.0f, -1.0f, 0.0f)},
    {glm::vec3(1.0f, -1.0f, -1.f), glm::vec2(0.f, 0.f), glm::vec3(0.0f, -1.0f, 0.0f)},
    {glm::vec3(-1.0f, -1.0f, -1.f), glm::vec2(1.f, 0.f), glm::vec3(0.0f, -1.0f, 0.0f)}, //Bottom Face
    {glm::vec3(-1.0f, -1.0f, 1.f), glm::vec2(1.f, 1.f), glm::vec3(0.0f, -1.0f, 0.0f)}};

std::vector<unsigned int> plane_indices = {0, 1, 2, 0, 2, 3};

namespace ant
{
    Plane::Plane(const char *tex)
    {
        // std::reverse(indices.begin(),indices.end());
        ant::Texture2D _tex(tex, GL_TEXTURE_2D);
        std::vector<Texture> tex_vec = {{_tex.getID(), "cubeTex"}};
        m_mesh = new ant::Mesh(plane_vertices, plane_indices, tex_vec);
    }
    void Plane::Draw(Shader *_shader)
    {
        glm::mat4 m_modelMatrix(1.0f);
        m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(200.0f, 200.0f, 200.0f));
        _shader->setMat4("modelMatrix", m_modelMatrix);
        m_mesh->Draw(_shader, GL_TRIANGLES);
    }
}