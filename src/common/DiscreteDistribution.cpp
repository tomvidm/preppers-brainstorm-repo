#include "DiscreteDistribution.h"

namespace common {
    unsigned DiscreteDistribution::seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine DiscreteDistribution::gen(seed);

    DiscreteDistribution::DiscreteDistribution()
    {
        ;
    }

    DiscreteDistribution::DiscreteDistribution(const std::vector<int>& weights)
    {
        setWeights(weights);
    }

    int DiscreteDistribution::rand() const 
    {
        return pdf_(gen);
    }

    int DiscreteDistribution::rand(const std::vector<int>& weights) const 
    {
        std::discrete_distribution<int> pdf = std::discrete_distribution<int>(weights.begin(), weights.end());
        return pdf(gen);
    }

    void DiscreteDistribution::setWeights(const std::vector<int>& weights)
    {
        weights_ = weights;
        pdf_ = std::discrete_distribution<int>(weights_.begin(), weights_.end());
    }

    std::vector<int> DiscreteDistribution::getWeights() const
    {
        return weights_;
    }
}
