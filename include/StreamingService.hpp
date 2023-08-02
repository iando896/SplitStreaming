#pragma once
#include <string>
#include <vector>
#include <stdint.h>
#include <unordered_set>

// #define SPOTIFY "Spotify"
// #define APPLE "Apple TV"
class StreamingService {
private:
    std::string name; //unique
    std::unordered_set<unsigned int> ids;
    float price;
public:
    StreamingService(std::string name, float price);
    ~StreamingService();
    std::string getName();
    float getPrice();
    std::unordered_set<unsigned int> getIds();
    float getPricePerUser() const;
    void printStream();
    void addID(unsigned int id);
    // void updateAmountOwed(const std::vector<User>& users);
};

StreamingService parseStreamingServices(const std::string& line);
