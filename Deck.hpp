/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_DECK_HPP
#define EX3_SW2_DECK_HPP
#include "Knight.hpp"
#include "Monopoly.hpp"
#include "Road_building.hpp"
#include "VictoryPoint.hpp"
#include "Year_Of_Plenty.hpp"

class Deck {

public:
    static std::vector<DevCard*> deck;
    Deck();
    [[nodiscard]] static std::vector<DevCard*> getDeck() {return Deck::deck;}
    static void shuffle();
    static DevCard* ExtractCard();
};


#endif //EX3_SW2_DECK_HPP
