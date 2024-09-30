// main.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "includes/Blockchain.h"
#include "includes/NetworkNode.h"
#include "includes/Transaction.h"
#include "includes/ProofOfWork.h"
using namespace std;

int main()
{
    // Create a Blockchain
    Blockchain blockchain;
    std::cout << "Blockchain created with Genesis Block." << std::endl;

    // Simulate Network Nodes
    NetworkNode node1("127.0.0.1", 8080);
    NetworkNode node2("127.0.0.1", 8081);

    // RSA* senderKey = generateRSAKeyPair(); // Generate RSA key for Alice

    // Create Transactions
    Transaction transaction1("Alice", "Bob", 50);   // Alice sends 50 coins to Bob
    Transaction transaction2("Bob", "Charlie", 20); // Bob sends 20 coins to Charlie

    std::cout << "Transactions created." << std::endl;

    // Add Transactions to the Blockchain (Pending until mined)
    blockchain.addTransaction(transaction1);
    blockchain.addTransaction(transaction2);

    // Simulate Consensus Algorithm (Proof of Work or Proof of Stake)
    ProofOfWork proofOfWork(&blockchain, 4); // Example difficulty set to 4
    // ProofOfStake proofOfStake; // If using Proof of Stake

    // Step 6: Mine a Block and add it to the Blockchain
    Block newBlock = blockchain.createNewBlock(node1);
    proofOfWork.mineBlock(); // If Proof of Work
    // proofOfStake.mineBlock(newBlock, node1); // If Proof of Stake

    blockchain.addBlock();
    std::cout << "New block mined and added to the blockchain." << std::endl;

    // Validate the Blockchain
    if (blockchain.isChainValid()) {
        std::cout << "Blockchain is valid." << std::endl;
    }
    else {
        std::cout << "Blockchain is invalid." << std::endl;
    }

    // Print the Blockchain
    blockchain.printChain();

	return 0;
}
