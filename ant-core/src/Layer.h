#pragma once
#include "deps.h"
#include "Event.h"
namespace ant
{
    class Layer
    {
    public:
        std::string m_name;
        virtual void onAttach(){};//Init Function
        virtual void onDetach(){};//DeInit Function
        virtual void onUpdate(float dt){};// Game Loop
        virtual void onEvent(Event& e){};//
        Layer(std::string _name):m_name(_name){};
    };
}