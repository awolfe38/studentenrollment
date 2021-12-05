#include "roster.h"

#include <iostream>
#include <string>
#include <sstream>

int main()
{
    const std::string studentData[] =

        //Given information 
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Alex,Wolfe,awol10217@wgu.edu,31, 20, 25, 19,SOFTWARE"
    };

    
    cout << "SCRIPTING AND PROGRAMMING -  C867\n";
    cout << "C++\n";
    cout << "Student ID#001282336\n";
    cout << "Alex Wolfe\n\n\n";



    const int numStudents = 5;
    Roster roster; //creates the roster

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);

    cout << "Displaying all students:\n";
    roster.printAll();
    cout << "\n\n";

    cout << "Invalid emails given:\n";
    roster.printInvalidEmails();
    cout << "\n\n";

    cout << "Average day per course for each student:\n";
    for (int i = 0; i < numStudents; i++)
    {
        
        string x = roster.classRosterArray[i]->getID();
        roster.printAverageDaysInCourse(x);
    }
    cout << "\n\n";

    cout << "Students studying software:\n";
    roster.printByDegreeType(SOFTWARE);
    cout << "\n\n";

    roster.remove("A3");
    cout << "\n";
    roster.printAll();
    cout << "\n\n";
    roster.remove("A3");
    cout << "\n\n";
}

