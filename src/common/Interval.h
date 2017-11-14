#ifndef INTERVAL_H
#define INTERVAL_H

namespace common {
    template <typename T>
    class Interval 
    {
    public:
        Interval(const T& lowerBound, const T& upperBound);
        Interval(const Interval& other);
        ~Interval();

        bool contains(T value) const;

        T getLowerBound() const;
        T getUpperBound() const;
    private:
        T lowerBound_;
        T upperBound_;
    };

    template <typename T>
    Interval<T>::Interval(const T& lowerBound, const T& upperBound)
    : lowerBound_(lowerBound), upperBound_(upperBound)
    {
        ;
    }

    template <typename T>
    Interval<T>::Interval(const Interval<T>& other)
    : lowerBound_(other.getLowerBound()),
      upperBound_(other.getUpperBound())
    {
        ;
    }

    template <typename T>
    Interval<T>::~Interval()
    {
        ;
    }

    template <typename T>
    bool Interval<T>::contains(T value) const
    {
        return (lowerBound_ < value) && (value < upperBound_);
    }

    template <typename T>
    T Interval<T>::getLowerBound() const
    {
        return lowerBound_;
    }

    template <typename T>
    T Interval<T>::getUpperBound() const 
    {
        return upperBound_;
    }
}

#endif