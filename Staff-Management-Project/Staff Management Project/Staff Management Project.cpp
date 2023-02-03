// Staff Management Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Employee.h"
#include "Admin.h"
#include "App.h"

using std::cin;
using std::cout;
using std::endl;


int main()
{
    // Testing that the employee constructor works
   // Admin musa;
    //musa.addStaff();
   // musa.viewAllEmployees();
   // musa.viewEmployee();
   // musa.editEmployee();
    //musa.deleteEmployee();

    App app;
    app.appLogic();
    return 0;
}

