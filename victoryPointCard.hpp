// Roniki04@gmail.com
#include "card.hpp"

class VictoryPointCard : public Card {
    public:
    VictoryPointCard(const std::string type) : Card(type) {}
    void use() override; // Use the card
};

    