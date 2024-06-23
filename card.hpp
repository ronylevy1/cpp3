// Roniki04@gmail.com
#pragma once
#include <string>

class Card {
    public:
    std::string type; // The type of the card
    Card(const std::string type) : type(type) {}

    virtual void use() = 0; // Use the card
    std::string getType(); // Get the type of the card
};