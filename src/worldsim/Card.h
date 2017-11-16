#ifndef CARD_H
#define CARD_H

#include <string>

namespace game {
    class Card
    {
    public:
        Card(const unsigned int& id);
        void setDescription(const std::string& description);
        std::string getDescription() const;
        unsigned int getID() const;
    private:
        const unsigned int id_;
        std::string description_;
    };
}

#endif