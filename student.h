#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using std::string;
using std::cout;

//makes the Student class and initializes all the variables included in the class
class Student
{
public:
	const static int dayArraySize = 3;

private:
	string studentID;
	string first;
	string last;
	string email;
	int age;
	int days[dayArraySize];
	DegreeProgram degreeType;
public:
	Student();//Parameterless constructor
	Student(string studentID, string first, string last, string email, int age, int days[], DegreeProgram degreeType); //Full constructor
	~Student();//Destructor 

	//getters
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	int* getDay();
	DegreeProgram getProgram();

	//setters
	void setID(string id);
	void setFirst(string first);
	void setLast(string last);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setType(DegreeProgram degree);

	static void printHeader();//displays a header

	void print();//displays student's data

};