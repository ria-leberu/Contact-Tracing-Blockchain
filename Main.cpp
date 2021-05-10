#include <iostream>
#include "Block.h"
#include "Blockchain.h"

void showMenu() {
	std::cout << "**********Blockchain***********" << std::endl;
	std::cout << "1. Set Transaction Data (Add New Block)" << std::endl;
	std::cout << "2. View Blockchain Data" << std::endl << std::endl;;
	std::cout << "0. Exit" << std::endl;
	
	std::cout << "*******************************" << std::endl;
}


int main() {
	Blockchain nChain = Blockchain();


	int user_option = 99;

	do {

		showMenu();
		std::cout << "Option: ";
		std::cin >> user_option;
		system("cls");

		switch (user_option) {
		case 1:
			nChain.addTransactionData();
			break;
		case 2:
			nChain.viewBlockchain();
			break;
		
		case 0:
			break;
		default:
			std::cout << "Invalid Command." << std::endl;
			break;
		}


	} 	while (user_option != 0);

	

	

}