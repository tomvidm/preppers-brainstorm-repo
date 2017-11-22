#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"

#include "common/Logger.h"

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