#pragma once
#include "../deps.h"
#include "./Mesh.h"
#include "./Shader.h"
namespace ant
{
    class Plane
    {
    public:
        glm::vec3 m_scale=glm::vec3(1.0f,1.0f,1.0f);
        glm::vec3 m_position=glm::vec3(0.0f,0.0f,0.0f);
        Plane(const char* tex);
        void Draw(Shader* _shader);
    private:
        Mesh*m_mesh;
    };
}