#ifndef _USER_H
#define _USER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Application.h"

class User {
public: 
std::string username;

User(std::string username, std::string password, bool admin);

bool checkPass(std::string passAtmpt);
std::vector<Application> getApps();
void addApp(int appId, std::string title, std::string body);
void removeApp(int index);

//getters and setters for email and phone number, not currently used but may be in the future
//std::string getEmail();
//bool setEmail(std::string email);

private: 
    std::string password;
    std::string email;
    int phone;
    bool adminFlag;
    std::vector<Application> applications;
};

#endif //_USER_H