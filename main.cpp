#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "user.hpp"
#include "StreamingService.hpp"

#define USER_FILE "rsrc/user.csv"
#define STREAMS_FILE "rsrc/Streaming.csv"

std::vector<User> UserDB;
std::vector<StreamingService> Services;

void initStreamingServices() {
    std::ifstream StreamingServiceFile;
    StreamingServiceFile.open(STREAMS_FILE);

    if (!StreamingServiceFile.is_open()) {
    }

    
}

void initUserDB(std::vector<User>& db) {
    //parse user file and create user objects
    //skip first line and create payer
    //Create rest of uesrs

    std::ifstream userFile;
    userFile.open(USER_FILE);

    if (!userFile.is_open()) {
    }

    userFile.ignore(LONG_MAX, '\n');

    std::string line;
    while (userFile) {
        std::getline(userFile, line);
        db.push_back(parseUserFromLine(line));
    }
    
}

int main(int argc, char *argv[]) {
    //Parse csv file for users, streaming services, and mapping
    //Init streaming services db using 
    initStreamingServices();
    //Init user database
    initUserDB(UserDB);
    //Calculate prices for each person
    //Divide price per user
    //update amount owed by each user
    

    //Send out venmo requests
}