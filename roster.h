#pragma once
#include "student.h"

class Roster {
private:
    int lastIndex;
    int capacity;
    Student** classRosterArray;

public:
    Roster(int capacity = 5);
    ~Roster();

    void add(std::string studentID, std::string firstName, std::string lastName, std::string email,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
