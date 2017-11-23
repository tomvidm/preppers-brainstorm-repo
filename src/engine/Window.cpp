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
        gui::Widget w("widget01", sf::Vector2f(100.f, 100.f), sf::Vector2f(300.f, 400.f));
        w.setPosition(sf::Vector2f(100.f, 100.f));
        while (sfWindow.isOpen())
        {
            sf::Event event;
            while (sfWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    sfWindow.close();
                }
            }

            sfWindow.clear();
            sfWindow.draw(w);
            sfWindow.display();
        }
    }
}