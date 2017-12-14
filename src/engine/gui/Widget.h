#ifndef WIDGET_H
#define WIDGET_H

#include <vector>

#include "SFML/Graphics.hpp"

#include "engine/Node.h"

namespace engine { namespace gui {

    class Widget : 
        public ::sf::Drawable,
        public ::sf::Transformable,
        public ::engine::Node
    {
    public:
        Widget(const std::string& id);
        Widget(const std::string& id, const sf::Vector2f& pos, const sf::Vector2f& size);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update();
    protected:
        sf::Vector2f size_;
        sf::RectangleShape rectShape_;
        sf::Rect<float> rect_;
        std::vector<Widget*> childWidgets_;
    };
}}

#endif