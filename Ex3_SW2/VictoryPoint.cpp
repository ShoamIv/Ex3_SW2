/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "VictoryPoint.hpp"
#include "Player.hpp"

VictoryPoint::VictoryPoint()
        : DevCard(CardType::VICTORY_POINT, "Victory Point") {}

void VictoryPoint::action(Player &player,Board & board) {
player.set_Winning_p(1);

}
