// SqliteDBTesting_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
REQUIREMENTS THAT SHOW YOU ARE READY TO USE THE DB FOR THE STAFF MANAGEMENT PROJECT

*/
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <string>


using namespace std;
 
//function declarations
static int createDB(const char* s);
static int createTable(const char* s);
static int deleteData(const char* s);
static int insertData(const char* s);
static int updateData(const char* s);
static int selectData(const char* s);

//Function declarations modified to be close to the operations for the employee management application
static int deleteDataCustom(const char* s);
static int insertDataCustom(const char* s);
//Displaying the data in my own way...
static int selectDataCustom(const char* s);

static int callback(void* NotUsed, int argc, char** argv, char** azColName);
static int callbackCustom(void* NotUsed, int argc, char** argv, char** azColName);

int main()
{
    //the double slash is important so that the folder can be in keeping the universal naming conventions of paths
    const char* dir = "c:\\users\\user\\desktop\\Staff Management Project\\SqliteDBTesting_\students.db";

    //Initializing the DB object
    sqlite3* db;
  /*  createDB(dir);
    createTable(dir);*/

    //Inserting Data into the DB
    //insertData(dir);  
    //Select data also outputs all the data because it has a callback function responsible for that purpose...
    //selectData(dir);
    selectDataCustom(dir);

    //Testing other methods of manipulating the database

    //Changing data of partcular people in the DB
    //updateData(dir);
    //cout << "After Updating the data\n";
    //selectData(dir);
    
   
    /*deleteData(dir);
     cout << "After Deleting from the data\n";
    selectData(dir);*/
    
    //cout << "After reinserting values into the data\n";

    //insertDataCustom(dir);
    //deleteDataCustom(dir);

  

    return 0;
}

static int createDB(const char* s) {
    sqlite3* DB;
    int exit = 0;

    // s here refers to the path, where the db is to be created...
    //I try to open the DB and if it does not exist, it will be created
    exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);

    return 0;
}

static int createTable(const char* s) {
    sqlite3* DB;

    //Creating the Table with a Schema kind of...
    //The title of the table is "GRADES"
    string sql = "CREATE TABLE IF NOT EXISTS DETAILS("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAME       TEXT NOT NULL, "
        "LNAME      TEXT NOT NULL, "
        "AGE        TEXT NOT NULL, "
        "ADDRESS    TEXT NOT NULL, "
        "GRADE      TEXT NOT NULL );";

    //error handling
    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            cerr << "Error Creating Table" << endl;
            sqlite3_free(messageError);
        }
        else {
            cout << "Table created Successfully" << endl;
            sqlite3_close(DB);
        }
    }
    catch (const exception & e) {
        cerr << e.what();
    }
    return 0;
}

static int insertData(const char* s) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    //Go to the directory titled "s" and look for the table titled GRADES and then insert into GRADES...
    string sql("INSERT INTO DETAILS (NAME,LNAME,AGE,ADDRESS,GRADE) VALUES('Alice', 'Chapa', '35', 'Tampa', 'A');"
        "INSERT INTO DETAILS (NAME,LNAME,AGE,ADDRESS,GRADE) VALUES('Bob', 'Lee', '20', 'Dallas', 'B');"
        "INSERT INTO DETAILS (NAME,LNAME,AGE,ADDRESS,GRADE) VALUES('Fred', 'Cooper', '24', 'New York', 'C');");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error Inserting" << endl;
        sqlite3_free(messageError);
    }
    else {
        cout << "Records created Successfully!" << endl;
    }
    return 0;
}

static int insertDataCustom(const char* s) {
    sqlite3* DB;
    sqlite3_stmt* st;

    char* messageError;
    int exit = sqlite3_open(s, &DB);

    string fName, lName, address, grade;
    int age;

    cout << "First Name: ";
    cin >> fName;
    cout << "Last Name: ";
    cin >> lName;
    cout << "Age: ";
    cin >> age;
    cout << "Address: ";
    cin >> address;
    cout << "Grades: ";
    cin >> grade;


    string sql="INSERT INTO DETAILS (NAME,LNAME, AGE, ADDRESS, GRADE) VALUES('" + fName + "','" + lName + "','" + std::to_string(age) + "','" + address + "','" + grade + "');";


    cout << sql << "\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error Inserting" << endl;
        sqlite3_free(messageError);
    }
    else {
        cout << " Student grade enterred successfully!\n\n\nRecords after entering: \n";
        selectData(s);
    }

    return 0;
}


//tHIS FUNCTION BASICALLY OUPTPUTS ALL THE ENTRIES
static int selectData(const char* s) {
    sqlite3* DB;

    int exit = sqlite3_open(s, &DB); 

    //This implies that you want all the grades  
    string sql = "SELECT * FROM DETAILS;";

    //arguments are -> open DB,sql to be evaluated, callback function, 1st argument to callback, Error message 
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    return 0;
}

//Enables us to output data from the database in the way that we want
static int selectDataCustom(const char* s) {
    sqlite3* DB;

    int exit = sqlite3_open(s, &DB);

    //This implies that you want all the grades  
    string sql = "SELECT * FROM DETAILS;";

    //arguments are -> open DB,sql to be evaluated, callback function, 1st argument to callback, Error message 
    cout << "ID     NAME        LAST NAME      AGE     ADDRESS       GRADE\n";
    sqlite3_exec(DB, sql.c_str(), callbackCustom, NULL, NULL);
    return 0;
}
/*
argc: holds the number of results
azColumn: holds each column returned in an array
argv: Holds each value in aray
*/
static int callback(void* NotUsed, int argc, char** argv, char** azColumn)
{
    for (int i{ 0 }; i < argc; i++) {
        //coolumn name and value
        cout << azColumn[i] << ": " << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

static int callbackCustom(void* NotUsed, int argc, char** argv, char** azColName) {

    for (int i{ 0 }; i < argc; i++) {
        cout << argv[i] << "            ";
    }
    cout << endl;
    return 0;
}

static int updateData(const char* s) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);
    
    //Table name is GRADES
    //Where clause prevents you from updating all the data entries

    string sql("UPDATE DETAILS SET GRADE = 'A' WHERE LNAME = 'Cooper';");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error Insert" << endl;
        sqlite3_free(messageError);
    }
    else {
        cout << "Records created Successfully!" << endl;
    }

    return 0;
}

static int deleteData(const char* s) {
    sqlite3* DB;

    int exit = sqlite3_open(s, &DB);

    //Delete everything from DB
    string sql = "DELETE FROM DETAILS;";
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

    return 0;
}

static int deleteDataCustom(const char* s) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);


    string sql = "DELETE FROM DETAILS WHERE LNAME = 'Cooper';";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error Deleting" << endl;
        sqlite3_free(messageError);
    }
    else {
        cout << "Record deleted Successfully!" << endl;
    }
    return 0;
}
