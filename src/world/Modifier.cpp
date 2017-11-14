#include "Modifier.h"

namespace game {
    Modifier::Modifier(const AttributeType& attribute,
                       const ModifierTarget& target,
                       const ModifierEquation& equation,
                       const float& factor)
    : attribute(attribute), target(target), equation(equation), 
      factor(factor)
    {
        ;
    }

    float Modifier::modify(const float& value) const
    {
        switch (equation)
        {
            case ModifierEquation::AddFlat:
            {
                return value + factor;
            }
            case ModifierEquation::MultiplyAndAdd:
            {
                return value * (1 + factor);
            }
            case ModifierEquation::Multiply:
            {
                return value * factor;
            }
            default:
            {
                return 0.f;
            }
        }
    }
}