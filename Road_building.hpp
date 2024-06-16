/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX3_SW2_ROAD_BUILDING_HPP
#define EX3_SW2_ROAD_BUILDING_HPP


#include "DevCard.hpp"

class Road_building: public DevCard {
public:
    Road_building();
    void action(Player & player,Board & board)const override;
};


#endif //EX3_SW2_ROAD_BUILDING_HPP
