#pragma once
#include "../deps.h"
#include "./Mesh.h"
#include "./Shader.h"
#include "./Texture.h"
#include "./Sprite.h"

namespace ant
{
    Sprite::Sprite(const char *image_path, int _width, int _height, glm::vec2 _pos , float _angle)
    {
        width=800;
        height=600;
        float __width = _width;//((float)_width) / ((float)this->width);
        float __height = _height;//((float)_height) / ((float)this->height);

        std::vector<Vertex> vertex_vec = {
            {glm::vec3(-__width, __height, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(__width, __height, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(-__width, -__height, 0.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(__width, -__height, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)}};
        std::vector<unsigned int> indices_vec = {
            0, 2, 3, 0, 3, 1};

        tex=new Texture2D(image_path, GL_TEXTURE_2D);

        texture_vec = {{tex->getID(),"spriteTex"}};
        m_mesh = new Mesh(vertex_vec, indices_vec, texture_vec);
        pos = _pos;
        angle = _angle;
        m_modelMatrix=glm::mat4(1.0f);
        // m_modelMatrix=glm::translate(m_modelMatrix,glm::vec3(_pos.x,_pos.y,0.0f));
        m_modelMatrix=glm::rotate(m_modelMatrix,_angle,glm::vec3(0.0f,0.0f,1.0f));
        m_modelMatrix=glm::scale(m_modelMatrix,glm::vec3(0.1f,0.1f,0.0f));
    }
    void Sprite::Draw(Shader *_shader)
    {
        _shader->use();
        _shader->setMat4("modelMatrix",m_modelMatrix);
        m_mesh->Draw(_shader,GL_TRIANGLES);
    }

    void Sprite::RotateBy(float delta_angle)
    {
        m_modelMatrix=glm::rotate(m_modelMatrix,delta_angle,glm::vec3(0.0f,0.0f,1.0f));
    }






    Application* Sprite::app=NULL;
}