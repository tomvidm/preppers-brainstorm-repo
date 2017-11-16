#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <string>

namespace game {
    class Description
    {
    public:
        Description();
        Description(const std::string& title, const std::string& description);
        void setTitle(std::string title);
        void setDescription(std::string description);
        std::string getTitle() const;
        std::string getDescription() const;
        std::string getString() const;
    private:
        std::string title_;
        std::string description_;
    };
}

#endif