
#include "common/Logger.h"
#include "worldsim/UnitState.h"
#include "worldsim/AttributeModifier.h"

int main()
{
    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Running...\n", common::LogLevel::LOG_DEBUG);

    return 0;
}