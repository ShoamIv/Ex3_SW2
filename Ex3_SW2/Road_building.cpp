/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include <iostream>
#include "Road_building.hpp"
#include "Player.hpp"

Road_building::Road_building()
        : DevCard(CardType::ROAD_BUILDING, "Road Building") {}

void Road_building::action(Player &player,Board & board) {
    player.set_road_token();

}


