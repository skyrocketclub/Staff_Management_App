#pragma once

#include <string>
#include "Employee.h"
#include <sqlite3.h>
#include <iomanip>

using std::string;


class Admin
{
public:
    Admin();
    ~Admin();
    Admin(string firstname, string lastname, string sex);

    string firstName_{ "" };
    string lastName_{ "" };
    string sex_{ "" };
    string role_{ "" };
    string passWord_{ "" };

    

    // Function declarations
    bool addStaff();
    void viewAllEmployees();
    void viewEmployee();
    bool editEmployee();
    bool deleteEmployee();

   

private:
    //path to the db in my computer
    const char* dir = "C:\\Users\\user\\Desktop\\Current Project Main\\office.db";


   // const char* dir = "c:\\users\\user\\desktop\\Staff Management Project\\office.db";

    bool addAdminToDB(Admin);
    bool addEmployeeToDB(Employee);
    int createEmployeeTable();
    int createDB();
    int createAdminTable();
    //for output data to the console...
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
};

