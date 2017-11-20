#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <algorithm>
#include <stack>
#include <iostream>

#include "common/Logger.h"

#include "common/LimitedValue.h"
#include "worldsim/AttributeModifier.h"

/*
    DEPRECATED SOON
*/

namespace game {
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
        T getMaxValue() const;

        void addModifier(const AttributeModifier<T>& mod);
        unsigned int getNumModifiers() const;

        void operator += (const T& val);
        void operator -= (const T& val);
        void operator = (const Attribute<T>& attr);

        void setBaseValue(const T& val);
        void onTurn();
    protected:
        void update();
        void cleanup();
        
        common::LimitedValue<T> baseAttributeValue;
        common::LimitedValue<T> modifiedAttributeValue;

        std::vector<AttributeModifier<T>> modifiers;
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
    T Attribute<T>::getMaxValue() const
    {
        return modifiedAttributeValue.getMax();
    }

    template <typename T>
    void Attribute<T>::addModifier(const AttributeModifier<T>& mod)
    {
        modifiers.push_back(mod);
        update();
    }

    template <typename T>
    void Attribute<T>::setBaseValue(const T& val)
    {
        baseAttributeValue = val;
        update();
    }

    template <typename T>
    void Attribute<T>::operator += (const T& val)
    {
        baseAttributeValue += val;
        update();
    }

    template <typename T>
    void Attribute<T>::operator -= (const T& val)
    {
        baseAttributeValue -= val;
        update();
    }

    template <typename T>
    void Attribute<T>::operator = (const Attribute<T>& attr)
    {
        baseAttributeValue = attr.baseAttributeValue;
        modifiedAttributeValue = attr.modifiedAttributeValue;
        update();
    }

    template <typename T>
    unsigned int Attribute<T>::getNumModifiers() const
    {
        return modifiers.size();
    }

    template <typename T>
    void Attribute<T>::onTurn()
    {
        for (auto& m : modifiers)
        {
            m.onTurn();
        }
        cleanup();
        update();
    }

    template <typename T>
    void Attribute<T>::update()
    {
        modifiedAttributeValue = baseAttributeValue;

        // Make sure flat modifiers are applied before multiplicative.
        std::sort(modifiers.begin(), modifiers.end());  

        for (auto m : modifiers)
        {
            m.modify(modifiedAttributeValue);
        }
    }

    template <typename T>
    void Attribute<T>::cleanup()
    {
        // Should probably find a better way to remove elements.
        std::vector<AttributeModifier<T>> leftoverModifiers;
        for (auto& m : modifiers)
        {
            if (m.isActive())
            {
                leftoverModifiers.push_back(m);
            }
        }
        modifiers = leftoverModifiers;
    }
}

#endif