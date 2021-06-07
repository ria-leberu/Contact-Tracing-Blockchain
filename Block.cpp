#include "Block.h"
#include "sha256.h"
#include <iostream>

Block::Block(int block_number_input, HealthContact data_input) {
	nonce = 0;
	block_number = block_number_input;
	health_contact = data_input;
	block_hash = calculateHash();
}

std::string Block::getBlockHash() {
	return block_hash;
}

void Block::getHealthInfo() {
	return health_contact.displayAllHealthData();
}

std::string Block::calculateHash() {
	std::string full_hash_string = std::to_string(block_number) + std::to_string(nonce) + health_contact.getHealthDataHash() + block_previous_hash;
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