#ifndef WORLDNODE_H
#define WORLDNODE_H

namespace game {
    typedef std::string String;

    enum WorldNodeType
    {
        Actor,
        Location,
        Faction
    };

    class WorldNode
    {
    public:
        inline String getName() const { return name_; } 
    private:
        String name_;
    };
}

#endif