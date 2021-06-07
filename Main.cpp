#include <iostream>
#include <ctime>
#include "Block.h"
#include "Blockchain.h"

void showMenu() {
	std::cout << "**********Blockchain***********" << std::endl;
	std::cout << "1. Add New Patient" << std::endl;
	std::cout << "2. Add 10 New Patients" << std::endl;
	std::cout << "3. View Blockchain Data" << std::endl << std::endl;;
	std::cout << "0. Exit" << std::endl;
	
	std::cout << "*******************************" << std::endl;
}


int main() {
	srand(time(NULL));
	Blockchain nChain = Blockchain();


	int user_option = 99;

	do {

		showMenu();
		std::cout << "Option: ";
		std::cin >> user_option;
		system("cls");

		switch (user_option) {
		case 1:
			nChain.addNewHealthContact();
			break;
		case 2:
			for (int i = 0; i < 10; ++i) {
				nChain.addNewHealthContact();
			}
			break;
		case 3:
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