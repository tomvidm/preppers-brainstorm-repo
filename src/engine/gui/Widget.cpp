#include "engine/gui/Widget.h"

namespace engine { namespace gui {
    Widget::Widget(const std::string& id)
    : Node::Node(id)
    {
        pos_ = sf::Vector2f(100.f, 100.f);
        size_ = sf::Vector2f(300.f, 400.f);
        rect_ = sf::Rect<float>(pos_, size_);
        rectShape_.setPosition(this->pos_);
        rectShape_.setSize(size_);
    }

    Widget::Widget(const std::string& id, const sf::Vector2f& pos, const sf::Vector2f& size)
    : Node::Node(id), size_(size), pos_(pos)
    {
        rect_ = sf::Rect<float>(this->pos_, this->size_);
        rectShape_.setPosition(this->pos_);
        rectShape_.setSize(this->size_);
    }

    void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rectShape_);
    }

    void Widget::setPosition(const sf::Vector2f& pos)
    {
        pos_ = pos;
        rect_ = sf::Rect<float>(this->pos_, size_);
        rectShape_.setPosition(this->pos_);
    }
}}