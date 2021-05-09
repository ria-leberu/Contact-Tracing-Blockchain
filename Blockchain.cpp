#include <iostream>
#include "Blockchain.h"

Blockchain::Blockchain() {
	chain.push_back(Block(0, "Genesis Block"));
}

Block Blockchain::getPreviousBlock() {
	return chain.back();
}

void Blockchain::addBlock(Block new_block) {
	new_block.block_previous_hash = getPreviousBlock().getBlockHash();
	new_block.mineBlock();
	chain.push_back(new_block);
}

int Blockchain::getSize() {
	return chain.size();
}

void Blockchain::viewBlockchain() {
	std::cout << "**********Blockchain View***********" << std::endl;
	for (auto& it : chain) {
		std::cout << "Block Number: " << it.block_number << std::endl;
		std::cout << "Block Hash: " << it.getBlockHash() << std::endl;
		std::cout << "Previous Block Hash: " << it.block_previous_hash << std::endl;
		std::cout << "Transaction Data: " << it.getTransactionInfo() << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}
}