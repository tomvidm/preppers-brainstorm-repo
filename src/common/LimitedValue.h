#ifndef LIMITEDVALUE_H
#define LIMITEDVALUE_H

#include <limits>

#include "common/Interval.h"

namespace common {
    template <typename T>
    class LimitedValue
    {
    public:
        LimitedValue();
        LimitedValue(const T& val);
        LimitedValue(const T& initialValue, const T& lowerBound, const T& upperBound);
        LimitedValue(const LimitedValue<T>& other);
        ~LimitedValue();

        T getMin() const;
        T getMax() const;
        T getValue() const;

        bool isMin() const;

        void imitateUnsigned();

        Interval<T> getInterval() const;
        void setInterval(const Interval<T>& interval);
        void setInterval(const T& lowerBound, const T& upperBound);

        void operator += (const T& val);
        void operator -= (const T& val);
        void operator *= (const T& val);
        void operator /= (const T& val);
        void operator += (const LimitedValue<T>& val);
        void operator -= (const LimitedValue<T>& val);
        void operator *= (const LimitedValue<T>& val);
        void operator /= (const LimitedValue<T>& val);

        bool operator == (const T& val) const;
        bool operator == (const LimitedValue<T>& val) const;

        void operator = (const T& val);
    private:
        T value_;
        Interval<T> bounds_;

        void applyLimits();
    };

    template <typename T>
    LimitedValue<T>::LimitedValue()
    : bounds_(Interval<T>(std::numeric_limits<T>::min(), 
                          std::numeric_limits<T>::max())), value_(T())
    {
        ;
    }

    template <typename T>
    LimitedValue<T>::LimitedValue(const T& val)
    : bounds_(Interval<T>(std::numeric_limits<T>::min(), 
                          std::numeric_limits<T>::max())), value_(val)
    {
        ;
    }

    template <typename T>
    LimitedValue<T>::LimitedValue(const T& initialValue, const T& lowerBound, const T& upperBound)
    : bounds_(Interval<T>(lowerBound, upperBound)), value_(initialValue)
    {
        ;
    }

    template <typename T>
    LimitedValue<T>::LimitedValue(const LimitedValue<T>& other)
    : value_(other.getValue()), bounds_(other.getInterval())
    {
        ;
    }

    template <typename T>
    LimitedValue<T>::~LimitedValue()
    {
        ;
    }

    template <typename T>
    Interval<T> LimitedValue<T>::getInterval() const
    {
        return bounds_;
    }

    template <typename T>
    void LimitedValue<T>::setInterval(const T& lowerBound, const T& upperBound)
    {
        setInterval(Interval<T>(lowerBound, upperBound));
    }

    template <typename T>
    void LimitedValue<T>::setInterval(const Interval<T>& interval)
    {
        bounds_ = interval;
    }

    template <typename T>
    void LimitedValue<T>::operator += (const T& val)
    {
        value_ += val;
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator -= (const T& val)
    {
        value_ -= val;
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator *= (const T& val)
    {
        value_ *= val;
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator /= (const T& val)
    {
        value_ /= val;
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator += (const LimitedValue<T>& val)
    {
        value_ += val.getValue();
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator -= (const LimitedValue<T>& val)
    {
        value_ -= val.getValue();
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator *= (const LimitedValue<T>& val)
    {
        value_ *= val.getValue();
        applyLimits();
    }

    template <typename T>
    void LimitedValue<T>::operator /= (const LimitedValue<T>& val)
    {
        value_ /= val.getValue();
        applyLimits();
    }

    template <typename T>
    bool LimitedValue<T>::operator == (const T& val) const
    {
        return value_ == val;
    }

    template <typename T>
    bool LimitedValue<T>::operator == (const LimitedValue<T>& val) const
    {
        return value_ == val.getValue();
    }

    template <typename T>
    void LimitedValue<T>::operator = (const T& val)
    {
        value_ = val;
        applyLimits();
    }

    template <typename T>
    T LimitedValue<T>::getMin() const
    {
        return bounds_.getLowerBound();
    }

    template <typename T>
    T LimitedValue<T>::getMax() const
    {
        return bounds_.getUpperBound();
    }

    template <typename T>
    T LimitedValue<T>::getValue() const
    {
        return value_;
    }

    template <typename T>
    bool LimitedValue<T>::isMin() const
    {
        return value_ == getMin();
    }

    template <typename T>
    void LimitedValue<T>::imitateUnsigned()
    {
        setInterval(T(static_cast<T>(0)), std::numeric_limits<T>::max());
    }

    template <typename T>
    void LimitedValue<T>::applyLimits()
    {
        if (!bounds_.contains(value_))
        {
            if (value_ > bounds_.getUpperBound())
            {
                value_ = bounds_.getUpperBound();
            }
            else
            {
                value_ = bounds_.getLowerBound();
            }
        }
    }


}

#endif