#include <iostream>
#include <string>
#include <algorithm>
#include "HealthContact.h"

HealthContact::HealthContact() {
	
	notified = false; //has the contact been notified of exposure?
	contact_number = "0"; //phone number
	name = "GENESIS BLOCK";
	infection_status = "GENESIS BLOCK"; //positive, negative, unknown
	dx_date = "GENESIS BLOCK"; //date diagnosed
	vaccination_status = "GENESIS BLOCK"; //no vaccination, partial vaccination, full vaccination
	work ="GENESIS BLOCK"; //address of workplace
	residence = "GENESIS BLOCK"; //address of residence
	recent_visit_local = "GENESIS BLOCK"; //areas in city/town visited most frequently in last two weeks
	recent_visit_travel = "GENESIS BLOCK"; //states or countries visited in last two weeks
	recent_contacts = "GENESIS BLOCK"; //persons most recently in contact with outside of residence

}

std::string HealthContact::getHealthDataHash() { //string for block hash generation
	

	std::string health_hash = std::to_string(notified) + contact_number + name + infection_status + dx_date + vaccination_status + work + residence + recent_visit_local + recent_visit_local + recent_visit_travel + recent_contacts;

	return health_hash;

}

void HealthContact::displayAllHealthData() {

	std::cout << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Notified: ";
		if (notified == 1) { std::cout << "YES" << std::endl; }
		else { std::cout << "NO" << std::endl; }
	std::cout << "Phone Number: " << contact_number << std::endl;
	std::cout << "Current Infection Status (Novel Virus): " << infection_status << std::endl;
	std::cout << "Diagnosis Date: " << dx_date << std::endl;
	std::cout << "Vaccination Status: " << vaccination_status << std::endl;
	std::cout << "Workplace Address: " << work << std::endl;
	std::cout << "Residential Address: " << residence << std::endl;
	std::cout << "Recently Visited Areas (Local): " << recent_visit_local << std::endl;
	std::cout << "Recently Visited Areas (Out of State, Last Six Weeks): " << recent_visit_travel << std::endl;
	std::cout << "Recent Contacts: " << recent_contacts << std::endl;
	std::cout << std::endl;
}

std::string HealthContact::getInfectionStatus() {
	return infection_status;
}

void HealthContact::setNotified(bool input_notified) {
	notified = input_notified;
}

void HealthContact::setContactNumber(std::string input_contact) {
	contact_number = input_contact;
}


void HealthContact::setName(std::string input_name) {
	std::transform(input_name.begin(), input_name.end(), input_name.begin(), ::toupper);
	name = input_name;
}

void HealthContact::setInfectionStatus(std::string input_infection_status) {
	std::transform(input_infection_status.begin(), input_infection_status.end(), input_infection_status.begin(), ::toupper);
	infection_status = input_infection_status;
}

void HealthContact::setDx_date(std::string input_dx_date) {
	dx_date = input_dx_date;
}

void HealthContact::setVaccinationStatus(std::string input_vaccination_status) {
	std::transform(input_vaccination_status.begin(), input_vaccination_status.end(), input_vaccination_status.begin(), ::toupper);
	vaccination_status = input_vaccination_status;
}

void HealthContact::setWork(std::string input_work) {
	std::transform(input_work.begin(), input_work.end(), input_work.begin(), ::toupper);
	work = input_work;
}

void HealthContact::setResidence(std::string input_residence) {
	std::transform(input_residence.begin(), input_residence.end(), input_residence.begin(), ::toupper);
	residence = input_residence;
}

void HealthContact::setRecentVisitLocal(std::string input_local) {
	std::transform(input_local.begin(), input_local.end(), input_local.begin(), ::toupper);
	recent_visit_local = input_local;

}

void HealthContact::setRecentVisitTravel(std::string input_travel) {
	std::transform(input_travel.begin(), input_travel.end(), input_travel.begin(), ::toupper);
	recent_visit_travel = input_travel;
}

void HealthContact::setRecentContacts(std::string input_recent_contacts) {
	std::transform(input_recent_contacts.begin(), input_recent_contacts.end(), input_recent_contacts.begin(), ::toupper);
	recent_contacts = input_recent_contacts;
}