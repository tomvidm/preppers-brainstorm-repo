#include "engine/Node.h"

namespace engine {
    Node::Node(const std::string& id)
    : id_(id)
    {
        ;
    }

    void Node::update()
    {
        ;
    }

    std::string Node::setId(const std::string& id)
    {
        id_ = id;
        return id_;
    }

    std::string Node::getId() const
    {
        return id_;
    }

    bool Node::setVisibility(const bool& isVisible)
    {
        isVisible_ = isVisible;
        return isVisible_;
    }

    bool Node::getVisibility() const
    {
        return isVisible_;
    }
}