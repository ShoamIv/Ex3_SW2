/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX3_SW2_CATAN_HPP
#define EX3_SW2_CATAN_HPP
#include "Player.hpp"
#include "Board.hpp"
#include "Deck.hpp"

class Catan{
    Player * p1,*p2,*p3;
    Board * board;
    Deck deck;
    std::vector<int>turn_manage;
    int currentTurnIndex;
    void resource_distribution(int dice);
    void welcome_gift();
public:
    Catan(Player *player1,Player *player2,Player *player3);
    Board* getBoard(){return this->board;}
    void Choose_OrderInteractive();  //choose order of the players.
    void Head_start();    //place two settlements and two roads.
    bool WinnerWinnerChickenDinner();                                //prints winner. stop the game.
    void PlayTurn();
    void end_turn(){currentTurnIndex = (currentTurnIndex + 1) % 3;}
    void game_flow(Player &p); // in interactive game this function will monitor plays.

};
#endif //EX3_SW2_CATAN_HPP
