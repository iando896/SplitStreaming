#include "UserDatabase.hpp"
#include <iostream>
UserDatabase::UserDatabase() 
:
    db()
{}

UserDatabase::~UserDatabase() {

}

void UserDatabase::addPaidUser(const std::string& line, std::vector<StreamingService>& streams) {
    paidUser = parseUserAndServicesFromLine(line, streams);
}

void UserDatabase::addUserFromLine(const std::string& line, std::vector<StreamingService>& streams) {
    User temp = parseUserAndServicesFromLine(line, streams);
    db[temp.getId()] = temp;
}

User& UserDatabase::getUserFromID(unsigned int id) {
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