/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "Monopoly.hpp"
#include "Player.hpp"

Monopoly::Monopoly()
        : DevCard(CardType::MONOPOLY, "Monopoly") {}

void Monopoly::action(Player  & player,Board & board)const {

    std::cout<<player.getName()<<" Please choose resource to receive from the other players.\n";
    int res;
    std::cin>>res;
    std::cout<<player.getName()<<" pick: "<< res<<std::endl;
    for(int i=0; i<3; i++){
        if(Player::getPlayers().at(i)->getName()==player.getName())continue;else{
           int k=Player::getPlayers().at(i)->get_Resource().at(res);
            Player::getPlayers().at(i)->get_Resource().at(res)-=k;
            player.get_Resource().at(res)+=k;
            std::cout<<Player::getPlayers().at(i)->getName()<<" Transfer "<<std::to_string(k);
            std::cout<<" to "<<player.getName()<<std::endl;
        }
    }
}
