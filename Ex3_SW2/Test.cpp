/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include <sstream>
#include "doctest.h"
#include "Catan.hpp"
#include "Player.hpp"
#include <unordered_set>
#include <unordered_map>


TEST_CASE("settelment roads and city")
{
Player   player;

player.setName("Test");
Board * board=Board::getBoard();
Point * a=board->getHexagon().at(0).getVertex().at(5);
Point * b=board->getHexagon().at(0).getVertex().at(3);
Point * c=board->getHexagon().at(1).getVertex().at(5);
Point * d=board->getHexagon().at(1).getVertex().at(4);
Point * e=board->getHexagon().at(1).getVertex().at(3);

player.Place_Settle(0,5,*board);
player.Place_Settle(1,5,*board);

int t=player.getSettlements().size();
    CHECK(t==2);
    CHECK(player.getSettlements().at(0)->GetOwner()==&player);
    CHECK(player.getSettlements().at(0)->get_Vertex()->getX()==a->getX());
    CHECK(player.getSettlements().at(0)->get_Vertex()->getY()==a->getY());
    player.Place_Road(*board->getHexagon().at(0).getVertex().at(1),*board->getHexagon().at(0).getVertex().at(3),*board);
    player.Place_Road(*board->getHexagon().at(0).getVertex().at(1),*board->getHexagon().at(1).getVertex().at(0),*board);
    CHECK(t==2);
    CHECK(player.getRoads().at(0)->getEdge().getOwner()=="Test");
    CHECK(board->getHexagon().at(0).getVertex().at(5)->get_building_type()=="Settle");
 
 // Redirect std::cout to capture the output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Attempt to place a settlement
    player.Place_Settle(a);
    // Restore original std::cout
    std::cout.rdbuf(oldCout);
    // Check that the correct message was printed
    
    CHECK(buffer.str() == "You do not have enough resources.\n");
    player.Place_Road(*a,*b,*board);
    CHECK(buffer.str() == "You do not have enough resources.\n");

    //get player enough resource overall.
    for(int i=0; i<5; i++){
    player.gainResource(i,10);
    }

    CHECK(player.get_Winning_p()==2);

    player.Place_City(player.getSettlements().at(1));
      
    CHECK(player.getCities().size()==1);


    player.clean_up();

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

    CHECK(player1.get_Resource().at(4)==10);
    CHECK(player2.get_Resource().at(4)==10);

    player1.Trade(player2,"Monopoly","Ore",1,4);

    CHECK(player1.get_Resource().at(4)==14);
    CHECK(player2.get_Resource().at(4)==6);

    CHECK(player2.getCards().at(1)->Get_Card_name()=="Monopoly");

   
}

TEST_CASE("Board"){

    Board * board=Board::getBoard();

    CHECK(board->getHexagon().size()==19);
    CHECK(board->getEdge().size()==72);

     for (const auto& edge : board->getEdge()) {
        CHECK(edge.getPoints().size() == 2);
    }
      std::unordered_map<int, int> hexCount;
    for (const auto& hex : board->getHexagon()) {
        hexCount[hex.getRes()]++;
    }
    CHECK(hexCount[Point::Brick] == 3);
    CHECK(hexCount[Point::Wheat] == 4);
    CHECK(hexCount[Point::Wool] == 5);
    CHECK(hexCount[Point::Wood] == 3);
    CHECK(hexCount[Point::Ore] == 3);
    CHECK(hexCount[Point::Desert] == 1);
    delete(board);
  
}

TEST_CASE("Cards action"){
Board * board=Board::getBoard();
Player player1,player2,player3;
CHECK(player1.get_Winning_p()==0);
for(int i=0; i<5; i++){
    player2.gainResource(i,10); 
 }
Knight a1,a2,a3;
Monopoly b;
Year_Of_Plenty c;
VictoryPoint d;
Road_building e;

player1.setName("Test1");
player2.setName("Test2");
player3.setName("Test3");
Player::set_Players(&player1);
Player::set_Players(&player2); ///at run game occur at Catan constructor.
Player::set_Players(&player3);
player1.set_Cards(&a1);
player1.set_Cards(&a2);
player1.set_Cards(&a3);
player1.set_Cards(&b);
player1.set_Cards(&c);
player1.set_Cards(&d);
player1.set_Cards(&e);

player1.getCards().at(0)->action(player1,*board);
CHECK(player1.get_Winning_p()==2);

//remain two winning points.

player1.getCards().at(1)->action(player1,*board);
player1.getCards().at(2)->action(player1,*board);
CHECK(player1.get_Winning_p()==2);

//player1.getCards().at(3)->action(player1,*board);

int k=player1.get_Resource().at(0);
player1.getCards().at(4)->action(player1,*board);
CHECK(player1.get_Resource().at(0)==k+1);

player1.getCards().at(5)->action(player1,*board);
CHECK(player1.get_Winning_p()==3);
player1.getCards().at(6)->action(player1,*board);

CHECK(player1.get_road_token()==4);  //initiail two from constructor of player.

}


