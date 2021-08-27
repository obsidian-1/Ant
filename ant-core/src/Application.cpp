#pragma once
#include "Application.h"

namespace ant
{
    void Application::Init()
    {
        if (glfwInit())
        {
            LOG_DEBUG("GLFW Init successful");
        }
        else
        {
            LOG_ERROR("GLFW Init failed");
        }
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //My OpenGl-Version:: 4(Major).6(Minor).0 NVIDIA 460.56
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);
        glfwWindowHint(GLFW_SAMPLES,4);
        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
        if (m_window)
        {
            LOG_DEBUG("GLFW Window-Creation successful");
        }
        else
        {
            LOG_ERROR("GLFW Window-Creation failed");
        }
        glfwMakeContextCurrent(m_window);
        glfwSetKeyCallback(m_window, &this->OnEvent);
        //Glfw-init complete
        if (glewInit() == GLEW_OK)
        {
            LOG_DEBUG("GLEW Init successful");
        }
        else
        {
            LOG_ERROR("GLEW Init failed");
        }

        glClearColor(0.2f, 0.2f, 0.2f, 0.4f);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //     glEnable(GL_DEPTH_TEST);
        //     glDepthFunc(GL_LESS);

        // glDepthMask(GL_FALSE);
        glViewport(0, 0, m_width, m_height);
        for (Layer *&l : m_layerStack)
        {
            l->onAttach();
        }
        is_running = true;
    }

    void Application::Shutdown()
    {
        for (Layer *&l : m_layerStack)
        {
            l->onDetach();
        }
        glfwDestroyWindow(m_window);
        LOG_DEBUG("GLFW Window Destroyed");
        m_window = NULL;
        glfwTerminate();
        LOG_DEBUG("GLFW Terminated");
    }

    void Application::Update(float dt)
    {
        for (Layer *&l : m_layerStack)
        {
            l->onUpdate(dt);
        }
    }

    void Application::Run()
    {
        Init();
        while (!glfwWindowShouldClose(m_window))
        {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            Update((1.0f / 60.0f));

            glfwSwapBuffers(m_window);
        }
        Shutdown();
    }

    void Application::pushLayer(Layer *_l)
    {
        m_layerStack.push_back(_l);
    }
    void Application::popLayer()
    {
        m_layerStack.pop_back();
    }
}