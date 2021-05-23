#pragma once
#include <iostream>

class Block {
	

	int nonce;

	//information regarding transaction
	std::string transaction_data;

	//hash information
	std::string block_hash;

	//hash calculation
	std::string calculateHash();

	public:
		int block_number;

		std::string block_previous_hash;
		std::string getBlockHash();
		std::string getTransactionInfo();

		Block(int block_number_input, std::string data_input);
		void mineBlock();
};
