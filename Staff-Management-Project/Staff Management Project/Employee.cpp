#include "Employee.h"

#include <string>
#include <iostream>

using std::cout;
using std::string;

// constructor with initializations
Employee::Employee(string firstname, string lastname, string sex)
{
    firstName_ = firstname;
    lastName_ = lastname;
    sex_ = sex;
}

// default contructor
Employee::Employee() {}

Employee::~Employee() {}

void Employee::viewProfile()
{
    cout << "Name: " << this->firstName_ << " " << this->lastName_ << "\n";
    cout << "Sex: " << this->sex_ << "\n";
}