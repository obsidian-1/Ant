#pragma once
#include "deps.h"

namespace ant
{
    enum EventType
    {
        KEY_DOWN,
        KEY_PRESS,

        MOUSE_PRESSED,
        MOUSE_CLICKED,
        MOUSE_MOVED,

        CURSOR_MOVED
    };

    class Event
    {
    public:
        EventType type;
    };
}