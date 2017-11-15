#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

// Unit attributes are defined here.

#include "common/LimitedValue.h"
#include "world/AttributeModifier.h"
#include <iostream>

namespace game {
    enum AttributeType
    {
        // Basic attributes
        SoftAttack,
        SoftDefense,
        HardAttack,
        HardDefense,
        Organization,
        Morale,
        Dicipline,
        Entrenchment,
        NUM_ATTRIBUTES
    };

    template <typename T>
    class Attribute
    {
    public:
        Attribute();
        Attribute(const T& initialValue);
        Attribute(const T& initialValue, const T& maxValue);

        T getBaseValue() const;
        T getBaseMaxValue() const;
        T getValue() const;

        void addModifier(const AttributeModifier<T>& mod);
    private:
        void update();
        
        common::LimitedValue<T> baseAttributeValue;
        common::LimitedValue<T> modifiedAttributeValue;

        std::vector<AttributeModifier<T>> flatModifiers;
        std::vector<AttributeModifier<T>> multiplicativeModifiers;
    };

    template <typename T>
    Attribute<T>::Attribute()
    : baseAttributeValue(common::LimitedValue<T>::LimitedValue(
                                            static_cast<T>(0),
                                            static_cast<T>(0),
                                            std::numeric_limits<T>::max()))
    {
        update();
    }

    template <typename T>
    Attribute<T>::Attribute(const T& initialValue)
    : baseAttributeValue(common::LimitedValue<T>::LimitedValue(
                                            initialValue,
                                            static_cast<T>(0),
                                            std::numeric_limits<T>::max()))
    {
        update();
    }

    template <typename T>
    Attribute<T>::Attribute(const T& initialValue, const T& maxValue)
    : baseAttributeValue(common::LimitedValue<T>::LimitedValue(
                                            initialValue,
                                            static_cast<T>(0),
                                            maxValue))
    {
        update();
    }

    template <typename T>
    T Attribute<T>::getBaseValue() const
    {
        return baseAttributeValue.getValue();
    }

    template <typename T>
    T Attribute<T>::getBaseMaxValue() const
    {
        return baseAttributeValue.getMax();
    }

    template <typename T>
    T Attribute<T>::getValue() const
    {
        return modifiedAttributeValue.getValue();
    }

    template <typename T>
    void Attribute<T>::addModifier(const AttributeModifier<T>& mod)
    {
        switch (mod.getModifierOperation())
        {
            case ModifierOperation::Flat:
                flatModifiers.push_back(mod);
                break;
            case ModifierOperation::Multiplicative:
                multiplicativeModifiers.push_back(mod);
                break;
            default:
                break;
        }

        update();
    }

    template <typename T>
    void Attribute<T>::update()
    {
        modifiedAttributeValue = baseAttributeValue;

        for (auto m : flatModifiers)
        {
            modifiedAttributeValue += m.getFactor();
        }

        for (auto m : multiplicativeModifiers)
        {
            modifiedAttributeValue *= m.getFactor();
        }
    }
}

#endif