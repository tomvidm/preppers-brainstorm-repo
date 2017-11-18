#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

namespace game {
    enum BodyFunction
    {
        Sight,
        Hearing,
        Smell,
        Taste,
        Moving,
        Language
    };

    enum DamageType
    {
        // Instant damage
        Blunt = 0,
        Sharp,
        Ballistic,
        Spread,
        Explosive,
        Concussive,
        // Gradual damage
        Burning = 6,
        Radiation,
        Suffocating,
        Bleeding,
        NUM_DAMAGE_TYPES
    };

    enum DamageAspect
    {
        Damage,           // Raw damage value
        ArmorPenetration, // Negates flat defense modifiers
        NUM_DAMAGE_ASPECTS
    };
}

#endif