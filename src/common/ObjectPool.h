#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <vector>
#include <list>

#define DEFAULT_OBJECTPOOL_SIZE 10

namespace common {
    template <class T>
    class ObjectPool
    {
    public:
        T& addObject();
        T& addObject(const T& obj);

        size_t getNumAllocatedSlots() const;
    private:
        std::vector<T> objectContainer_;
        std::list<size_t> freeList_;
    };

    template <class T>
    T& ObjectPool<T>::addObject()
    {
        return addObject(T());
    }

    template <class T>
    T& ObjectPool<T>::addObject(const T& obj)
    {
        if (freeList_.empty())
        {
            objectContainer_.push_back(obj);
        }
        return objectContainer_[objectContainer_.size() - 1];
    }


    template <class T>
    size_t ObjectPool<T>::getNumAllocatedSlots() const
    {
        return objectContainer_.size();
    }
}

#endif