#ifndef ATTRIBUTEMODIFIER_H
#define ATTRIBUTEMODIFIER_H

#include "common/LimitedValue.h"

namespace game {
    enum ModifierOperation {
        Flat,
        Multiplicative
    };

    template <typename T>
    class AttributeModifier
    {
    public:
        AttributeModifier(const T& factor, const ModifierOperation& modifierOperation);

        T modify(const T& val) const;
        ModifierOperation getModifierOperation() const;
        T getFactor() const;
    private:
        ModifierOperation modifierOperation_;
        T factor_;
    };

    template <typename T>       
    AttributeModifier<T>::AttributeModifier(const T& factor, const ModifierOperation& modifierOperation)
    : modifierOperation_(modifierOperation), factor_(factor)
    {
        ;
    }

    template <typename T>
    T AttributeModifier<T>::modify(const T& val) const
    {
        switch (modifierOperation_)
        {
            case ModifierOperation::Flat:
                return val + factor_;
            case ModifierOperation::Multiplicative:
                return val * factor_;
            default:
                return T();
        }
    }

    template <typename T>
    ModifierOperation AttributeModifier<T>::getModifierOperation() const
    {
        return modifierOperation_;
    }

    template <typename T>
    T AttributeModifier<T>::getFactor() const
    {
        return factor_;
    }
}

#endif