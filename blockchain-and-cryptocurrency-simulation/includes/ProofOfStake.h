#ifndef PROOF_OF_STAKE_H
#define PROOF_OF_STAKE_H

#include "Block.h"
#include <map>
#include <string>

class ProofOfStake {
public:
    ProofOfStake();
    void addStake(const std::string& validator, double amount);
    std::string selectValidator();

private:
    std::map<std::string, double> stakes;

    double totalStake() const;
};

#endif // PROOF_OF_STAKE_H
