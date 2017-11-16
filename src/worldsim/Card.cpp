#include "Card.h"

namespace game {
    Card::Card(const unsigned int& id)
    : id_(id)
    {
        ;
    }

    unsigned int Card::getID() const
    {
        return id_;
    }
}