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
	getline(ss, sYear);

	ss << sMonth << sDay << sYear;
	ss >> month >> day >> year;

	Date::month = month;

	ss.clear();
	ss.str("");
} // end init

void Date::printDate(){
	std::string months[13] = {"NULL", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	std::cout << months[month] << std::endl;
} // end printDate
