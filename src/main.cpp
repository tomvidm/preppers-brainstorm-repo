
#include "common/Logger.h"
#include "world/UnitState.h"
#include "world/Modifier.h"

int main()
{
    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Running...\n", common::LogLevel::LOG_DEBUG);

    return 0;
}