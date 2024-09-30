#include "../includes/Transaction.h"
//#include <openssl/err.h>
//#include <openssl/ssl.h>
//#include <openssl/rsa.h>
#include <sstream>
#include <iomanip>

Transaction::Transaction(const std::string& sender, const std::string& receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {
    std::string data = getTransactionData();
    // signature = signTransaction(data);
}

std::string Transaction::getSender() const {
    return sender;
}

std::string Transaction::getReceiver() const {
    return receiver;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getSignature() const {
    return signature;
}

std::string Transaction::getTransactionData() const {
    std::ostringstream oss;
    oss << sender << receiver << amount;
    return oss.str();
}

//bool Transaction::verifySignature() const {
//    std::string data = getTransactionData();
//    unsigned char hash[SHA256_DIGEST_LENGTH];
//    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
//
//    RSA* rsa = RSA_new();
//    BIO* keybio = BIO_new_mem_buf(sender.c_str(), -1);
//    PEM_read_bio_RSA_PUBKEY(keybio, &rsa, nullptr, nullptr);
//    BIO_free(keybio);
//
//    bool result = RSA_verify(NID_sha256, hash, SHA256_DIGEST_LENGTH, reinterpret_cast<const unsigned char*>(signature.c_str()), signature.length(), rsa);
//    RSA_free(rsa);
//
//    return result;
//}

//std::string Transaction::signTransaction(RSA* senderKey, const std::string& data) const {
//    unsigned char hash[SHA256_DIGEST_LENGTH];
//    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
//
//    unsigned char* signature = new unsigned char[RSA_size(senderKey)];
//    unsigned int signatureLen;
//    RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, signature, &signatureLen, senderKey);
//
//    std::string signatureStr(reinterpret_cast<const char*>(signature), signatureLen);
//    delete[] signature;
//
//    return signatureStr;
//}

//std::string Transaction::sha256(const std::string& data) {
//    unsigned char hash[SHA256_DIGEST_LENGTH];
//    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
//
//    std::ostringstream oss;
//    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
//        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
//    }
//
//    return oss.str();
//}
