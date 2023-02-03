#include <iostream>
#include "Admin.h"
//#include <sqlite3.h>

using std::cin;
using std::cout;
using std::string;
using std::cerr;
using std::endl;

//setting default values for the Admin
/*
1. Default username: admin, default password: admin

2. If you log in using the default account...

The you have the opportunity to ---> Demonstrating CRUD

 --- View all Admins 
 --- View all Employees
 --- Remove an Employee
*/

Admin::Admin()
{
    firstName_ = "admin";
}

Admin::~Admin()
{
}

Admin::Admin(string firstname, string lastname, string sex) {
    firstName_ = firstname;
    lastName_ = lastname;
    sex = sex;
}


//If the Data base at that particular direction is not available, then it will be created...
 int Admin::createDB() {
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(dir, &DB);
    sqlite3_close(DB);
    return 0;
}

//Function to add admin and employee
 bool Admin::addStaff()
 {
     bool success{};
     int choice;

     cout << "Would you like to add\n1 - ADMIN\n2 - EMPLOYEE\nCHOICE:  ";
     cin >> choice;

     string f_name{ "" }, l_name{ "" }, sex{ "" }, role{ " " }, p_word{ "" };
     int sex_option{}, role_option{};

     //The user comes back here if he/she wants to make changes to the input...
     if (choice == 1) {
         cout << "ENTER THE FOLLOWING DETAILS OF THE ADMIN\nFIRST NAME: ";
     }
     else {
         cout << "ENTER THE FOLLOWING DETAILS OF THE EMPLOYEE\nFIRST NAME: ";
     }
     
     cin >> f_name;

     cout << "LAST NAME: ";
     cin >> l_name;

     cout << "SEX\n1: MALE\n2: FEMALE\nCHOICE: ";
     cin >> sex_option;

     if (sex_option == 1) {
         sex = "MALE";
     }
     else if (sex_option == 2) {
         sex = "FEMALE";
     }


     if (choice == 1) {
         cout << "ROLE\n1: CEO\n2: HR1\n3: HR2\nCHOICE: ";
         cin >> role_option;
         if (role_option == 1) {
             role = "CEO";
         }
         else if (role_option == 2) {
             role = "HR1";
         }
         else if (role_option == 3) {
             role = "HR2";
         }
     }
     else {
         cout << "ROLE\n1: ACCOUNTANT\n2: ENGINEER\nCHOICE: ";
         cin >> role_option;
         if (role_option == 1) {
             role = "ACCOUNTANT";
         }
         else if (role_option == 2) {
             role = "ENGINEER";
         };
     }

     if (choice == 1) {
         cout << "ENTER A SECURE PASSWORD - NOT LESS THAN 5 CHARACTERS: ";
         cin >> p_word;

     }

     if (choice == 1) {
         //adding the admin to the database...
         Admin admin;
         admin.firstName_ = f_name;
         admin.lastName_ = l_name;
         admin.sex_ = sex;
         admin.role_ = role;
         admin.passWord_ = p_word;
         success = addAdminToDB(admin);
     }
     else if (choice == 2) {
         //adding employee to the database
         Employee employee;
         employee.firstName_ = f_name;
         employee.lastName_ = l_name;
         employee.sex_ = sex;
         employee.role_ = role;
         success = addEmployeeToDB(employee);
     }
     return success;
 }

 int Admin::createEmployeeTable() {
     sqlite3* DB;
     string sql = "CREATE TABLE IF NOT EXISTS EMPLOYEE("
         "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
         "FNAME      TEXT NOT NULL,"
         "LNAME      TEXT NOT NULL,"
         "SEX        TEXT NOT NULL,"
         "ROLE       TEXT NOT NULL);";

     try {
         int exit = 0;
         exit = sqlite3_open(dir, &DB);

         char* messageError;
         exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

         if (exit != SQLITE_OK) {
             cerr << "Error Creating Employee Table" << endl;
             sqlite3_free(messageError);
         }
         else {
             cout << "Employee Table created Successfully" << endl;
             sqlite3_close(DB);
         }
     }
     catch (const std::exception& e) {
         cerr << e.what();
     }
     return 0;
}


//PENDING
void Admin::viewAllEmployees()
{
}

//PENDING
void Admin::viewEmployee(Employee employee)
{
}

//PENDING
bool Admin::editEmployee(Employee employee)
{
    return true;
}

//PENDING
bool Admin::deleteEmployee(Employee employee)
{
    return true;
}


bool Admin::addEmployeeToDB(Employee employee) {

    createEmployeeTable();
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(dir, &DB);

    //getting the employee values from the argument
    string f_name = employee.firstName_;
    string l_name = employee.lastName_;
    string sex = employee.sex_;
    string role = employee.role_;

    string sql = "INSERT INTO EMPLOYEE (FNAME,LNAME,SEX,ROLE) VALUES('" + f_name + "','"
        + l_name + "','" + sex + "','" + role + "');";
    cout << "\nCONFIRM DETAILS OF NEW ADMIN\n";
    cout << "Firstname: " << f_name
        << "\nLastname: " << l_name
        << "\nSex: " << sex
        << "\nRole: " << role << "\n\n";

    int confirmation{};
    cout << "1: Confirmed\n2: Changes Required\nChoice: ";
    cin >> confirmation;
    if (confirmation == 1) {
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error Adding Employee\n";
            sqlite3_free(messageError);
        }
        else {
            cout << "Employee added successfully\n";
        }
    }
    else {
        addStaff();
    }

    return true;
}

int Admin::createAdminTable() {

    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS ADMIN("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "FNAME      TEXT NOT NULL,"
        "LNAME      TEXT NOT NULL,"
        "SEX        TEXT NOT NULL,"
        "ROLE       TEXT NOT NULL,"
        "PASSWORD   TEXT NOT NULL);";

    try {
        int exit = 0;
        exit = sqlite3_open(dir, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            cerr << "Error Creating Table" << endl;
            sqlite3_free(messageError);
        }
        else {
            cout << "Admin Table created Successfully" << endl;
            sqlite3_close(DB);
        }
    }
    catch (const std::exception& e) {
        cerr << e.what();
    }
    return 0;
}

bool Admin::addAdminToDB(Admin admin) {
    
    createAdminTable();

    //Allowing the Admin to add other admins...
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(dir, &DB);

    string f_name = admin.firstName_;
    string l_name = admin.lastName_;
    string sex = admin.sex_;
    string role = admin.role_;
    string p_word = admin.passWord_;


    string sql = "INSERT INTO ADMIN (FNAME,LNAME,SEX,ROLE,PASSWORD) VALUES('" + f_name + "','"
        + l_name + "','" + sex + "','" + role + "','" + p_word + "');";
    cout << "\nCONFIRM DETAILS OF NEW ADMIN\n";
    cout << "Firstname: " << f_name
        << "\nLastname: " << l_name
        << "\nSex: " << sex
        << "\nRole: " << role
        << "\nPassword: " << p_word << "\n\n";

    int confirmation{};
    cout << "1: Confirmed\n2: Changes Required\nChoice: ";
    cin >> confirmation;
    if (confirmation == 1) {
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error Adding admin\n";
            sqlite3_free(messageError);
        }
        else {
            cout << "Admin added successfully\n";
        }
    }
    else {
        addStaff();
    }
    return true;
}