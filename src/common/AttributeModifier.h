#ifndef ATTRIBUTEMODIFIER_H
#define ATTRIBUTEMODIFIER_H

#include <string>

namespace common {
    enum ModifierType
    {
        AddBaseMax = 0,
        MultiplyBaseMax = 1,
        AddMax = 2,
        MultiplyMax = 3,
        AddValue = 4,
        MultiplyValue = 5
    };

    template <typename T>
    class AttributeModifier
    {
    public:
        AttributeModifier(const T& factor, 
                          const ModifierType& type);
        T getFactor() const;
        ModifierType getModifierType() const;
        bool operator < (const AttributeModifier& other) const;
    private:
        void update();

        T factor_;
        ModifierType modType_;
        int duration_ = -1;
    };

    template <typename T>
    AttributeModifier<T>::AttributeModifier(const T& factor, const ModifierType& type)
    : factor_(factor), modType_(type)
    {
        ;
    }

    template <typename T>
    T AttributeModifier<T>::getFactor() const { return factor_; }

    template <typename T>
    ModifierType AttributeModifier<T>::getModifierType() const { return modType_; }

    template <typename T>
    bool AttributeModifier<T>::operator < (const AttributeModifier& other) const
    {
        return (static_cast<int>(modType_) < static_cast<int>(other.getModifierType()));
    }
}

#endif