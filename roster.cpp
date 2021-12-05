#include "roster.h"

void Roster::parse(string studentdata) {

	int rhs = studentdata.find(",");//finds the first comma
	string sID = studentdata.substr(0, rhs);//extracts the substring before the comma, gives us the ID

	int lhs = rhs + 1;//moves to the right of the first found comma
	rhs = studentdata.find(",", lhs);
	string sFirst = studentdata.substr(lhs, rhs - lhs); //gets the first name

	lhs = rhs + 1;//moves to the right of the next found comma
	rhs = studentdata.find(",", lhs);
	string sLast = studentdata.substr(lhs, rhs - lhs); //gets the last name

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string sEmail = studentdata.substr(lhs, rhs - lhs); //gets the email

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int sAge = stod(studentdata.substr(lhs, rhs - lhs)); //gets the student's age

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs); 
	int sDay1 = stod(studentdata.substr(lhs, rhs - lhs)); //gets the first number of days 
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int sDay2 = stod(studentdata.substr(lhs, rhs - lhs)); //gets the second number of days
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int sDay3 = stod(studentdata.substr(lhs, rhs - lhs)); //gets the last number of days

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	DegreeProgram sDegree = NETWORK;
	if (string(1, studentdata.at(lhs)) + studentdata.at(lhs + 1) == "SE") sDegree = SECURITY;
	else if (string(1, studentdata.at(lhs)) + studentdata.at(lhs + 1) == "SO") sDegree = SOFTWARE;

	add(sID, sFirst, sLast, sEmail, sAge, sDay1, sDay2, sDay3, sDegree);
}


void Roster::add(string ID, string first, string last, string email, int age, int day1, int day2, int day3, DegreeProgram degree) {
	//puts the days into an array so we can pass it into the constructor  
	int darr[3] = { day1, day1, day3 };
	//makes the new student object
	classRosterArray[++lastIndex] = new Student(ID, first, last, email, age, darr, degree);
}

//prints all of the students
void Roster::printAll() {

	Student::printHeader();//prints the header
	for (int i = 0; i <= lastIndex; i++)
	{
		cout << classRosterArray[i]->getID(); cout << '\t';
		cout << "First Name: " << classRosterArray[i]->getFirst(); cout << '\t';
		cout << "Last Name: " << classRosterArray[i]->getLast(); cout << '\t';
		cout << "Age :" << classRosterArray[i]->getAge(); cout << '\t';
		cout << "daysInCourse: {" << classRosterArray[i]->getDay()[0]; cout << ", ";
		cout << classRosterArray[i]->getDay()[1]; cout << ", ";
		cout << classRosterArray[i]->getDay()[2]; cout << "} ";
		cout << "Degree Program :"  << degreeStrings[classRosterArray[i]->getProgram()]; cout << '\n';
	}
}

//prints all of the students from a given degree program
void Roster::printByDegreeType(DegreeProgram degreeProgram) {

	Student::printHeader();
	for (int i = 0; i <= lastIndex; i++) {
		if (Roster::classRosterArray[i]->getProgram() == degreeProgram) classRosterArray[i] -> print();
	}
	cout << "\n";
}

//A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {

	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string bEmail = (classRosterArray[i]->getEmail());
		if (bEmail.find('@') == string::npos || bEmail.find('.') == string::npos || bEmail.find(' ') != string::npos) {
			any = true;
			cout << bEmail << "\n";
		}

	}
	if (!any) cout << "NONE\n";
}

//prints the average number of days the student took to finish each course
void Roster::printAverageDaysInCourse(string StudentID) {
	
	bool success = false;
		for (int i = 0; i <= Roster::lastIndex; i++)
		{
			if (classRosterArray[i]->getID() == StudentID) {
				success = true;//found
				cout << classRosterArray[i]->getFirst() << " " << classRosterArray[i]->getLast() << " took an average of ";
				cout << (classRosterArray[i]->getDay()[0]
					+ classRosterArray[i]->getDay()[1]
					+ classRosterArray[i]->getDay()[2]) / 3 ;
				cout << " days to complete.";
			}
		}

		if (!success) {
			cout << StudentID << " was not found.\n";//if not found
		}
		cout << "\n\n";
}

//removes a student that comes in as a parameter
void Roster::remove(string StudentID) {

	bool success = false;

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == StudentID) {
			success = true;//found
			if (i < numStudents - 1){
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;

		}

	}

	if (success) {
		cout << "Student " << StudentID << " removed from the roster.\n\n";
	}
	else {
		cout << StudentID << " was not found.\n";//if not found
	}

}

	//return string Student::getID() { return this->studentID; }
Roster::~Roster() {
	cout << "DESTRUCTOR CALLED!!!\n\n";
	for (int i = 0; i < numStudents; i++) 
	{
		cout << "Destroying student #" << i + 1 << "...\n";
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}