/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_DEVCARD_HPP
#define EX3_SW2_DEVCARD_HPP

#include "Board.hpp"
#include <string>
#include <utility>
class Player;


enum class CardType{
    KNIGHT,
    MONOPOLY,
    YEAR_OF_PLENTY,
    ROAD_BUILDING,
    VICTORY_POINT
};

class DevCard {
    CardType type;
    std::string card_name;

public:
    DevCard(CardType type, std::string name){this->type=type;
        set_name(std::move(name));}
    [[nodiscard]] CardType Get_type() const {return this->type;}
    void set_name(std::string n){this->card_name=std::move(n);}
    std::string Get_Card_name(){return this->card_name;}
    virtual void action(Player  & player,Board & board)const=0;

};


#endif //EX3_SW2_DEVCARD_HPP
