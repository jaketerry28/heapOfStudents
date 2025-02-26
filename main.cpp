//main.cpp

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"

void testAddress();
void testDate();
void testStudent();
void loadStudents();

int main(){

  std::cout << "Hello!" << std::endl;
  testAddress();
  testDate();
  testStudent();
  std::cout << std::endl;
  loadStudents();
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

void loadStudents(){
	// initialize vector
	std::vector<Student*> students;

	//read from a file
	std::ifstream inFile;
	std::string currentLine;
	std::stringstream ss;

	std::string test;
	inFile.open("data.csv");

	while (getline(inFile, currentLine)){
		ss.clear();
		ss.str(currentLine);

		getline(ss, test, '\n');
		
		ss.clear();
		ss.str("");

		Student* student = new Student();
		student->init(currentLine);

		students.push_back(student);
		student->printStudent();
	} // end while
} // end loadStudents()
