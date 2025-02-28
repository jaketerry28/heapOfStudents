//main.cpp

#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "date.h"
#include "address.h"
#include "student.h"

void testAddress();
void testDate();
void testStudent();
void loadStudents(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
std::string menu();

int main(){

  	//initialize studentPtr type vector called students
  	std::vector<Student*> students;
  	loadStudents(students);

  
  	std::cout << "Hello!" << std::endl;

  	bool keepGoing = true;

  	while (keepGoing){
	std::string choice = menu();
	if (choice == "0"){
		std::cout << "\nQuit\n";
		keepGoing = false;
	} // end for
	else if (choice == "1"){
		printStudents(students);
	} // end else if
	else if (choice == "2"){
		showStudentNames(students);
	} // end else if
	else if (choice == "3"){
		findStudent(students);
	} // end else if
	else {
		std::cout << "\nPlease enter a valid inputer 0-3: \n";
	}
	} // end while 
	
  /*		
  testAddress();
  testDate();
  testStudent();
  */
  std::cout << std::endl;
  delStudents(students);
  return 0;
} // end main

void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  std::cout << std::endl;
  delete student;
} // end testStudent

void loadStudents(std::vector<Student*>& students){

	//read from a file
	std::ifstream inFile;
	std::string currentLine;
	inFile.open("data.csv");

	while (getline(inFile, currentLine)){

		Student* student = new Student();
		student->init(currentLine);

		students.push_back(student);
	} // end while
	inFile.close();
	
} // end loadStudents()

void delStudents(std::vector<Student*>& students){
	for (auto& item: students){
		delete item;
	} // end for
} // end delStudents

void printStudents(std::vector<Student*>& students){
	for (auto& item: students){
		item->printStudent();
	} // end for
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
	for (auto& item: students){
		std::cout << item->getLastFirst() << std::endl;
	} // end for
} // end showStudentNames

void findStudent(std::vector<Student*>& students){
	std::string searchName, lastName;
	std::stringstream ss; // for parsing for lastName 
	int i = 1; // initialize counter
	bool results = false; //init result checker

	std::cout << "Enter students last name: ";
	getline(std::cin, searchName); // store input
	std::cout << "\n    RESULTS    \n" << std::endl;
	
	for (auto& item: students){
		// parse for lastName and store it
		ss.clear();
		ss.str(item->getLastFirst());
		getline(ss, lastName, ',');

		size_t found = lastName.find(searchName); // search lastName for substring, store substring position in found

		if (found != std::string::npos){ //npos = -1, if found is not -1 then substring exists
			results = true;
			std::cout << i << ')' << std::endl; // print count
			item->printStudent();
			i++; // update counter
		} // end if
	} //end for 

	// if no results found
	if (!results){
		std::cout << "No results found." << std::endl;
	} // end if

} // end findStudent

std::string menu(){
	
	std::cout << "\n0) quit\n";
	std::cout << "1) print all student names\n";
	std::cout << "2) print all student data\n";
	std::cout << "3) find a student\n";

	std::cout << "\nPlease choose 0-3: ";
	
	std::string choice;
	
	getline(std::cin, choice);

	return choice;
	
} // end menu
