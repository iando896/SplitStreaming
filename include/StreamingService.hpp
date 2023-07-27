#pragma once
#include <string>
#include <vector>
#include "user.hpp"

// #define SPOTIFY "Spotify"
// #define APPLE "Apple TV"
class StreamingService {
private:
    std::string name; //unique
    std::vector<int> userIDs;
    float price;
public:
    StreamingService(std::string name, std::vector<std::string> users, float price);
    ~StreamingService();
};

