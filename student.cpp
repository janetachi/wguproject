#include <iostream>
#include "student.h"

Student::Student() {
    studentID = "";
    firstName = "";
    lastName = "";
    email = "";
    age = 0;
    for (int i = 0; i < 3; ++i) daysInCourse[i] = 0;
    degreeProgram = SOFTWARE;
}

Student::Student(std::string id, std::string first, std::string last, std::string mail, int a, int days[], DegreeProgram dp) {
    studentID = id;
    firstName = first;
    lastName = last;
    email = mail;
    age = a;
    for (int i = 0; i < 3; ++i) daysInCourse[i] = days[i];
    degreeProgram = dp;
}

std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmail() const { return email; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

void Student::setStudentID(std::string id) { studentID = id; }
void Student::setFirstName(std::string first) { firstName = first; }
void Student::setLastName(std::string last) { lastName = last; }
void Student::setEmail(std::string mail) { email = mail; }
void Student::setAge(int a) { age = a; }
void Student::setDaysInCourse(int days[]) {
    for (int i = 0; i < 3; ++i) daysInCourse[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }

void Student::print() {
    std::cout << "ID: " << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName
              << "\tAge: " << age << "\tDays In Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2]
              << "} Degree Program: ";
    switch (degreeProgram) {
        case SECURITY: std::cout << "Security"; break;
        case NETWORK: std::cout << "Network"; break;
        case SOFTWARE: std::cout << "Software"; break;
    }
    std::cout << std::endl;
}
