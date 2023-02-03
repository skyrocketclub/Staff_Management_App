#pragma once

#include <string>
#include "Employee.h"
#include <sqlite3.h>

using std::string;

/*

1. Create DB
2. Create Table function ---> Factor in the details of the employee (including Inbox)
3. Carry out the other functions
4. The employee table ---> "EMPLOYEE"
5. The admin table ---> "ADMIN"
*/



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
    void viewEmployee(Employee);
    bool editEmployee(Employee);
    bool deleteEmployee(Employee);

   

private:
    //path to the db in my computer
    const char* dir = "C:\\Users\\user\\Desktop\\Current Project Main\\office.db";


   // const char* dir = "c:\\users\\user\\desktop\\Staff Management Project\\office.db";

    bool addAdminToDB(Admin);
    bool addEmployeeToDB(Employee);
    int createEmployeeTable();
    int createDB();
    int createAdminTable();
};

