#include <iostream>
#include <chrono>
#include <random>
#include "common/Logger.h"
#include "common/DiscreteDistribution.h"

int main()
{
    common::Logger* logger = common::Logger::getInstancePtr();
    logger->log("Running...\n", common::LogLevel::LOG_DEBUG);
    common::DiscreteDistribution pdf;
    std::vector<int> w = { 5, 4, 3, 2, 1};
    pdf.setWeights(w);
    int hist[5] = {0};
    for (int i = 0; i < 20000; i++)
    {
        hist[pdf.rand()]++;
    }
    std::cout << hist[0] << std::endl;
    std::cout << hist[1] << std::endl;
    std::cout << hist[2] << std::endl;
    std::cout << hist[3] << std::endl;
    std::cout << hist[4] << std::endl;
    return 0;
}