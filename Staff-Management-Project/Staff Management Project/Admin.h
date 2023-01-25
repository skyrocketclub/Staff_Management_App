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
    string passWord_{ "" };

    

    // Function declarations
     int createDB();
     int createAdminTable();
    int createEmployeeTable(const char* s);
    void addEmployee();
    void viewAllEmployees();
    void viewEmployee(Employee);
    bool editEmployee(Employee);
    bool deleteEmployee(Employee);

    bool addAdmin();

private:
 
    const char* dir = "C:\\Users\\user\\Desktop\\Current Project Main\\office.db";
   // const char* dir = "C:\\Users\\charles\\source\\repos\\Staff_Management_App"
    string verifyPassword(string);

};

