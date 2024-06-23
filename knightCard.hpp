// Roniki04@gmail.com
#pragma once
#include "card.hpp"

class KnightCard : public Card {
    public:
    KnightCard(const std::string type) : Card(type) {}
    void use() override; // Override the use function of card

};