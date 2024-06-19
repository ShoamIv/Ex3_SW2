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
    Deck();
    static std::vector<DevCard*> deck;


public:
    static Deck * getdeck() ;
    //static Deck * pt;
    ~Deck();
    [[nodiscard]] static std::vector<DevCard*> getDeck() {return Deck::deck;}
    static void shuffle();
    static DevCard* ExtractCard();
    void clean_up();
};


#endif //EX3_SW2_DECK_HPP
