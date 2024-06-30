/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Catan.hpp"
int main() {


    auto *p1=new Player();
    auto *p2=new Player();
    auto *p3=new Player();
    p1->setName("Shauli");
    p2->setName("Amatzia");
    p3->setName("Avi");

    Board * board=Board::getBoard();


    /*
     * Initiate Catan.
     */
    
    Catan catan(p1,p2,p3);
    catan.Head_start();

    //Shauli turn.
    catan.PlayTurn();
    catan.end_turn();

    //Amatzia turn.
    catan.PlayTurn();
    p2->Place_Settle(4,3,*catan.getBoard());
    catan.end_turn();

    //Avi turn.
    catan.PlayTurn();
    p3->Trade(*p1,"Wood","Brick",1,1);
    catan.end_turn();

    //Shauli turn
    catan.PlayTurn();
    p1->Buy_Card();
    catan.end_turn();

    //Amatzia turn.
    catan.PlayTurn();
    p2->offer(*p3,"Wood","Wheat",2,1);
    p2->Buy_Card();
    catan.end_turn();

    //Avi turn.
    catan.PlayTurn();
    catan.end_turn();

    //Shauli turn
    catan.PlayTurn();

    if(!p1->getCards().empty()) {
        p1->playCard(p1->getCards().at(0)->Get_Card_name(), *catan.getBoard());
    }
    catan.end_turn();

    //Amatzia turn.
    catan.PlayTurn();
    if(!p2->getCards().empty()) {
        p2->playCard(p2->getCards().at(0)->Get_Card_name(), *catan.getBoard());
    }
    catan.end_turn();
    catan.game_over();
    
    p1->clean_up();
    p2->clean_up();
    p3->clean_up();

    delete(p1);
    delete(p2);
    delete(p3);
      

}
