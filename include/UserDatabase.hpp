#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "StreamingService.hpp"
#include "User.hpp"


//TODO: Make into singleton
class UserDatabase {
private:
    User paidUser;
    std::unordered_map<unsigned int,User> db;
public:
    UserDatabase();
    ~UserDatabase();
    void addPaidUser(const std::string& line, std::vector<StreamingService>& streams);
    void addUserFromLine(const std::string& line, std::vector<StreamingService>& streams);
    void removeUserByID(unsigned int id);
    User& getUserFromID(unsigned int id);
    void printUserDB();
};