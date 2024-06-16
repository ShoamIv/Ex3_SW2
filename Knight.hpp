/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX3_SW2_KNIGHT_HPP
#define EX3_SW2_KNIGHT_HPP


#include "DevCard.hpp"

class Knight: public DevCard {
public:
    Knight();
    void action(Player  & player,Board & board) const override;
    static void Check_Knight(Player & p);
};


#endif //EX3_SW2_KNIGHT_HPP
