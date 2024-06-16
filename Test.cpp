/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include <sstream>
#include "doctest.h"
#include "Catan.hpp"
#include "Player.hpp"


TEST_CASE("settelment roads and city")
{
Player  player;
player.setName("Test");
Board * board=Board::getBoard();
Point a(-2,-8);
Point b(-1,-7);
Point c(0,-8);
Point d(-0,-6);
Point e(1,-7);
Point f(-1,-7);

player.Place_Settle(&c);
player.Place_Settle(&d);
int t=player.getSettlements().size();
    CHECK(t==2);
    CHECK(player.getSettlements().at(0)->GetOwner()==&player);
    CHECK(player.getSettlements().at(0)->get_Vertex()==&c);
player.Place_Road(d,e,*board);
player.Place_Road(d,f,*board);
    CHECK(t==2);
    CHECK(player.getRoads().at(0)->getEdge().getOwner()=="Test");
    CHECK(player.getRoads().at(1)->getEdge().getPoints().at(1)==&f);
 // Redirect std::cout to capture the output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Attempt to place a settlement
    player.Place_Settle(&a);
    // Restore original std::cout
    std::cout.rdbuf(oldCout);
    // Check that the correct message was printed
    CHECK(buffer.str() == "You do not have enough resources.\n");
    player.Place_Road(a,b,*board);
    CHECK(buffer.str() == "You do not have enough resources.\n");

    //get player enough resource overall.
    for(int i=0; i<5; i++){
    player.gainResource(i,10);
    }
    player.Place_Settle(&a);
    CHECK(player.getSettlements().at(2)->get_Vertex()==&a);
    CHECK(player.get_Winning_p()==3);
    player.Place_City(player.getSettlements().at(2));
    CHECK(player.getCities().size()==1);
}


TEST_CASE("Players trade")
{
Player  player1,player2;
Knight a;
Monopoly b;
player1.setName("Test1");
player1.setName("Test2");
for(int i=0; i<5; i++){
    player1.gainResource(i,10); 
    player2.gainResource(i,10); 
    }
    player1.Trade(player2,"Wood","Brick",5,5);
    CHECK(player1.get_Resource().at(0)==5);
    CHECK(player1.get_Resource().at(1)==15);

    CHECK(player2.get_Resource().at(0)==15);
    CHECK(player2.get_Resource().at(1)==5);

    player1.set_Cards(&a);
    player2.set_Cards(&b);
    player1.Trade(player2,"Knight","Monopoly",1,1);
    
    CHECK(player1.getCards().at(0)->Get_Card_name()=="Monopoly");
    CHECK(player2.getCards().at(0)->Get_Card_name()=="Knight");

    player1.Trade(player2,"Monopoly","Ore",1,4);
    CHECK(player1.get_Resource().at(4)==14);
    CHECK(player2.get_Resource().at(4)==6);
    CHECK(player2.getCards().at(1)->Get_Card_name()=="Monopoly");
}
TEST_CASE("Board"){

Board * board=Board::getBoard();

    CHECK(board->getHexagon().size()==19);
    CHECK(board->getEdge().size()==72);

}
TEST_CASE("Cards action"){
Board * board=Board::getBoard();
Player player1,player2;
for(int i=0; i<5; i++){
    player2.gainResource(i,10); 
    }
Knight a1,a2,a3;
Monopoly b;
Year_Of_Plenty c;
VictoryPoint d;
Road_building e;
player1.setName("Test1");
player1.set_Cards(&a1);
player1.set_Cards(&a2);
player1.set_Cards(&a3);
player1.set_Cards(&b);
player1.set_Cards(&c);
player1.set_Cards(&d);
player1.set_Cards(&e);

player1.getCards().at(0)->action(player1,*board);
player1.getCards().at(1)->action(player1,*board);
player1.getCards().at(2)->action(player1,*board);
CHECK(player1.get_Winning_p()==2);

player1.getCards().at(3)->action(player1,*board);

int k=player1.get_Resource().at(0);
player1.getCards().at(4)->action(player1,*board);
CHECK(player1.get_Resource().at(0)==k+1);

player1.getCards().at(5)->action(player1,*board);
CHECK(player1.get_Winning_p()==1);

player1.getCards().at(6)->action(player1,*board);
CHECK(player1.get_road_token()==4);


}
