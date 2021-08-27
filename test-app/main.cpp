#include "../ant-core/ant.h"

float sensitivity = 0.03f;
double lastX = 400.f;
double lastY = 300.f;
double yaw = 99.9999f;
double pitch = 0.0f;
float last_angle;
float yaw_r;

ant::PerspectiveCamera *cam = NULL;

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{

    float x_offset = -xpos + lastX;
    float y_offset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;
    x_offset *= sensitivity;
    y_offset *= sensitivity * 0.5f;
    yaw += x_offset;
    pitch += y_offset;
    if (pitch > 89.f)
    {
        pitch = 89.f;
    }
    if (pitch < -89.f)
    {
        pitch = -89.f;
    }
    glm::vec3 _direction;
    yaw_r = -glm::radians(yaw);
    _direction.x = cos(glm::radians(-yaw)) * cos(glm::radians(-pitch));
    _direction.y = sin(glm::radians(-pitch));
    _direction.z = sin(glm::radians(-yaw)) * cos(glm::radians(-pitch));
    cam->lookInDir(glm::normalize(_direction));
};

class OpenGl_Layer : public ant::Layer
{
public:
    ant::Application *app;
    ant::Shader *main_shader;
    std::vector<ant::Texture> tex_vec;
    ant::Cube *cube;
    
    OpenGl_Layer(ant::Application *_app, std::string _title) : Layer(_title), app(_app)
    {
        LOG_DEBUG(_title<<" Initialised");
    }

    virtual void onAttach() override
    {
        main_shader = new ant::Shader("shaders/vertex.glsl", "shaders/fragment.glsl", NULL);
        cube = new ant::Cube("./res/download.jpeg");
        cam = new ant::PerspectiveCamera(glm::vec3(0.0f, 0.0f, 20.0f), glm::vec3(0.0f, 0.0f, -1.0f));
        cam->lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
        glfwSetInputMode(app->m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        glfwSetInputMode(app->m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetCursorPosCallback(app->m_window, cursor_position_callback);
    }

    virtual void onUpdate(float dt) override
    {
        if (glfwGetKey(app->m_window, GLFW_KEY_S) == GLFW_PRESS)
        {
            cam->moveCam(cam->m_direction * -0.3f);
        }
        if (glfwGetKey(app->m_window, GLFW_KEY_W) == GLFW_PRESS)
        {
            cam->moveCam(cam->m_direction * +0.3f);
        }
        if (glfwGetKey(app->m_window, GLFW_KEY_A) == GLFW_PRESS)
        {
            cam->moveCam(cam->getCamRight()*0.3f);
        }
        if (glfwGetKey(app->m_window, GLFW_KEY_D) == GLFW_PRESS)
        {
            cam->moveCam(cam->getCamRight()*-0.3f);
        }
        if (glfwGetKey(app->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(app->m_window, GLFW_TRUE);
        }



        main_shader->setMat4("projectionMatrix", cam->m_projectionMatrix);
        main_shader->setMat4("viewMatrix", cam->m_viewMatrix);
        cube->Draw(main_shader);
    }
};

int main(void)
{
    ant::Application app("Main-App");
    ant::Sprite::app = &app;
    OpenGl_Layer glLayer(&app, "GL-Layer");
    app.pushLayer(&glLayer);
    app.Run();
}
