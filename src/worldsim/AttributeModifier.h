#ifndef ATTRIBUTEMODIFIER_H
#define ATTRIBUTEMODIFIER_H

#include "common/LimitedValue.h"

namespace game {
    enum ModifierOperation {
        Flat = 0,
        Multiplicative = 1
    };

    template <typename T>
    class AttributeModifier
    {
    public:
        AttributeModifier(const T& factor, const ModifierOperation& modifierOperation);

        T modify(const T& val) const;
        void modify(common::LimitedValue<T>& limval) const;
        ModifierOperation getModifierOperation() const;
        T getFactor() const;

        bool operator < (const AttributeModifier& other) const;
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
    void AttributeModifier<T>::modify(common::LimitedValue<T>& limval) const
    {
        switch (modifierOperation_)
        {
            case ModifierOperation::Flat:
                limval += factor_;
                break;
            case ModifierOperation::Multiplicative:
                limval *= factor_;
                break;
            default:
                break;
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

    template <typename T>
    bool AttributeModifier<T>::operator < (const AttributeModifier& other) const
    {
        return static_cast<unsigned int>(getModifierOperation()) < static_cast<unsigned int>(other.getModifierOperation());
    }
}

#endif