#include "../includes/ProofOfStake.h"
#include <cstdlib>
#include <ctime>
#include <numeric>

ProofOfStake::ProofOfStake() {
    std::srand(std::time(nullptr));
}

void ProofOfStake::addStake(const std::string& validator, double amount) {
    stakes[validator] += amount;
}

std::string ProofOfStake::selectValidator() {
    double total = totalStake();
    double rand = static_cast<double>(std::rand()) / RAND_MAX;

    double cumulative = 0;
    for (const auto& stake : stakes) {
        cumulative += stake.second / total;
        if (rand < cumulative) {
            return stake.first;
        }
    }

    return stakes.begin()->first;
}

double ProofOfStake::totalStake() const {
    return std::accumulate(stakes.begin(), stakes.end(), 0.0, [](double sum, const std::pair<std::string, double>& stake) {
        return sum + stake.second;
    });
}
