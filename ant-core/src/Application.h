#pragma once
#include "deps.h"
#include "Layer.h"
namespace ant
{
    class Application
    {
    //Data--------------------------------
    public:
        std::string m_title = "Main";
        int m_width=800;
        int m_height=600;
        bool is_resizable=false;
        bool is_full_screen=false;
        bool is_running = false;
        GLFWwindow *m_window=NULL;
    private:
        std::vector<Layer*> m_layerStack;
    //------------------------------------


    //functions---------------------------
    public:
        Application(std::string _title):m_title(_title){};
        void Run();
        void pushLayer(Layer*_l);
        void popLayer();
    private:
        void Init();
        void Update(float dt);
        void Shutdown();
        static void  OnEvent(GLFWwindow* window, int key, int scancode, int action, int mods){};
    //------------------------------------
    };
}