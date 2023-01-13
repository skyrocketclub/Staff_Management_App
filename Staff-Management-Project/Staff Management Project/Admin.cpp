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
ADD MUSA Who is the CEO of the company to the DB, so that he can always access and perform other functions
This means that the Admin is accessible on two conditions

1. If Musa is the one to log in

 --- The first time Musa adds an admin, Musa's details are added already (but only the first time)
 FName - Musa
 LName - Datti
 Sex - Male
 Role - CEO
 Password - admin

2. If the admin and password tallies with sth obtainable in the DB

The you have the opportunity to 

 --- Add an admin
 --- View all Admins (In a sorted manner, keep it short and simple ) 
 --- Add an Employee
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
    //const char* dir = "c:\\users\\user\\desktop\\Staff Management Project\\office.db";
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(dir, &DB);
    sqlite3_close(DB);
    return 0;
}


 int Admin::createAdminTable() {

     sqlite3* DB;
     /*const char* dir = "c:\\users\\user\\desktop\\Staff Management Project\\office.db";*/


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
     catch (const std::exception & e) {
         cerr << e.what();
     }
     return 0;
}

 int Admin::createEmployeeTable(const char* s) {
     return 0;
}
void Admin::addEmployee() {

}

void Admin::viewAllEmployees()
{
}

void Admin::viewEmployee(Employee employee)
{
}

bool Admin::editEmployee(Employee employee)
{
    return true;
}

bool Admin::deleteEmployee(Employee employee)
{
    return true;
}

bool Admin::addAdmin()
{
   

    //Just incase the ADMIN table has not been created
    createAdminTable();

    //Allowing the Admin to add other admins...
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open(dir, &DB);
    string f_name{ "" }, l_name{ "" }, sex{ "" }, role{ " " },p_word{ "" };
    int sex_option{}, role_option{};

    //The user comes back here if he/she wants to make changes to the input....
    confirm: cout << "ENTER THE FOLLOWING DETAILS OF THE ADMIN\nFIRST NAME: ";
    cin >> f_name;
    cout << "LAST NAME: ";
    cin >> l_name;
    cout << "SEX\n1: MALE\n2: FEMALE\n3: CHOICE: ";
    cin >> sex_option;
   
    if (sex_option == 1) {
        sex = "MALE";
    }
    else if (sex_option == 2) {
        sex = "FEMALE";
    }

    cout << "ROLE\n1: CEO\n2: HR1\n3: HR2\nCHOICE: ";
    cin >> role_option;
    if (role_option == 1) {
        role = "CEO";
    }
    else if (role_option == 2) {
        role = "HR1";
    }
    else {
        role = "HR2";
    }

     




    //This should be implemented...
    // this checks if the password is up to 5 characters
    // more conditions can be added to make the password input more robust...
    // p_word = this->verifyPassword(p_word);

    cout << "ENTER A SECURE PASSWORD - NOT LESS THAN 5 CHARACTERS: ";
    cin >> p_word;

    string sql = "INSERT INTO ADMIN (FNAME,LNAME,SEX,ROLE,PASSWORD) VALUES('" + f_name + "','"
        + l_name + "','" + sex + "','" + role +"','" + p_word + "');";
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
        goto confirm;
    }
    return true;
}

string Admin::verifyPassword(string password)
{
    string pass_{ "" };

    return pass_;
}