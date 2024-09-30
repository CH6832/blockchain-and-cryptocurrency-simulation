#ifndef PROOF_OF_WORK_H
#define PROOF_OF_WORK_H

#include "Block.h"

class ProofOfWork {
public:
    ProofOfWork(Blockchain* blockchain, int difficulty);
    std::string mineBlock();

private:
    Block& block;
    int difficulty;
    std::string getLeadingZeros(int n) const;
};

#endif // PROOF_OF_WORK_H