#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"

#include "common/Logger.h"
#include "engine/gui/Widget.h"

// A pointless wrapper for sf::RenderWindow.
// WIll hopefully be useful one day

namespace engine {
    class Window
    {
    public:
        Window();
    private:
        void loop();
        sf::RenderWindow sfWindow;
    };
}

#endif