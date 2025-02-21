//student.cpp

#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
	studentString = "";
	firstName = "";
	lastName = "";
	dob = nullptr;
	expectedGrad = nullptr;
	address = nullptr;
	creditHours = 0;
} // end constructor

Student::~Student(){
	delete dob;
	delete expectedGrad;
	delete address;
} // end deconstructor

void Student::init(std::string studentString){

	Student::studentString = studentString;
	std::stringstream ss;
	std::string street;
	std::string city;
	std::string state;
	std::string zip;
	std::string sBirth;
	std::string sGrad;
	std::string sCreditHours;
	
	ss.clear();
	ss.str(studentString);

	getline(ss, Student::firstName, ',');
	getline(ss, Student::lastName, ',');
	getline(ss, street, ',');
	getline(ss, city, ',');
	getline(ss, state, ',');
	getline(ss, zip, ',');
	getline(ss, sBirth, ',');
	getline(ss, sGrad, ',');
	getline(ss, sCreditHours);

	ss.clear();
	ss.str("");
	
	ss << sCreditHours;
	ss >> creditHours;

	Student::dob = new Date();
	Student::dob->init(sBirth);

	Student::expectedGrad = new Date();
	Student::expectedGrad->init(sGrad);

	Student::address = new Address();
	Student::address->init(street, city, state, zip);

} // end init

void Student::printStudent(){
	std::cout << Student::firstName << " " << Student::lastName << std::endl;
	address->printAddress();
	std::cout << "Dob: ";
	dob->printDate();
	std::cout << "Grad: ";
	expectedGrad->printDate();
	std::cout << "Credits: " << Student::creditHours << std::endl;
} // end printStudent
