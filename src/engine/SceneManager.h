#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>

#include "SFML/Graphics.hpp"

namespace engine {
    class Node;

    class SceneManager
    {
    private:
        std::vector<Node*> nodes;
        std::vector<sf::Sprite> sprites;
    };
}

#endif