/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "Year_Of_Plenty.hpp"
#include "Player.hpp"

Year_Of_Plenty::Year_Of_Plenty()
        : DevCard(CardType::YEAR_OF_PLENTY, "Year of Plenty") {}

void Year_Of_Plenty::action(Player &player, Board & board) {
   // std::cout<<"Please enter two desired resource:"<<std::endl;
    int res1;int res2;
    res1=0;res2=1;
   // std::cin>>res1;
    //std::cin>>res2;
    player.gainResource(res1,1);player.gainResource(res2,1);

}
