/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX3_SW2_VICTORYPOINT_HPP
#define EX3_SW2_VICTORYPOINT_HPP


#include "DevCard.hpp"

class VictoryPoint: public DevCard {
public:
    VictoryPoint();
    void action(Player  & player,Board & board)const override;
};


#endif //EX3_SW2_VICTORYPOINT_HPP
