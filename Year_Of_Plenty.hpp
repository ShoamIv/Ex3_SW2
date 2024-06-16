/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_YEAR_OF_PLENTY_HPP
#define EX3_SW2_YEAR_OF_PLENTY_HPP


#include "DevCard.hpp"

class Year_Of_Plenty: public DevCard {
public:
    Year_Of_Plenty();
    void action(Player  & player,Board & board)const override;

};


#endif //EX3_SW2_YEAR_OF_PLENTY_HPP
