#ifndef TRAITATLAS_H
#define TRAITATLAS_H

#include <vector>

#include "worldsim/Trait.h"
#include "lua/LuaIncludes.h"

namespace game {
    class TraitAtlas
    {
    public:
        TraitAtlas();
        void listTraits() const;
    private:
        std::vector<Trait> traits;
    };
}

#endif