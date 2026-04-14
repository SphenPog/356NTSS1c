#include <cstdlib>
#include <iostream>
#include <string>
#include "Application.h"
#include "User.h"

using namespace std;

User* users[10];
User* currentUser = nullptr;
std::vector<Application> apps;

User* createAccount(string username, string password) {
    cout << "Create New Username: " << endl;
    cin >> username;
    cout << "Create Password: " << endl;
    cin >> password;

    User* newUser = new User(username, password, false);
    for (int i = 0; i < 10; i++) {
        if (users[i] == nullptr) {
            users[i] = newUser;
            return newUser;
        }
    }
    cout << "account limit reached." << endl;
    return nullptr;
}

User* promptLogin() {
    cout << "Enter Username or press 1 to create an account: " << endl;
    string username;
    cin >> username;

    if (username == "1") {
        return createAccount(username, username);
    } else { 

    for (int i = 0; i < 10; i++ ) {
        if (users[i] != nullptr)
        {
            if (username == users[i]->username) {
            return users[i];
            }
        }
    }
    cout << "username not found." << endl;
    }
    return nullptr;
}

void viewApps(User* user) {

    apps = user->getApps();
    
    if (apps.empty()) {
        cout << "there are no aplications to display" << endl << endl;
        return;
    }

    for (int i = 0; i < apps.size(); i++) {
        cout << i << ". Title: " << apps[i].getTitle() << endl;
    }

    int choice = 0;

    cout << "choose which app to view." << endl;
    cin >> choice;

    Application currentApp = apps[choice];
    cout << currentApp.getTitle() << endl << endl
        << currentApp.getBody() << endl;

    cout << "press 0 to return." << endl;
    cin >> choice;
    if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }
    
}

void createApp (User* user) {
    string title;
    string body;
    cout << "enter title for Application." << endl;

    cin.ignore();
    getline(cin, title);

    cout << "enter body for Application." << endl;

    getline(cin, body);

    user->addApp(2, title, body);
    cout << "application added." << endl << endl;
}


int main() {
    //setting up basic premade accounts for tests
    static User* adminUser = new User("admin", "password", true);
    static User* basicUser = new User("bob", "bob123", false);

    users[0] = adminUser;
    users[1] = basicUser;

    basicUser->addApp(1, "test", "this is a test for applications!!");

    //prompt user for login information and verify password
    while (currentUser == nullptr) {
        currentUser = promptLogin();
    }

    string password;
    cout << "enter password:" <<endl;
    while (!currentUser->checkPass(password))
    {
        cin >> password;

        if (!currentUser->checkPass(password)) {
        cout << "wrong password entered." << endl
             << "try again." << endl;
        } else {
            break;
        }
    }

    int choice = 0;

    cout << "login successful!" << endl;    

    //prompt user for what they want to do until they choose to log out
    while (choice != 3) {

        cout << "Press the following buttons to make a selection. (1-4)" << endl
            << "1. view applications" << endl
            << "2. create new application" << endl
            << "3. Logout" << endl;

        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }
        
        //handle user input and call appropriate functions
        switch (choice)
        {
        case 1:
            viewApps(currentUser);
            break;
        case 2:
            createApp(currentUser);
            break;
        case 3:
            cout << "Logging off..." << endl;
            break;
        default:
            cout << "invalid choice." << endl;
            break;
        }
    }
}