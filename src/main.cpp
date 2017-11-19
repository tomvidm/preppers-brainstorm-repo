#include <iostream>
#include <chrono>
#include <random>
#include "common/Logger.h"
#include "worldsim/Body.h"
#include "worldsim/DamageDescriptor.h"

int main()
{
    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Running...\n", common::LogLevel::LOG_DEBUG);

    game::Body body;
    game::DamageDescriptor dmg(game::DamageType::Ballistic, 0.2f);
    
    for (int i = 0; i < 5; i++)
    {
        game::Part hit = body.receiveDamage(dmg, game::Part::Head);
        std::cout << body.getBodyPart(hit).getName() << " was hit!" << std::endl;
    }

    body.assessHealth();
    std::cout << "===================" << std::endl;
    body.assessHitChances();
    std::cout << "===================" << std::endl;
    body.assessHitChances(game::Part::Head);
    return 0;
}