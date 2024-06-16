/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "Knight.hpp"
#include "Player.hpp"


Knight::Knight()
        : DevCard(CardType::KNIGHT, "Knight") {}


void Knight::action(Player &player, Board &board) const{
    int c=0;
    for(int i=0; i<player.getCards().size(); i++){
        if(player.getCards().at(i)->Get_type()== this->Get_type())c++;
    }
    if(c>2) player.set_Winning_p(2);
}

void Knight::Check_Knight(Player & p) {
    int count=0;
    for(int i=0; i<p.getCards().size(); i++){
        if(p.getCards().at(i)->Get_Card_name()== "Knight") count++;
    }
    if(count<3) p.set_Winning_p(-2);
}

