#include <iostream>
#include <string>
#include "HealthContact.h"

HealthContact::HealthContact() {
	


}

std::string HealthContact::getHealthDataHash() { //string for block hash generation
	
	std::string all_contacts = ""; //convert list of contacts into single string
	for (auto& it : recent_contacts) {
		all_contacts += it;
	}

	std::string health_hash = std::to_string(notified) + std::to_string(contact_number) + name + infection_status + dx_date + vaccination_status + work + residence + recent_visit_local + recent_visit_local + recent_visit_travel + all_contacts;

	return health_hash;

}

void HealthContact::displayAllHealthData() {

	std::cout << "Name: " << name << std::endl;
	std::cout << "Current Infection Status (Novel Virus): " << infection_status << std::endl;
	std::cout << "Diagnosis Date: " << dx_date << std::endl;
	std::cout << "Vaccination Status: " << vaccination_status << std::endl;
	std::cout << "Workplace Address: " << work << std::endl;
	std::cout << "Residential Address: " << residence << std::endl;
	std::cout << "Recently Visited Areas (Local): " << recent_visit_local << std::endl;
	std::cout << "Recently Visited Areas (Out of State): " << recent_visit_travel << std::endl;
	for (auto& it : recent_contacts) {
		std::cout << it << std::endl;
	}

}

bool HealthContact::getNotificationStatus(std::string contact_id) {

}