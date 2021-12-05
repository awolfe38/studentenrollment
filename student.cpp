#include "student.h"

Student::Student() { //Parameterless constructor sets default values

	this->studentID = "";
	this->first = "";
	this->last = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = 0;
	this->degreeType = DegreeProgram::NETWORK;
	

}

Student::Student(string studentID, string first, string last, string email, int age, int days[], DegreeProgram degreeType) {
	
	this->studentID = studentID;
	this->first = first;
	this->last = last;
	this->email = email;
	this->age = age;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
	this->degreeType = degreeType;

}

Student::~Student() {}//Destructor does nothing

string Student::getID() { return this->studentID; }
string Student::getFirst() { return this->first; }
string Student::getLast() { return this->last; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDay() { return this->days; }
DegreeProgram Student::getProgram() { return this->degreeType; }

void Student::setID(string id) { this->studentID = id; }
void Student::setFirst(string first) { this->first = first; }
void Student::setLast(string last) { this->last = last; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }

void Student::setDays(int days[]) { //sets each number of days individually
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
}

void Student::setType(DegreeProgram degreeType) { this->degreeType = degreeType; }

void Student::printHeader() { //prints the header

	cout << "Output format: \nStudent ID \t| First Name \t| Last Name \t\t| Age \t| Days in Course \t| Degree Program\n";

}

void Student::print() { //the full line of all the student's information

	cout << this->getID() << '\t';
	cout << "First Name: " << this->getFirst() << '\t';
	cout << "Last Name: " << this->getLast() << '\t';
	cout << "Age :" << this->getAge() << '\t';

	cout << "daysInCourse: {";
	for (int i = 0; i < dayArraySize; i++) {
		cout << this->getDay()[i];
		if (i < dayArraySize - 1) {
			cout << ',';
		} 
	}

	cout << "} Degree Program: " << degreeStrings[this->getProgram()] << '\n';

}

