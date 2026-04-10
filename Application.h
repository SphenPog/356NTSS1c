#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <cstdlib>
#include <iostream>
#include <string>

class Application {
public: 
Application(int appId);

std::string getTitle();
std::string getBody();
void setTitle(std::string title);
void setBody(std::string body);

private: 
    int appID;
    std::string title;
    std::string body;
};

#endif //_APPLICATION_H