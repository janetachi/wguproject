#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

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
        "A5,YourFirstName,YourLastName,YourEmail@domain.com,21,20,25,30,SOFTWARE"
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
