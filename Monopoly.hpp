/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX3_SW2_MONOPOLY_HPP
#define EX3_SW2_MONOPOLY_HPP
#include "DevCard.hpp"

class Monopoly: public DevCard  {
public:
    Monopoly();
    void action(Player  & player,Board & board)const override;

};


#endif //EX3_SW2_MONOPOLY_HPP
