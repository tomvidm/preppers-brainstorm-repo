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
                          const ModifierType& type,
                          const int& duration = -1);
        
        T getFactor() const;
        ModifierType getModifierType() const;
        int getDuration() const;
        bool isActive() const;
        
        bool operator < (const AttributeModifier& other) const;

        void onTurn();
    private:
        void update();

        T factor_;
        ModifierType modType_;
        int duration_ = -1;
        bool isActive_ = true;
    };

    template <typename T>
    AttributeModifier<T>::AttributeModifier(const T& factor, const ModifierType& type, const int& duration)
    : factor_(factor), modType_(type), duration_(duration)
    {
        ;
    }

    template <typename T>
    T AttributeModifier<T>::getFactor() const { return factor_; }

    template <typename T>
    ModifierType AttributeModifier<T>::getModifierType() const { return modType_; }

    template <typename T>
    int AttributeModifier<T>::getDuration() const { return duration_; }

    template <typename T>
    bool AttributeModifier<T>::isActive() const { return isActive_; }

    template <typename T>
    void AttributeModifier<T>::onTurn()
    {
        if (getDuration() > 0)
        {
            duration_ -= 1;
        }

        update();
    }


    template <typename T>
    bool AttributeModifier<T>::operator < (const AttributeModifier& other) const
    {
        return (static_cast<int>(modType_) < static_cast<int>(other.getModifierType()));
    }
}

#endif