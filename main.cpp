#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Degree enum
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Student class
class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    Student() {
        studentID = "";
        firstName = "";
        lastName = "";
        email = "";
        age = 0;
        for (int i = 0; i < 3; ++i) daysInCourse[i] = 0;
        degreeProgram = SOFTWARE;
    }

    Student(string id, string first, string last, string mail, int a, int days[], DegreeProgram dp) {
        studentID = id;
        firstName = first;
        lastName = last;
        email = mail;
        age = a;
        for (int i = 0; i < 3; ++i) daysInCourse[i] = days[i];
        degreeProgram = dp;
    }

    string getStudentID() const { return studentID; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getEmail() const { return email; }
    int getAge() const { return age; }
    int* getDaysInCourse() { return daysInCourse; }
    DegreeProgram getDegreeProgram() const { return degreeProgram; }

    void print() {
        cout << "ID: " << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName
             << "\tAge: " << age << "\tDays In Course: {" << daysInCourse[0] << ", "
             << daysInCourse[1] << ", " << daysInCourse[2] << "} Degree Program: ";
        switch (degreeProgram) {
            case SECURITY: cout << "Security"; break;
            case NETWORK: cout << "Network"; break;
            case SOFTWARE: cout << "Software"; break;
        }
        cout << endl;
    }
};

// Roster class
class Roster {
private:
    int lastIndex;
    int capacity;
    Student** classRosterArray;

public:
    Roster(int capacity = 5) {
        this->capacity = capacity;
        this->lastIndex = -1;
        this->classRosterArray = new Student*[capacity];
    }

    ~Roster() {
        for (int i = 0; i <= lastIndex; ++i) {
            delete classRosterArray[i];
        }
        delete[] classRosterArray;
    }

    void add(string studentID, string firstName, string lastName, string email,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
        int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysArray, degreeProgram);
    }

    void remove(string studentID) {
        bool found = false;
        for (int i = 0; i <= lastIndex; ++i) {
            if (classRosterArray[i]->getStudentID() == studentID) {
                found = true;
                delete classRosterArray[i];
                for (int j = i; j < lastIndex; ++j) {
                    classRosterArray[j] = classRosterArray[j + 1];
                }
                lastIndex--;
                cout << "Student with ID " << studentID << " removed." << endl;
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found." << endl;
    }

    void printAll() {
        for (int i = 0; i <= lastIndex; ++i) {
            classRosterArray[i]->print();
        }
    }

    void printAverageDaysInCourse(string studentID) {
        for (int i = 0; i <= lastIndex; ++i) {
            if (classRosterArray[i]->getStudentID() == studentID) {
                int* days = classRosterArray[i]->getDaysInCourse();
                cout << "Average days in course for " << studentID << ": "
                     << (days[0] + days[1] + days[2]) / 3 << endl;
            }
        }
    }

    void printInvalidEmails() {
        for (int i = 0; i <= lastIndex; ++i) {
            string email = classRosterArray[i]->getEmail();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email: " << email << endl;
            }
        }
    }

    void printByDegreeProgram(DegreeProgram degreeProgram) {
        for (int i = 0; i <= lastIndex; ++i) {
            if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
                classRosterArray[i]->print();
            }
        }
    }
};

// Main function
int main() {
    cout << "C867 - Scripting and Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "WGU Student ID: 012418342" << endl;
    cout << "Name: Janet Otieno" << endl << endl;

    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Janet,Otieno,otienojano17@gmail.com,21,20,25,30,SOFTWARE"
    };

    Roster classRoster;

    for (string record : studentData) {
        stringstream ss(record);
        string token;
        string parts[9];
        int i = 0;
        while (getline(ss, token, ',')) {
            parts[i++] = token;
        }

        DegreeProgram dp = SOFTWARE;
        if (parts[8] == "SECURITY") dp = SECURITY;
        else if (parts[8] == "NETWORK") dp = NETWORK;

        classRoster.add(parts[0], parts[1], parts[2], parts[3], stoi(parts[4]),
                        stoi(parts[5]), stoi(parts[6]), stoi(parts[7]), dp);
    }

    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    for (int i = 1; i <= 5; ++i) {
        classRoster.printAverageDaysInCourse("A" + to_string(i));
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
