#include <iostream>
#include "promotionCard.hpp"

void PromotionCard::use() {
    // do nothing
}

void monopolyCard::use() {
    std::cout << "Monopoly Card used" << std::endl;
}

void buildRoadCard::use() {
    std::cout << "Build Road Card used" << std::endl;
}

void plentyYearCard::use() {
    std::cout << "Plenty Year Card used" << std::endl;
}
