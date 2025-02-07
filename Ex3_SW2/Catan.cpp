/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_GAMELOGIC_H
#define EX3_SW2_GAMELOGIC_H

#include <iostream>
#include "Catan.hpp"

Catan::Catan( Player *player1,Player *player2,Player *player3) {
    Board * board1=Board::getBoard();
    Deck *cards=Deck::getdeck();
    this->p1=player1;this->p2=player2;this->p3=player3;
    this->board= board1;
    this->deck=cards;
    Player::set_Players(player1);
    Player::set_Players(player2);
    Player::set_Players(player3);
    currentTurnIndex = 0;

 /*
Interactive mode:
void Catan::Choose_OrderInteractive() {
    std::vector<std::pair<int, Player *>> rolls = {
            {p1.roll(), &p1},
            {p2.roll(), &p2},
            {p3.roll(), &p3}
    };
    std::sort(rolls.begin(), rolls.end(), [](const std::pair<int, Player *> &a, const std::pair<int, Player *> &b) {
        return a.first > b.first;
    });
    for (int i = 0; i < rolls.size(); ++i) {
        rolls[i].second->setTurn(i % 3); // Turn is the index modulo 3

    }
    std::cout << "Order of players from highest to lowest roll:" << std::endl;
    for (const auto& roll : rolls) {
        std::cout << roll.second->getName() << " with roll " << roll.first
                  << " has turn " << roll.second->getTurn() << std::endl;
    }
}
*/

}

void Catan::Head_start() {

    this->p1->Place_Settle(3,2,*board);
    this->p1->Place_Settle(1,4,*board);

    this->p2->Place_Settle(7,3,*board);
    this->p2->Place_Settle(4,2,*board);

    this->p3->Place_Settle(17,1,*board);
    this->p3->Place_Settle(15,1,*board);
    

    this->p1->Place_Road(*board->getHexagon().at(0).getVertex().at(1),*board->getHexagon().at(0).getVertex().at(3),*board);
    this->p1->Place_Road(*board->getHexagon().at(0).getVertex().at(1),*board->getHexagon().at(1).getVertex().at(0),*board);
   
    this->p2->Place_Road(*board->getHexagon().at(3).getVertex().at(3),*board->getHexagon().at(0).getVertex().at(2),*board);
    this->p2->Place_Road(*board->getHexagon().at(4).getVertex().at(2),*board->getHexagon().at(4).getVertex().at(0),*board);

    this->p3->Place_Road(*board->getHexagon().at(9).getVertex().at(1),*board->getHexagon().at(9).getVertex().at(0),*board);
    this->p3->Place_Road(*board->getHexagon().at(9).getVertex().at(1),*board->getHexagon().at(9).getVertex().at(3),*board);
    
    Catan::welcome_gift();

    /*
    Interactive mode:
    std::cout << this->p1.getName();
    std::cout << " Please enter two settlements and two roads: " << std::endl;
    this->p1.placeSettleInteractive(board);
    this->p1.placeSettleInteractive(board);
    this->p1.placeRoadInteractive(board);
    this->p1.placeRoadInteractive(board);

    std::cout << this->p2.getName();
    std::cout << " Please enter two settlements and two roads: " << std::endl;
    this->p2.placeSettleInteractive(board);
    this->p2.placeSettleInteractive(board);
    this->p2.placeRoadInteractive(board);
    this->p2.placeRoadInteractive(board);

    std::cout << this->p3.getName();
    std::cout << " Please enter two settlements and two roads: " << std::endl;
    this->p3.placeSettleInteractive(board);
    this->p3.placeSettleInteractive(board);
    this->p3.placeRoadInteractive(board);
    this->p3.placeRoadInteractive(board);
    */
}

bool Catan::WinnerWinnerChickenDinner() {
    if(this->p1->get_Winning_p()>=10){
        std::cout<<this->p1->getName()<<" is the Winner!";
        return true;
    }
    if(this->p2->get_Winning_p()>=10){
        std::cout<<this->p2->getName()<<" is the Winner!";
        return true;
    }
    if(this->p3->get_Winning_p()>=10){
        std::cout<<this->p3->getName()<<" is the Winner!";
        return true;
    }
        return false;
}

bool Catan::PlayTurn() {
    if(WinnerWinnerChickenDinner()){
        game_over();
        return false;
    }
    Player * currentPlayer = Player::getPlayers().at(currentTurnIndex);
    std::cout<< currentPlayer->getName() << " turn\n";

    int diceRoll = currentPlayer->roll();
    std::cout << currentPlayer->getName() << " rolls a " << diceRoll << "\n";
    if(diceRoll==7) Seven_penalty();
    else
    this->resource_distribution(diceRoll);
    return true;
}

void Catan::resource_distribution(int dice) {
    for(int i=0; i<19; i++){
        if(board->getHexagon().at(i).getNum_Dice()==dice){
            Player * p;
            for(int j=0; j<6; j++){
               if(!board->getHexagon().at(i).getVertex().at(j)->getOwner().empty()){

                       if(board->getHexagon().at(i).getVertex().at(j)->getOwner()==this->p1->getName()){
                           p=this->p1;
                       }
                       else if(board->getHexagon().at(i).getVertex().at(j)->getOwner()==this->p2->getName()){
                           p=this->p2;
                       }
                       else   p=this->p3;

                       if(board->getHexagon().at(i).getVertex().at(j)->get_building_type()=="Settle") {
                           p->gainResource(board->getHexagon().at(i).getRes(), 1);
                       }

                       else {
                           this->p1->gainResource(board->getHexagon().at(i).getRes(), 2);
                   }
               }
            }
        }
    }
}

void Catan::welcome_gift() {

    for(int i=0; i<19; i++){
        for(int j=0; j<6; j++){
            Player *p;
        if(!board->getHexagon().at(i).getVertex().at(j)->getOwner().empty()){

            if(board->getHexagon().at(i).getVertex().at(j)->getOwner()==this->p1->getName()){
                p=this->p1;
            }
             if(board->getHexagon().at(i).getVertex().at(j)->getOwner()==this->p2->getName()){
                p=this->p2;
            }
            if(board->getHexagon().at(i).getVertex().at(j)->getOwner()==this->p3->getName()) {
                p = this->p3;
            }
            p->gainResource(board->getHexagon().at(i).getRes(), 1);
            }
        }
    }
}

void Catan::Seven_penalty()
{
    
        if(p1->total_res()>=7){
            payment(this->p1);
        }

         if(p2->total_res()>=7){
            payment(this->p2);
        }
        if(p3->total_res()>=7){
             payment(this->p3);
        }         
}

void Catan::payment(Player *player)
{
         std::cout<<"hello "<<player->getName()<<std::endl;
            player->display_res();
            int gap=player->total_res()/2;
            std::cout<<"Please choose enough resources to decrease.\n";
            std::cout<<"Notice you need to deacrese: "<<gap<<" resources\n";
            std::cout<<"choose the resource and amount you with to decrease.\n";
            int a;int b=0; std::cin>>a>>b;
            while(b!=gap){
                 player->display_res();
                while(player->get_Resource().at(a)-b<0){
                 std::cout<<"Not enough resource.\n";
                 player->display_res();
                std::cout<<"choose the resource and amount you with to decrease.\n";
                 std::cin>>a>>b;
                }
            gap=gap-b;
             player->set_res(a,-b);
             std::cout<<"Please decrease more resource to reach the gap.\n";
             std::cout<<"gap left: "<<gap;
             std::cout<<"choose the resource and amount you with to decrease.\n";
             std::cin>>a>>b;
             }
            std::cout<<"Thank you for your cooperation.\n";
}

void Catan::game_over()
{
        deck->clean_up();
        delete(board);
}

#endif //EX3_SW2_GAMELOGIC_H

