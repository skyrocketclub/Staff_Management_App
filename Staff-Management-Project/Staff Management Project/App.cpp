#include "App.h"





App::App() {

}

App::~App() {

}

void App::appLogic() {
    int choice{};
    Admin admin;

    //Temporary . Subsequently, admin will have to enter username and password
    cout << "WELCOME TO THE STAFF MANAGEMENT APPLICATION\nYOU ARE LOGGED IN AS ADMIN\n";
    cout << "WHAT WOULD YOU LIKE TO DO?\n1 - ADD A STAFF\n2 - VIEW ALL EMPLOYEES\n3 - EDIT EMPLOYEE DETAILS\n4 - DELETE AN EMPLOYEE\n5 - QUIT\nCHOICE: ";
    cin >> choice;
    switch (choice)
    {
        case (1):
        {
            system("cls");
            cout << "\t\t\t====================ADDING A STAFF===========================\n";
            admin.addStaff();
            cout << endl << endl;
            appLogic();
        }
        break;
        case (2):
        {
            system("cls");
            cout << "\t\t\t====================VIEWING ALL EMPLOYEES===========================\n";
            admin.viewAllEmployees();

            cout << endl << endl;
            appLogic();
        }
        break;
        case (3):
        {
            system("cls");
            cout << "\t\t\t====================EDITING EMPLOYEE DETAILS===========================\n";
            admin.editEmployee();

            cout << endl << endl;
            appLogic();
        }
        break;
        case(4): 
        {
            system("cls");
            cout << "\t\t\t====================REMOVE EMPLOYEE FROM DATABASE===========================\n";
            admin.deleteEmployee();

            cout << endl << endl;
            appLogic();
        }
        break;
        case(5):
        {
            system("cls");
            cout << "\t\t\t====================GOODBYE===========================\n";
        }
        break;
        default:
        {
            cout << "Kindly enter a valid input\n";
        }
    }
}

