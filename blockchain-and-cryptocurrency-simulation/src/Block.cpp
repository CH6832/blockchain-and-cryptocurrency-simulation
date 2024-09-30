#include "../includes/Block.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>

Block::Block(int index, const std::string& previousHash, const std::vector<std::string>& transactions)
    : index(index), previousHash(previousHash), transactions(transactions), timestamp(std::to_string(std::time(0))) {
    hash = calculateHash(index, previousHash, transactions, timestamp);
}

std::string Block::getHash() const {
    return hash;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

std::vector<std::string> Block::getTransactions() const {
    return transactions;
}

std::string Block::getTimestamp() const {
    return timestamp;
}

void Block::printBlock() const
{
    std::cout << "Block " << index << ":\n"
        << "Previous Hash: " << previousHash << "\n"
        << "Hash: " << hash << "\n"
        //<< "Created By: " << createdBy << "\n"
        << "Transactions:\n";
    //for (const auto& tx : transactions) {
    //    std::cout << "  " << tx.getSender() << " -> " << tx.getReceiver() << ": " << tx.getAmount() << " coins\n";
    //}
}

int Block::getIndex() const {
    return index;
}

std::string Block::calculateHash(int index, const std::string& previousHash, const std::vector<std::string>& transactions, const std::string& timestamp) {
    std::stringstream ss;
    ss << index << previousHash << timestamp;
    for (const auto& transaction : transactions) {
        ss << transaction;
    }
    std::string data = ss.str();

    // SHA256 hashing
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);

    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    return hashString.str();
}