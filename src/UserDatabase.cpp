#include "UserDatabase.hpp"
#include <iostream>
UserDatabase::UserDatabase() 
:   paidUser(),
    db()
{}

UserDatabase::~UserDatabase() 
{}

std::unordered_map<unsigned int, User>::iterator UserDatabase::begin() {
    return db.begin();
}

std::unordered_map<unsigned int, User>::iterator UserDatabase::end() {
    return db.end();
}


void UserDatabase::addPaidUser(const std::string& line, std::vector<StreamingService>& streams) {
    paidUser = parseUserAndServicesFromLine(line, streams);
}

void UserDatabase::addUserFromLine(const std::string& line, std::vector<StreamingService>& streams) {
    User temp = parseUserAndServicesFromLine(line, streams);
    db[temp.getId()] = temp;
}

User& UserDatabase::getUserFromID(unsigned int id) {
    if (id == 0)
        return paidUser;
    if (db.count(id) == 0) 
        std::cout << "Not in UserDB" << std::endl;
    return db[id];
}

void UserDatabase::printUserDB() {
    std::cout << "----User DB----" << std::endl;
    std::cout << "Paid User:" << std::endl;
    paidUser.printUser();
    for (auto user : db) {
        user.second.printUser();
    }
}