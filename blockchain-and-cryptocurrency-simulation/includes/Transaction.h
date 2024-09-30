#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
// #include <openssl/rsa.h>
// #include <openssl/pem.h>
// #include <openssl/sha.h>

class Transaction {
public:
    Transaction(const std::string& sender, const std::string& receiver, double amount);
    
    std::string getSender() const;
    std::string getReceiver() const;
    double getAmount() const;
    std::string getSignature() const;
    std::string getTransactionData() const;
    bool verifySignature() const;

private:
    std::string sender;
    std::string receiver;
    double amount;
    std::string signature;

    std::string signTransaction(RSA* senderKey, const std::string& data) const;
    static std::string sha256(const std::string& data);
};

#endif // TRANSACTION_H
