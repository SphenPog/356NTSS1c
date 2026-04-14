#include "User.h"
#include "Application.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructor
User::User(std::string username, std::string password, bool admin) {
    this->username = username;
    this->password = password;
    this->adminFlag = admin;
}

bool User::checkPass(std::string passAtmpt) {
    if (passAtmpt == this->password) {
        return true;
    } else {
        return false;
    }
}

//getter
std::vector<Application> User::getApps() {
    return applications;
}

//modify and append private vector of applications
void User::addApp(int appId, std::string title, std::string body) {
    Application* app = new Application(appId);
    app->setTitle(title);
    app->setBody(body);
    this->applications.push_back(*app);
}

void User::removeApp(int index) {
    this->applications.erase(applications.begin() + index);
}