#pragma once
#include <iostream>
#include <vector>
#include "Block.h"

class Blockchain {

	std::vector<Block> chain;

	Block getPreviousBlock();

public:
	//will initialize chain with genesis block
	Blockchain();

	void viewBlockchain();

	void addBlock(Block new_block);

	int getSize();

	void addNewHealthContact();
	
};