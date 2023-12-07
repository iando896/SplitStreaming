#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <User.hpp>
#include "UserDatabase.hpp"
#include "StreamingService.hpp"

// #define PY_SSIZE_T_CLEAN
// #include <Python.h>
#include <pybind11/embed.h>
namespace py = pybind11;

#define PATH_TO_USER "rsrc/Split Streaming Form.csv"
#define PATH_TO_STREAMING "rsrc/Streaming.csv"

UserDatabase UserDB;
std::vector<StreamingService> StreamingServices;

void initStreamingServices(char* fileName) {
    // std::cout << fileName << std:: endl;
    std::ifstream StreamingServiceFile;
    StreamingServiceFile.open(fileName);

    if (!StreamingServiceFile.is_open()) {
        std::cout << "Failed to open Streaming" << std::endl;
        //TODO: Add exception handling
    } else {
        std::string line;
        while(!StreamingServiceFile.eof()) {
            std::getline(StreamingServiceFile, line);
            //TODO: Assert line
            StreamingServices.push_back(parseStreamingServices(line));
        }
    }
}

void initUserDB(char* fileName) {
    //parse user file and create user objects
    //skip first line and create payer
    //Create rest of uesrs

    std::ifstream userFile;
    userFile.open(fileName);

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
        // std::cout << "Updating id: " << id << std::endl; 
        UserDB.getUserFromID(id).addAmountOwed(stream.getPricePerUser());
        std::stringstream ss;
        ss << stream.getName() << ": " << stream.getPricePerUser() << std::endl;
        UserDB.getUserFromID(id).concatPriceMessage(ss.str());
       }
    }
    
}

void printStreams() {
    std::cout << "----Streaming Services----" << std::endl;
    for (auto stream : StreamingServices) {
        stream.printStream();
        // std::cout << stream.getIdsSize() <<std::endl;
    }
}

//Pass the stream file, user file, and access token for Venmo
#include <filesystem>
int main(int argc, char *argv[]) {
    //Parse csv file for users, streaming services, and mapping
    std::filesystem::path cwd = std::filesystem::current_path();
    std::cout << cwd << std::endl;

    initStreamingServices(PATH_TO_STREAMING);
    // std::cout << StreamingServices.size() << std::endl;
    //Init user database
    initUserDB(PATH_TO_USER);

    updateAmountOwed();

    UserDB.printUserDB();
    printStreams();
    //Calculate prices for each person
    //Divide price per user
    //update amount owed by each user
    py::scoped_interpreter guard{};
    
    try
    {
        auto venmoModule = py::module::import("venmo");
        auto requestPayFunc = venmoModule.attr("request_pay");
        for (auto it = UserDB.begin(); it != UserDB.end(); it++) {
            if (argc > 1)
                requestPayFunc(it->second.getAmountOwed(), it->second.getPriceMessage(), it->second.getVenmoUser(), argv[1]);
            else
                requestPayFunc(it->second.getAmountOwed(), it->second.getPriceMessage(), it->second.getVenmoUser());
        }
    }
    catch(py::error_already_set& e)
    {
        std::cerr << e.what() << '\n';
    }
}