#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include "Transaction.h"
#include <vector>
#include <string>

class Blockchain {
public:
    Blockchain();
    void addBlock(const std::vector<std::string>& transactions);
    bool isChainValid() const;
    Block getLatestBlock() const;
    Blockchain();                 
    Block createGenesisBlock();  
    void addTransaction(const Transaction& transaction);
    void printChain() const;
    Block createNewBlock(NetworkNode& node);
    bool isChainValid() const;                     

private:
    std::vector<Block> chain;
    Block createGenesisBlock();
    std::vector<Block> chain;  
    std::vector<Transaction> pendingTransactions;
};

#endif // BLOCKCHAIN_H