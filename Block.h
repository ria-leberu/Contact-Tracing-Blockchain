#pragma once
#include <iostream>
#include "HealthContact.h"

class Block {
	

	int nonce;

	//information regarding transaction
	//std::string transaction_data;
	HealthContact health_contact;

	//hash information
	
	std::string block_hash;

	//hash calculation
	std::string calculateHash();

	public:
		int block_number;

		std::string block_previous_hash;
		std::string getBlockHash();
		void getHealthInfo();

		Block(int block_number_input, HealthContact data_input);
		void mineBlock();
};
