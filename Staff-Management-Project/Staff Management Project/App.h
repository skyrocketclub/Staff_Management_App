#pragma once

/*
This app class basically controls the logic for both the

Admin and the employee mode...

Admin.login

1. Ask the user to login
2. Check if the user is Musa, or an already registered user
3. If the user is able to login, then
		Show the things that the admin is able to do like...

		 --- Add an admin
		 --- View all Admins (In a sorted manner, keep it short and simple )
		 --- Add an Employee
		 --- View all Employees
		 --- Remove an Employee

*/

#include <string>
#include <sqlite3.h>
#include <iostream>

#include "Employee.h"
#include "Admin.h"

using std::cin;
using std::cout;
using std::string;
using std::cerr;
using std::endl;


class App
{
public:
	App();
	~App();

	string toUpperCase(string);
	string requestPassword();
	void checkPassword();

	void adminLogin();
	void employeeLogin();

private:
};

