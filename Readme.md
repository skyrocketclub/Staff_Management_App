# STAFF MANAGEMENT APPLICATION

This is an open source C++ project which makes use of sqlite3 as the database.

This Application is used to enable the users (both the admin and the employees) to carry out some actions but with different levels of privileges
The assumption is that an admin will definitely be a member of HR for the company.

The HR can add, view and delete employees, while employees can send messages to the admin via the platform

## STACKS

C++
SQLITE (For DataBase)
Visual Studio
Sqlite DB Viewer, to help you view changes in your db as they happen (https://download.sqlitebrowser.org/SQLiteDatabaseBrowserPortable_3.12.2_English.paf.exe)

## How to Get Started

1. Clone this Repository
2. View in Project Mode
3. Right Click the project and click on "Manage Nuget Packages"
4. If "sqlite3_c_plus_plus" is not already under installed, go to "Browse" and the search for "sqlite3_c_plus_plus"
5. Install the one by "Dawlin Pena L. & Allam Gallam" (should be the first)
6. After installing, you should see "packages.config" under your "sources" folder...
7. If not already there, include the "sqlite3.c" file into your "Source Files" folder, using the "Add Existing option"
8. You are good to go

## For Developers

1. Follow the steps on how to get started
2. Look through the current Issues
3. Create an issue (if needed)
4. Create a Pull Request When you are done

## Things to look out for (Very Important)

1. Cross-Check the path of the "dir" in the "Admin.h" file. that is the path where the db is to be created and subsequently stored, this may differ for each person and that path may be invalid in your pc.
