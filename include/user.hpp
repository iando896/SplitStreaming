#pragma once
#include <string>
#include <vector>
#include "StreamingService.hpp"

static int userids = 0;

class User {
    private:
        std::string name;
        std::string venmoUser;
        unsigned int userid;
        float amountOwed;
    public:
        User();
        User(const std::string& name, const std::string& venmoUser);
        ~User();
        // User(const User& user);
        //User& operator=(User& rhs);
        std::string getName() const;
        std::string getName();
        std::string getVenmoUser() const;
        std::string getVenmoUser();
        const unsigned int getId() const;
        const unsigned int getId();
        void printUser();
        void addAmountOwed(float amount);
};

User parseUserAndServicesFromLine(const std::string& line, std::vector<StreamingService>& streams);