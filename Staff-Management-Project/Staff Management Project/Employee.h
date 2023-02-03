#pragma once

#include <string>;
using std::string;

class Employee
{
public:
    Employee(string firstname, string lastname, string sex);
    Employee();
    ~Employee();

    string firstName_{ "" };
    string lastName_{ "" };
    string sex_{ "" };
    string role_{ "" };


private:
};

