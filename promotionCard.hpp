// Roniki04@gmail.com
#include "card.hpp"

class PromotionCard : public Card {
    public:
    PromotionCard(const std::string type) : Card(type) {} // Constructor
    void use() override; // Override the use function of card
};



class monopolyCard : public PromotionCard {
    public:
    monopolyCard(const std::string type) : PromotionCard(type) {} // Constructor
    void use() override; // Override the use function of promotion card
};



class buildRoadCard : public PromotionCard {
    public:
    buildRoadCard(const std::string type) : PromotionCard(type) {} // Constructor
    void use() override; // Override the use function of promotion card
};



class plentyYearCard : public PromotionCard {
    public:
    plentyYearCard(const std::string type) : PromotionCard(type) {} // Constructor
    void use() override; // Override the use function of promotion card
};

