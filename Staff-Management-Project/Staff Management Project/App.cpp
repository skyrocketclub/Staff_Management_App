#include "App.h"





App::App() {

}

App::~App() {

}

string App::toUpperCase(string input)
{
	char *iter = &input[0];

	while (*iter != '\0') {
		if (*iter >= 'a' && *iter <= 'z') {
			*iter = *iter - 32;
		}
		*(iter++);
	}
	return string(input);
}

string App::requestPassword()
{
	string password;
	cout<< "Choose a password (Must have a length of 5 characters): " << endl;
	cin>> password;

	return string(password);
}

void App::checkPassword()
{
	int status = 1;
	while (status) {
		string password = requestPassword();
		if (password.length() == 5) {
			status = 0;
		}
		else {
			status = 1;
			cout << "Invalid password"<<endl;
		} 
	}
	
}



void App::adminLogin() {

}

void App::employeeLogin() {

}
