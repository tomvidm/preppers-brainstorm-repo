#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"

#include "common/Logger.h"

// A pointless wrapper for sf::RenderWindow.
// WIll hopefully be useful one day

namespace engine {
    class Window
    {
    public:
        Window();
    private:
        void loop();
        void handleEvents();
        sf::RenderWindow sfWindow;
    };
}

#endif