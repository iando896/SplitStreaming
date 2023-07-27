#include "user.hpp"
#include <sstream>
#include <vector>
#include <iostream>

User::User() 
:   name(),
    venmoUser(),
    userid(++userids)
{}

User::User(const std::string& name, const std::string& venmoUser) 
:   name(name),
    venmoUser(venmoUser),
    userid(++userids)
{}

User::~User(){
}

// User::User(User& user) 
// :   name(user.getName()),
//     venmoUser(user.getVenmoUser()),
//     userid(user.getId())
// {}

std::string User::getName() {
    return name;
}

std::string User::getVenmoUser() {
    return venmoUser;
}

unsigned int User::getId() {
    return userid;
}

User parseUserAndServicesFromLine(const std::string& line) {
    //Skip first column
    std::stringstream ss(line);
    std::string time, name, username, services;
    // std::vector<std::string> servicesList;

    getline(ss, time, ',');
    getline(ss, name, ',');
    getline(ss, username, ',');
    getline(ss, services, ',');

    if (services.size() == 0) {
    }

    std::stringstream serviceSS(services.substr(1, services.size() - 2));
    std::cout << serviceSS.str() << std::endl;
    while (!serviceSS.eof()) {//Does this work??
        std::string temp;
        std::getline(serviceSS, temp, ',');
        //add to service 
        // servicesList.push_back(temp);
    }
    

    return User(name, username);
}