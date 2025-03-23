#pragma once
#include <string>
#include "degree.h"

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    Student();
    Student(std::string id, std::string first, std::string last, std::string mail, int a, int days[], DegreeProgram dp);

    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    int getAge() const;
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram() const;

    void setStudentID(std::string id);
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setEmail(std::string mail);
    void setAge(int a);
    void setDaysInCourse(int days[]);
    void setDegreeProgram(DegreeProgram dp);

    void print();
};
