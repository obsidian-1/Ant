#pragma once
namespace ant
{
    enum stream
    {
        grey = 1,
        alpha = 2,
        rgb = 3,
        rgb_alpha = 4
    };

    class Image
    {
    public:
        //Data-------------------------------
        unsigned char *data;
        int width;
        int height;
        bool has_alpha;
        int streams;
        //-----------------------------------

        unsigned char *
        load(const char *fileName,
             int *streams_in_file,
             int desired_streams);
        void create_png(const char *file_name, int width, int height, void *data);
        void free();
    };}