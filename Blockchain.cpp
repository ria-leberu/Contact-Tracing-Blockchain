#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
#include "Blockchain.h"
#include "HealthContact.h"

Blockchain::Blockchain() {
	HealthContact data;
	chain.push_back(Block(0,data));
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
		it.getHealthInfo();
		std::cout << "-----------------------------" << std::endl;
	}
}

void Blockchain::addNewHealthContact() { //generate new random entry to health contact block

	HealthContact patient_data;

	std::string first_name_list[10] = { "Bill", "Mary", "Jane", "George", "Jerry", "Elaine", "Larry", "Robert", "Catherine", "Jessica" };
	std::string surname_list[10] = { "Wilcox", "Todd", "Pepper", "Smith", "Brown", "Jones", "Garcia", "Miller", "Johnson", "Williams" };
	std::string phone_number_area_code[3] = {"212", "917", "646"};
	std::string infection_status_list[2] = { "Positive", "Negative"};
	std::string dx_date;
	std::string vaccination_status_list[4] = { "Not Vaccinated", "Partial Vaccination", "Full Vaccination", "Unknown"};
	std::string workplace_list[7] = { "SC&P, 210 MADISON AVE", "L-MART, 110 23RD STREET", "EMERSON ELECTRIC, 52 MOTT STREET", "FRESHCUT GROCERS, 210 JAY STREET", "WYATT AND SONS, 180 PRINCE STREET", "CANDICE CANDIES, 300 DEKALB AVE", "PRINCELY PRINTS, 420 CENTRAL PARK WEST"};
	std::string residence_list[9] = { "CHRISTOPHER STREET", "E 10TH SREET", "W 4TH STREET", "MADISON AVE", "W 52ND STREET", "W BROADWAY", "LEXINGTON AVENUE", "NINTH AVE", "PARK AVE" };
	std::string recent_areas_local_list[8] = { "WHOLE FOODS UNION SQUARE", "BEST BUY 23RD ST", "MCDONALDS TIME SQUARE", "BARNES AND NOBLE 6TH AVE" "METROPOLITAN MUSEUM OF ART", "AMERICAN MUSEUM OF NATURAL HISTORY", "WESTSIDE MARKET", "CHELSEA PIERS" };
	std::string recent_areas_travel_list[9] = { "TEXAS","NEW JERSEY","MAINE","FLORIDA","CALIFORNIA","GERMANY","SINGAPORE","BRAZIL","NEW ZEALAND" };

	//generate notification status
	if (rand() % 2 == 1) {
		patient_data.setNotified(true);
	}
	//generate name
	std::string patient_name = first_name_list[rand() % 10] + " " + surname_list[rand() % 10];
	patient_data.setName(patient_name);

	//generate phone number
	std::string phone_number = phone_number_area_code[rand() % 3] + "-" + std::to_string(rand() % 1000) + "-" + std::to_string(rand() % 10000);
	patient_data.setContactNumber(phone_number);
	
	//generate infection status
	patient_data.setInfectionStatus(infection_status_list[rand() % 2]);
	dx_date = std::to_string(1 + rand() % 12) + "/" + std::to_string(1 + rand() % 27) + "/" + "2020";
	patient_data.setDx_date(dx_date);

	//generate vaccination status
	if (patient_data.getInfectionStatus() == "POSITIVE") {
		patient_data.setVaccinationStatus("NEGATIVE");
	}
	else {
		patient_data.setVaccinationStatus(vaccination_status_list[rand() % 4]);
	}
	//generate workplace
	patient_data.setWork(workplace_list[rand() % 7]);

	//generate residence
	patient_data.setResidence(residence_list[rand() % 9]);

	//generate local visits
	patient_data.setRecentVisitLocal(recent_areas_local_list[rand() % 8]);

	//generate travel visits
	patient_data.setRecentVisitTravel(recent_areas_travel_list[rand() % 9]);

	//generate recent contacts
	int patient_num_contacts = rand() % 5;
	std::string patient_contacts_list ="";
	for (int i = 0; i < patient_num_contacts; ++i) {
		patient_contacts_list = patient_contacts_list + "(" + first_name_list[rand() % 10] + " " + surname_list[rand() % 10] + ")";
	}
	patient_data.setRecentContacts(patient_contacts_list);

	addBlock(Block(getSize(), patient_data));
	
	
}