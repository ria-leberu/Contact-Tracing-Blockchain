#include <iostream>
#include "Block.h"
#include "Blockchain.h"

void showMenu() {
	std::cout << "**********Blockchain***********" << std::endl;
	std::cout << "1. Set Transaction Data (Add New Block)" << std::endl;
	std::cout << "2. View Blockchain Data" << std::endl;
	std::cout << "*******************************" << std::endl;
}

void addTransactionData(Blockchain block_chain) {
	std::string new_block_data;
	std::cout << "Please enter transaction data: " << std::endl;
	std::cin >> new_block_data;
	
	block_chain.addBlock(Block(1, "new_block_data"));

}

int main() {
	Blockchain nChain = Blockchain();


	int user_option = 0;
	

	do {

		showMenu();
		std::cout << "Option: ";
		std::cin >> user_option;
		system("cls");

		switch (user_option) {
		case 1:
			addTransactionData(nChain);
			break;
		case 2:
			nChain.viewBlockchain();
			break;
		default:
			std::cout << "Invalid Command." << std::endl;
			break;
		}


	} 	while (user_option != 4);

	

	

}