#pragma once
#include <iostream>
#include <vector>

class HealthContact {

	bool notified; //has the contact been notified of exposure?
	int contact_number; //phone number
	std::string name;
	std::string infection_status; //positive, negative
	std::string dx_date; //date diagnosed
	std::string vaccination_status; //no vaccination, partial vaccination, full vaccination
	std::string work; //address of workplace
	std::string residence; //address of residence
	std::string recent_visit_local; //areas in city/town visited most frequently in last two weeks
	std::string recent_visit_travel; //states or countries visited in last two weeks
	std::vector<std::string> recent_contacts; //persons most recently in contact with outside of residence

public:


	std::string contact_id; //merges name and contact phone number

	void displayAllHealthData();

	std::string getHealthDataHash(); //string for block hash generation

	bool getNotificationStatus(std::string);
};