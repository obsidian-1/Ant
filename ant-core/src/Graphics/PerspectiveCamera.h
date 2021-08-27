#include "../deps.h"
#include "./Camera.h"

namespace ant
{
    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera(glm::vec3 camPos, glm::vec3 camDir, float fov = 0.785398f)
        {
            m_position = camPos;
            m_direction = camDir;
            camRight = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), camDir));
            m_upVector = glm::cross(camDir, camRight);

            m_projectionMatrix = glm::perspective(fov, 800.0f / 600.0f, 0.1f, 100.0f);
            m_viewMatrix = glm::lookAt(camPos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f));
        }
        PerspectiveCamera()
        {
        }
        PerspectiveCamera(const PerspectiveCamera &cam)
        {
        }
        void lookAt(glm::vec3 target)
        {
            m_viewMatrix = glm::lookAt(m_position, target, m_upVector);
        }
        void lookInDir(glm::vec3 dir)
        {
            m_direction = dir;
            m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, glm::vec3(0.0f, 1.0f, 0.0f));
        }
        void moveCam(glm::vec3 del)
        {
            m_position += del;
            m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, glm::vec3(0.0f, 1.0f, 0.0f));
        }
        glm::vec3 getCamRight()
        {
            return(glm::normalize(glm::cross(glm::vec3(0.0f,1.0f,0.0f),m_direction)));
        }
        glm::vec3 camRight;
    };
}