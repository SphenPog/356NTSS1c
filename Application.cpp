#include "Application.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//constructor
Application::Application(int appId) {
    appID = appId;
    title = "empty.";
    body = "empty.";

}

//getters and setters for private variables
string Application::getTitle() {
    return this->title;
}

string Application::getBody() {
    return this->body;
}

void Application::setTitle(std::string newTitle){
    this->title = newTitle;
}

void Application::setBody(std::string newBody){
    this->body = newBody;
}