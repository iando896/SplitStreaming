#pragma once
#include <string>

static int userids = 0;

class User {
    private:
        std::string name;
        std::string venmoUser;
        const unsigned int userid;
        float amountOwed;
    public:
        User();
        User(const std::string& name, const std::string& venmoUser);
        ~User();
        User(User& user);
        //User& operator=(User& rhs);
        std::string getName();
        std::string getVenmoUser();
        unsigned int getId();
};

User parseUserFromLine(const std::string& line);