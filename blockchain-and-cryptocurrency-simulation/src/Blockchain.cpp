#include "../includes/Blockchain.h"
#include <iostream>
#include "../includes/NetworkNode.h"

Blockchain::Blockchain() {
    chain.push_back(createGenesisBlock());
    Block genesisBlock = createGenesisBlock();
    chain.push_back(genesisBlock);
}

Block Blockchain::createGenesisBlock() {
    return Block(0, "0", {"Genesis Block"});
}

void Blockchain::addBlock(const std::vector<std::string>& transactions) {
    Block newBlock(chain.size(), chain.back().getHash(), transactions);
    chain.push_back(newBlock);
}

void Blockchain::addTransaction(const Transaction& transaction) {
    pendingTransactions.push_back(transaction);
    std::cout << "Transaction added: " << transaction.getSender() << " -> "
        << transaction.getReceiver() << " : " << transaction.getAmount() << " coins" << std::endl;
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];

        // Check hash of the current block
        if (currentBlock.getHash() != Block::calculateHash(currentBlock.getIndex(), currentBlock.getPreviousHash(), currentBlock.getTransactions(), currentBlock.getTimestamp())) {
            return false;
        }

        // Check the previous block's hash
        if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
            return false;
        }
    }
    return true;
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

void Blockchain::printChain() const {
    for (const auto& block : chain) {
        block.printBlock();
    }
}

// Create a new block with pending transactions and associated node
Block Blockchain::createNewBlock(NetworkNode& node) {
    Block newBlock(chain.size(), pendingTransactions, chain.back().getHash(), node.getAddress());
    pendingTransactions.clear(); // Clear pending transactions after creating the block
    return newBlock;
}
