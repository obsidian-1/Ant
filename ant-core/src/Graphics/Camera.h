#pragma once
#include "../deps.h"

namespace ant
{
    //Base camera class
    class Camera
    {
    public:
        int id;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;
        glm::vec3 m_position;
        glm::vec3 m_direction;
        glm::vec3 m_upVector;
        float fov;
        float roll;
    };

}