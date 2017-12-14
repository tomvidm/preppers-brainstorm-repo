#ifndef NODE_H
#define NODE_H

#include <string>

namespace engine {
    class Node
    {
    public:
        Node(const std::string& id);
        
        virtual void update();

        virtual std::string getId() const;
        virtual std::string setId(const std::string& id);
    private:
        std::string id_;
    };
}

#endif