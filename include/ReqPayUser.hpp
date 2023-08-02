#pragma once
#include "User.hpp"

class ReqPayUser : public User
{
private:
    float amountOwed;
public:
    ReqPayUser(float amount);
    ~ReqPayUser();
};
