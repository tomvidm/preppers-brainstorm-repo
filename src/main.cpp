#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include "common/Logger.h"
#include "Directories.h"
#include "worldsim/TraitAtlas.h"
#include "engine/Window.h"

int main()
{
    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Running...\n", common::LogLevel::LOG_DEBUG);

    engine::Window window;
    
    return 0;
}