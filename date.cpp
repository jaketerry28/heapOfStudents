//date.cpp

#include "date.h"
#include <iostream>
#include <sstream>

Date::Date(){
	dateString = "0/0/0000";
	month = 0;
	day = 0;
	year = 0;
} // end constructor

void Date::init(std::string dateString){

	Date::dateString = dateString;
	std::stringstream ss;
	std::string sMonth;
	std::string sDay;
	std::string sYear;

	ss.clear();
	ss.str(dateString);

	getline(ss, sMonth, '/');
	getline(ss, sDay, '/');
	getline(ss, sYear, '/');

	ss.clear();
	ss.str("");

	ss << sMonth << " " << sDay << " " << sYear;
	ss >> Date::month >> Date::day >> Date::year;

	if (ss.fail()){
		std::cout << "failed" << std::endl;
	} // end if
	
	ss.clear();
	ss.str("");

} // end init

void Date::printDate(){
	std::string months[] = {"NULL", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	std::cout << months[Date::month] << " " << Date::day << ", " << Date::year << std::endl;
} // end printDate
