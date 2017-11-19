#ifndef DISCRETEDISTRIBUTION_H
#define DISCRETEDISTRIBUTION_H

#include <random>
#include <vector>
#include <chrono>


namespace common {
    class DiscreteDistribution
    {
    public:
        DiscreteDistribution();
        DiscreteDistribution(const std::vector<int>& weights);
        int rand() const;
        int rand(const std::vector<int>& weights) const;
        std::vector<int> getWeights() const;
        std::vector<double> getProbabilities() const;
        void setWeights(const std::vector<int>& weights);
    private:
        static unsigned seed;
        static std::default_random_engine gen;
        std::discrete_distribution<int> pdf_;
        std::vector<int> weights_;
    };
}

#endif
