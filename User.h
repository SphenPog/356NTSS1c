#ifndef _USER_H
#define _USER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "Application.h"

class User {
public: 
User();

bool checkPass();
Application getApps();
void addApp(std::string title, std::string body);
void removeApp(int index);

private: 
    std::string username;
    std::string password;
    std::string email;
    int phone;
    bool adminFlag;
    Application applications[];
};

#endif //_USER_H