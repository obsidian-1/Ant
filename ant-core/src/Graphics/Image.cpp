#pragma once
#include "../deps.h"
#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

namespace ant
{
    unsigned char *
    Image::load(const char *fileName,
                int *streams_in_file,
                int desired_streams)
    {
        // stbi_set_flip_vertically_on_load(true);
        data = stbi_load(fileName, &this->width, &this->height, &this->streams, desired_streams);
        if (data)
        {
            LOG_DEBUG(fileName << " Loaded successfully");
        }
        else
        {
            LOG_ERROR(fileName<<" Loading failed");
            return NULL;
        }
        this->has_alpha = ((desired_streams % 2 == 0) ? true : false);
        return data;
    }

    void Image::free()
    {
        stbi_image_free(this->data);
    }
    
    void Image::create_png(const char *file_name, int width, int height, void *data)
    {
        stbi_write_png(file_name, width, height, 4, data, width * 4);
    }
}