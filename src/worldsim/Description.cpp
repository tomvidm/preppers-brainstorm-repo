#include "Description.h"

namespace game {
    Description::Description()
    : title_("title"), description_("description")
    {
        ;
    }

    Description::Description(const std::string& title,
                             const std::string& description)
    : title_(title), description_(description)
    {
        ;
    }

    void Description::setTitle(std::string title)
    {
        title_ = title;
    }

    void Description::setDescription(std::string description)
    {
        description_ = description;
    }

    std::string Description::getTitle() const
    {
        return title_;
    }

    std::string Description::getDescription() const
    {
        return description_;
    }

    std::string Description::getString() const
    {
        return title_ + ": " + description_ + "\n";
    }
}