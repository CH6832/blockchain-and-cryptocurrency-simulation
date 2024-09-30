#include "../includes/NetworkNode.h"
#include <iostream>
#include <thread>

NetworkNode::NetworkNode(const std::string& address, int port)
    : address(address), port(port), nodeName(name) {
    std::thread(&NetworkNode::handleIncomingConnections, this).detach();
}

void NetworkNode::connectToPeer(const std::string& peerAddress, int peerPort) {
    peers.emplace_back(peerAddress, peerPort);
    synchronizeBlockchain();
}

void NetworkNode::synchronizeBlockchain() {
    // Simulate synchronizing the blockchain with peers
    for (const auto& peer : peers) {
        // Fetch peer's blockchain and merge (pseudo-code)
        // Implement actual synchronization logic here
    }
}

void NetworkNode::broadcastNewBlock(const Block& block) {
    for (const auto& peer : peers) {
        sendBlockToPeer(block, peer.first, peer.second);
    }
}

void NetworkNode::handleIncomingConnections() {
    // Simulate handling incoming connections
    // Implement actual network communication here
}

void NetworkNode::sendBlockToPeer(const Block& block, const std::string& peerAddress, int peerPort) {
    // Simulate sending block to peer
    // Implement actual network communication here
}

// Implementation of the getAddress method
const std::string& NetworkNode::getAddress() const {
    return address; // Return the address of the node
}

std::string NetworkNode::getNodeName() const {
    return nodeName;
}