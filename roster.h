#pragma once
#include "student.h"

class Roster {

private:
	int lastIndex = -1;
	const static int numStudents = 5;

public:
	Student* classRosterArray[numStudents];


public:
	//parse method goes through a string with the commas taken out and takes out the data of each student
	void parse(string row);

	//the add method creates a Student object
	void add(
		string sID,
		string sFirst,
		string sLast,
		string sEmail,
		int sAge,
		int sDay1,
		int sDay2,
		int sDay3,
		DegreeProgram sDegree
	);

	void printAll();//calls the print method for each Student
	void printByDegreeType(DegreeProgram degreeProgram);//calls the print method for all the Students in the given Degree Program
	void printInvalidEmails(); // Prints all invalid emails, email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void printAverageDaysInCourse(string StudentID); //Prints the average number of days the student took to complete a course
	void remove(string StudentID); //removes the Student object with the given student ID
	~Roster();


};	