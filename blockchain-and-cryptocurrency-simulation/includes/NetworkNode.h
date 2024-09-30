#ifndef NETWORKNODE_H
#define NETWORKNODE_H

#include "Blockchain.h"
#include <string>
#include <vector>
// #include <asio.hpp>

class NetworkNode {
public:
    NetworkNode(const std::string& address, int port);
    void connectToPeer(const std::string& peerAddress, int peerPort);
    void synchronizeBlockchain();
    const std::string& getAddress() const; // Getter for address
    void broadcastNewBlock(const Block& block);

private:
    std::string address;
    int port;
    std::vector<std::pair<std::string, int>> peers;
    Blockchain blockchain;

    void handleIncomingConnections();
    void sendBlockToPeer(const Block& block, const std::string& peerAddress, int peerPort);
};

#endif // NETWORKNODE_H
