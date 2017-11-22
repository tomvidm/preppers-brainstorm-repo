#include "Directories.h"
#include "worldsim/TraitAtlas.h"
#include <iostream>
namespace game {
    TraitAtlas::TraitAtlas()
    {
        sel::State luaState{true};
        luaState.Load(directories::scripts + "traits.lua");
        int numTraits = luaState["getNumTraits"]();
        std::cout << numTraits << std::endl;
        for (int i = 1; i <= numTraits; i++)
        {
            std::string title = luaState["getTraitTitle"](i);
            std::string desc = luaState["getTraitDescription"](i);
            int numOpinions = luaState["getNumTraitOpinions"](i);

            Trait newTrait(title);
            newTrait.setDescription(desc);
            for (int j = 1; j <= numOpinions; j++)
            {
                std::string opinion = luaState["getTraitOpinion"](i, j);
                int opinionMod = luaState["getTraitOpinionModifier"](i, j);
                newTrait.setOpinionOf(opinion, opinionMod);
            }
            traits.push_back(newTrait);
        }
    }

    void TraitAtlas::listTraits() const
    {
        for (auto t : traits)
        {
            std::cout << t.getName() << " - " << t.getDescription() << std::endl;
        }
    }
}