#include "engine/gui/Widget.h"

namespace engine { namespace gui {
    Widget::Widget(const std::string& id)
    : Node::Node(id)
    {
        ;
    }

    Widget::Widget(const std::string& id, const sf::Vector2f& pos, const sf::Vector2f& size)
    : Node::Node(id), size_(size)
    {
        setPosition(pos);
        update();
    }

    void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rectShape_);

        for (auto wPtr : childWidgets_)
        {
            target.draw(*wPtr, states);
        }
    }

    void Widget::update()
    {
        rect_ = sf::Rect<float>(getPosition(), size_);
        rectShape_.setPosition(getPosition());
        rectShape_.setSize(size_);

        for (auto wPtr : childWidgets_)
        {
            wPtr->setPosition(getPosition());
        }
    }
}}