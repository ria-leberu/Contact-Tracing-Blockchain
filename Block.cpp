#include "Block.h"
#include "sha256.h"
#include <iostream>

Block::Block(int block_number_input, std::string data_input) {
	nonce = 0;
	block_number = block_number_input;
	transaction_data = data_input;
	block_hash = calculateHash();
}

std::string Block::getBlockHash() {
	return block_hash;
}

std::string Block::getTransactionInfo() {
	return transaction_data;
}

std::string Block::calculateHash() {
	std::string full_hash_string = std::to_string(block_number) + std::to_string(nonce) + transaction_data + block_previous_hash;
	return sha256(full_hash_string);
}

void Block::mineBlock() {
	char difficulty_string[2] = {'0','\0'};

	do {
		nonce++;
		block_hash = calculateHash();
		std::cout << "mining . . ." << block_hash << std::endl;
		system("cls");
	} while (block_hash.substr(0,1) != difficulty_string);

	std::cout << "Block Mined: " << block_hash << std::endl;
	
}