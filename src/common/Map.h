#ifndef MAP_H
#define MAP_H

#include <map>

namespace common {
    template <typename T>
    class Map
    {
    public:
        void set(const std::string& id, const T& item);
        T& get(const std::string& id);
        T get(const std::string& id) const;

        bool contains(const std::string& id) const;
    protected:
        std::map<std::string, T> map_;
    };

    template <typename T>
    void Map<T>::set(const std::string& id, const T& item)
    {
        map_[id] = item;
    }

    template <typename T>
    T& Map<T>::get(const std::string& id)
    {
        return map_.at(id);
    }

    template <typename T>
    T Map<T>::get(const std::string& id) const
    {
        return map_.at(id);
    }

    template <typename T>
    bool Map<T>::contains(const std::string& id) const 
    {
        if (map_.count(id))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

#endif