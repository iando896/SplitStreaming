#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "User.hpp"
#include "UserDatabase.hpp"
#include "StreamingService.hpp"

#define USER_FILE "rsrc/Users.csv"
#define STREAMS_FILE "rsrc/Streaming.csv"

UserDatabase UserDB;
std::vector<StreamingService> StreamingServices;

void initStreamingServices() {
    std::ifstream StreamingServiceFile;
    StreamingServiceFile.open(STREAMS_FILE);

    if (!StreamingServiceFile.is_open()) {
        std::cout << "Failed to open Streaming" << std::endl;
        //TODO: Add exception handling
    }

    std::string line;
    while(!StreamingServiceFile.eof()) {
        std::getline(StreamingServiceFile, line);
        //TODO: Assert line
        StreamingServices.push_back(parseStreamingServices(line));
    }
}

void initUserDB() {
    //parse user file and create user objects
    //skip first line and create payer
    //Create rest of uesrs

    std::ifstream userFile;
    userFile.open(USER_FILE);

    if (!userFile.is_open()) {
        std::cout << "Failed to open user" << std::endl;
    }

    userFile.ignore(LONG_MAX, '\n');
 
    std::string line;
    std::getline(userFile, line);
    UserDB.addPaidUser(line, StreamingServices);

    while (!userFile.eof()) {
        std::getline(userFile, line);
        UserDB.addUserFromLine(line, StreamingServices);
    }
}

void updateAmountOwed() {
    for (auto stream : StreamingServices)
    {
       for (auto id : stream.getIds()) {
        UserDB.getUserFromID(id).addAmountOwed(stream.getPricePerUser());
       }
    }
    
}

int main(int argc, char *argv[]) {
    //Parse csv file for users, streaming services, and mapping
    //Init streaming services db using 
    initStreamingServices();
    // std::cout << StreamingServices.size() << std::endl;
    
    //Init user database
    initUserDB();

    updateAmountOwed();

    UserDB.printUserDB();

    //Calculate prices for each person
    //Divide price per user
    //update amount owed by each user
    std::cout << "----Streaming Services----" << std::endl;
    for (auto stream : StreamingServices) {
        stream.printStream();
        // std::cout << stream.getIdsSize() <<std::endl;
    }
    //Send out venmo requests
}