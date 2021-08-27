#pragma once
#include "../deps.h"
#include "./Mesh.h"
#include "./Shader.h"
#include "../Application.h"


namespace ant
{
    class Sprite
    {
    public:
        int width;
        int height;
        glm::vec2 pos; //Coordinates of center of image
        float angle;   //in radians
        static Application* app;
        Mesh *m_mesh;
    private:
        glm::mat4 m_modelMatrix;
        int frame_width,frame_height;
        std::vector<Texture> texture_vec;
        Texture2D *tex;
    public:
        Sprite(const char *image_path, int _width, int _height, glm::vec2 _pos = glm::vec2(0.0f, 0.0f), float _angle = 0.0f);
        void Draw(Shader *_shader);
        void MoveTo(glm::vec2 new_pos){};
        void MoveBy(glm::vec2 delta_pos){};
        void RotateBy(float delta_angle);
    };
}