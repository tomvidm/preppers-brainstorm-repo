#ifndef ATTRIBUTEMODIFIER_H
#define ATTRIBUTEMODIFIER_H

#include "common/Logger.h"

#include "common/LimitedValue.h"
#include "worldsim/Description.h"

namespace game {
    enum ModifierOperation {
        Flat = 0,
        Multiplicative = 1
    };

    template <typename T>
    class AttributeModifier : public Description
    {
    public:
        AttributeModifier(const T& factor, const ModifierOperation& modifierOperation);

        T modify(const T& val) const;
        void modify(common::LimitedValue<T>& limval) const;
        ModifierOperation getModifierOperation() const;
        T getFactor() const;

        bool operator < (const AttributeModifier& other) const;
        void onTurn();
        bool isActive() const;
    private:
        ModifierOperation modifierOperation_;
        T factor_;
        unsigned int lifetimeTurns_ = 1;
        bool isActive_ = true;
    };

    template <typename T>       
    AttributeModifier<T>::AttributeModifier(const T& factor, const ModifierOperation& modifierOperation)
    : modifierOperation_(modifierOperation), factor_(factor)
    {
        common::Logger::getInstancePtr()->log("AttributeModifier constructed\n");
    }

    template <typename T>
    T AttributeModifier<T>::modify(const T& val) const
    {
        if (!isActive())
        {
            return val;
        }
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
        if (!isActive())
        {
            return;
        }
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
    void AttributeModifier<T>::onTurn()
    {
        common::Logger::getInstancePtr()->log("calling AttributeModifier::onTurn()\n");
        if (lifetimeTurns_ == 0)
        {
            isActive_ = false;
        }
        else if (lifetimeTurns_ == 1)
        {
            isActive_ = false;
            lifetimeTurns_ = 0;
        }
        else
        {
            lifetimeTurns_ -= 1;
        }
    }

    template <typename T>
    bool AttributeModifier<T>::isActive() const
    {
        return isActive_;
    }

    template <typename T>
    bool AttributeModifier<T>::operator < (const AttributeModifier& other) const
    {
        return static_cast<unsigned int>(getModifierOperation()) < static_cast<unsigned int>(other.getModifierOperation());
    }
}

#endif