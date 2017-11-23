#include "engine/ServiceLocator.h"

namespace engine {
    ServiceLocator* ServiceLocator::instancePtr_ = nullptr;

    ServiceLocator::ServiceLocator()
    {
        ;
    }

    ServiceLocator* ServiceLocator::getInstancePtr()
    {
        if (instancePtr_ == nullptr)
        {
            instancePtr_ = new ServiceLocator();
        }

        return instancePtr_;
    }
}