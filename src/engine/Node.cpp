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
}