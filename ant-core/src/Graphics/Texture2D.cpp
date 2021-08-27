#include "../deps.h"
#include "./Image.h"
#include "Texture2D.h"

namespace ant
{
    Texture2D::Texture2D(const char *fileName, GLenum type = GL_TEXTURE_2D)
    {
        this->type = type;
        Image img;
        img.load(fileName, NULL, rgb_alpha);
        this->width=img.width;
        this->height=img.height;
        this->streams=this->streams;
        glGenTextures(1, &this->id);
        glBindTexture(type, this->id);
        glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        if (img.data)
        {
            glTexImage2D(type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data);
            glGenerateMipmap(type);
        }
        glActiveTexture(0);
        glBindTexture(type, 0);
        img.free();
    }
    Texture2D::~Texture2D()
    {
    }
    void Texture2D::bind(const GLint texture_unit)
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        glBindTexture(this->type, this->id);
    }
    void Texture2D::unbind()
    {
        glActiveTexture(0);
        glBindTexture(this->type, 0);
    }
}