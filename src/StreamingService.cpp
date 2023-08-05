#include "StreamingService.hpp"
#include <sstream>
#include <iostream>

StreamingService::StreamingService(std::string name, float price) 
:   name(name),
    price(price)
{}

StreamingService::~StreamingService() 
{}

float StreamingService::getPricePerUser() const {
    if (!ids.size())
        return 0;
    return price / ids.size();
}

std::unordered_set<unsigned int> StreamingService::getIds() {
    return ids;
}

void StreamingService::printStream() {
    // std::cout << "---Streaming Service---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "User Count: " << ids.size() << std::endl;
    std::cout << "Price: " << price << std::endl << std::endl;

}

std::string StreamingService::getName() {
    return name;
}

float StreamingService::getPrice() {
    return price;
}

void StreamingService::addID(unsigned int id) {
    ids.insert(id);
}

StreamingService parseStreamingServices(const std::string& line) {
    std::stringstream ss(line);

    std::string name, price;
    std::getline(ss, name, ',');
    ss >> price;
    return StreamingService(name, std::stof(price));
}   