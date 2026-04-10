#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <cstdlib>
#include <iostream>
#include <string>

class Application {
public: 
Application();

std::string getTitle();
std::string getBody();

private: 
    int appID;
    std::string title;
    std::string body;
};

#endif //_APPLICATION_H