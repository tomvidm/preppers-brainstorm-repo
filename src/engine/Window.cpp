#include "engine/Window.h"

namespace engine {
    Window::Window()
    {
        sfWindow.create(sf::VideoMode(1024, 768), "WindowTitle");
        sfWindow.setFramerateLimit(60);

        common::Logger::getInstancePtr()->log("SFML Window created.");

        loop();
    }

    void Window::loop()
    {
        while (sfWindow.isOpen())
        {
            handleEvents();
            
            sfWindow.clear();
            sfWindow.display();
        }
    }

    void Window::handleEvents()
    {
        sf::Event event;
        while (sfWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                sfWindow.close();
            }
        }
    }
}