#ifndef TRAIT_H
#define TRAIT_H

#include <vector>
#include <string>

#include "common/Map.h"

namespace game {
    typedef std::string String;
    class Trait
    {
    public:
        Trait(String id);
        inline String& getName() { return name; }
        inline String getName() const { return name; }
        inline String getDescription() const { return description; }
        inline void setDescription(const String& desc) { description = desc; }

        bool hasOpinionOf(String id) const;
        float getOpinionModifierFor(String id) const;
        float getOpinionOf(const std::vector<Trait>& traits) const;
        void setOpinionOf(String id, float opinion);
    private:
        std::string name;
        std::string description; 
        common::Map<float> map;
    };
}

#endif