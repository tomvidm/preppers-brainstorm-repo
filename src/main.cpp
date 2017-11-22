#include <iostream>
#include <chrono>
#include <random>
#include "common/Logger.h"
#include "Directories.h"
#include "lua/LuaIncludes.h"

int main()
{
    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Running...\n", common::LogLevel::LOG_DEBUG);

    sel::State luaState;
    luaState.Load(directories::scripts + "names.lua");
    sel::Selector names = luaState["names"];
    sel::Selector lang = names["east_slavic"];
    
    return 0;
}