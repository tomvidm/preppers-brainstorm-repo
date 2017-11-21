#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include <vector>
#include <algorithm>

#include "common/AttributeModifier.h"

namespace common {
    template <typename T>
    class Attribute {
    public:
        Attribute();
        Attribute(const T& maxVal);

        inline T getBaseMaxValue() const { return baseMaxValue_; }
        inline T getMaxValue() const { return maxValue_; }
        inline T getValue() const { return value_; }
        inline std::vector<AttributeModifier<T>> getModifiers() const { return mods_; }

        void addModifier(const AttributeModifier<T>& modifier);
        void applyModifier(const AttributeModifier<T>& modifier);

        void operator += (const T& other);
        void operator -= (const T& other);
        void operator *= (const T& other);
        Attribute<T> operator = (const Attribute<T>& other);
        bool operator == (const Attribute<T>& other) const;
        bool operator == (const T& other) const;
        void onTurn();

    private:
        void update();
        void limitValue();

        T value_;
        T maxValue_;
        T baseMaxValue_;

        std::vector<AttributeModifier<T>> mods_;
    };

    template <typename T>
    Attribute<T>::Attribute()
    : maxValue_(1.f), value_(1.f), baseMaxValue_(1.f) { update(); }

    template <typename T>
    Attribute<T>::Attribute(const T& maxVal)
    : maxValue_(maxVal), value_(maxVal), baseMaxValue_(maxVal) { update(); }

    template <typename T>
    void Attribute<T>::operator += (const T& other)
    {
        value_ += other;
        limitValue();
    }

    template <typename T>
    void Attribute<T>::operator -= (const T& other)
    {
        value_ -= other;
        limitValue();
    }

    template <typename T>
    void Attribute<T>::operator *= (const T& other)
    {
        value_ *= other;
        limitValue();
    }

    template <typename T>
    Attribute<T> Attribute<T>::operator = (const Attribute<T>& other)
    {
        value_ = other.getValue();
        baseMaxValue_ = other.getBaseMaxValue();
        mods_ = other.getModifiers();
        update();
        return *this;
    }

    template <typename T>
    bool Attribute<T>::operator == (const Attribute<T>& other) const
    {
        return value_ == other.getValue();
    }

    template <typename T>
    bool Attribute<T>::operator == (const T& other) const
    {
        return value_ == other;
    }

    template <typename T>
    void Attribute<T>::update()
    {
        maxValue_ = baseMaxValue_;

        std::sort(mods_.begin(), mods_.end());

        for (auto& m : mods_)
        {
            applyModifier(m);
        }

        limitValue();
    }

    template <typename T>
    void Attribute<T>::limitValue()
    {
        if (value_ > maxValue_)
        {
            value_ = maxValue_;
        }
        else if (value_ < static_cast<T>(0))
        {
            value_ = static_cast<T>(0);
        }
    }

    template <typename T>
    void Attribute<T>::addModifier(const AttributeModifier<T>& modifier)
    {
        if (static_cast<int>(modifier.getModifierType()) > 3)
        {
            applyModifier(modifier);
            limitValue();
        }
        else
        {
            mods_.push_back(modifier);
            update();
        }
    }

    template <typename T>
    void Attribute<T>::applyModifier(const AttributeModifier<T>& modifier)
    {
        switch (modifier.getModifierType())
        {
            case ModifierType::AddBaseMax:
                baseMaxValue_ += modifier.getFactor();
                break;
            case ModifierType::MultiplyBaseMax:
                baseMaxValue_ *= modifier.getFactor();
                break;
            case ModifierType::AddMax:
                maxValue_ += modifier.getFactor();
                break;
            case ModifierType::MultiplyMax:
                maxValue_ *= modifier.getFactor();
                break;
            case ModifierType::AddValue:
                value_ += modifier.getFactor();
                break;
            case ModifierType::MultiplyValue:
                value_ *= modifier.getFactor();
                break;
            default:
                break;
        }
    }

    template <typename T>
    void Attribute<T>::onTurn()
    {
        std::vector<AttributeModifier<T>> temp;

        for (auto& m : mods_)
        {
            m.onTurn();

            if (m.getDuration() != 0)
            {
                temp.push_back(m);
            }            
        }

        mods_ = temp;
    }
}

#endif