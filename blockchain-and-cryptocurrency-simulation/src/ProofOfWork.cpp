#include "../includes/ProofOfWork.h"
#include <sstream>
#include <iostream>
#include "../includes/Blockchain.h"

ProofOfWork::ProofOfWork(Blockchain* blockchain, int difficulty)
    : block(block), difficulty(difficulty) {

    std::string ProofOfWork::mineBlock() {
        std::string target = getLeadingZeros(difficulty);
        std::string hash;
        int nonce = 0;

        do {
            hash = Block::calculateHash(block.getIndex(), block.getPreviousHash(), block.getTransactions(), block.getTimestamp() + std::to_string(nonce));
            nonce++;
        } while (hash.substr(0, difficulty) != target);

        return hash;
    }

    std::string ProofOfWork::getLeadingZeros(int n) const {
        return std::string(n, '0');
    };
}