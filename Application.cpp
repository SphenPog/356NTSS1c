#include "Application.h"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Application::Application(int appId) {
    appID = appId;
    title = "empty.";
    body = "empty.";

}

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