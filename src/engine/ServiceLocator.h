#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

// This singleton class is used to access frequently used facilities
// like the texture manager, animation manager, blah blah blah etc

namespace engine {
    class ServiceLocator 
    {
    public:
        static ServiceLocator* getInstancePtr();
    protected:
        ServiceLocator();
        static ServiceLocator* instancePtr_;
    };
}

#endif