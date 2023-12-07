#include "User.hpp"
#include <sstream>
#include <iostream>

User::User() 
:   name(),
    venmoUser(),
    userid(0),
    amountOwed(0)
{}

User::User(const std::string& name, const std::string& venmoUser) 
:   name(name),
    venmoUser(venmoUser),
    userid(userids++),
    amountOwed(0)
{}

User::~User(){
}

// User::User(const User& user) 
// :   name(user.name),
//     venmoUser(user.venmoUser),
//     userid(user.userid)
// {}

std::string User::getName() const {
    return name;
}

std::string User::getName() {
    return name;
}

std::string User::getPriceMessage() const{
    return priceMessage;
}

std::string User::getPriceMessage() {
    return priceMessage;
}

std::string User::getVenmoUser() const {
    return venmoUser;
}

std::string User::getVenmoUser() {
    return venmoUser;
}

float User::getAmountOwed() const {
    return amountOwed;
}

float User::getAmountOwed() {
    return amountOwed;
}

const unsigned int User::getId() const {
    return userid;
}

const unsigned int User::getId() {
    return userid;
}

void User::printUser() {
    std::cout << "Name: " << name << std::endl
    << "Venmo User: " << venmoUser << std:: endl
    << "User id: " << userid << std::endl
    << "Amount owed: " << amountOwed << std::endl << std::endl;
}

void User::addAmountOwed(float amount) {
    amountOwed += amount;
}

void User::concatPriceMessage(const std::string& msg) {
    priceMessage += msg;
}


std::string removeQuotes(const std::string& s) {
    if ((s.size() < 2) || (s[0] != '"') || (s[s.size() - 1] != '"'))
        return "";
    return s.substr(1, s.size() - 2);
}

User parseUserAndServicesFromLine(const std::string& line, std::vector<StreamingService>& streams) {
    //Skip first column
    std::stringstream ss(line);
    std::string time, name, username, services;

    getline(ss, time, ',');
    getline(ss, name, ',');
    getline(ss, username, ',');
    getline(ss, services);


    std::stringstream serviceSS(removeQuotes(services));
    // std::cout << serviceSS.str() << std::endl;

    User ret(removeQuotes(name), removeQuotes(username));
    // std::cout << "ID: " << ret.getId() << std::endl;
    //User make request for stream
    //Stream tracks user requesting and 
    while (!serviceSS.eof()) {//Does this work??
        std::string temp;
        std::getline(serviceSS, temp, ';');
        for (auto& stream : streams) {
            if (!stream.getName().compare(temp)) {
                stream.addID(ret.getId());
                // std::cout << "Equal" << std::endl;
                // std::cout << stream.getIdsSize() << std::endl;
            }
       
        }
    }
    return ret;
}