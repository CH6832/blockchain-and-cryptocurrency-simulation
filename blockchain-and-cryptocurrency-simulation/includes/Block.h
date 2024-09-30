#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <ctime>
// #include <openssl/sha.h>

class Block {
public:
    Block(int index, const std::string& previousHash, const std::vector<std::string>& transactions);

    std::string getHash() const;
    std::string getPreviousHash() const;
    std::vector<std::string> getTransactions() const;
    std::string getTimestamp() const;
    void printBlock() const;
    int getIndex() const;

    static std::string calculateHash(int index, const std::string& previousHash, const std::vector<std::string>& transactions, const std::string& timestamp);

private:
    int index;
    std::string previousHash;
    std::vector<std::string> transactions;
    std::string timestamp;
    std::string hash;
};

#endif // BLOCK_H