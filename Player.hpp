

#ifndef EX3_SW2_PLAYER_HPP
#define EX3_SW2_PLAYER_HPP
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include "Road.hpp"
#include "City.hpp"
#include "DevCard.hpp"
#include "Deck.hpp"
class Player {

    std::string name;
    std::vector<int>resource={0,0,0,0,0};  //      Wood,Brick,Wool,Wheat,Ore
    int Winning_p{};
    static std::vector<Player*>players;
    std::vector<Road*> Roads;
    std::vector<Settlement*> Settlements;
    std::vector<City*> Cities;
    std::vector<DevCard*> Cards;
    int road_token;
public:
    //constructor
    explicit Player();
    //getters and setters.
    std::string getName();
    int get_Winning_p() const;
    std::vector<int> get_Resource(){return this->resource;}
    int get_road_token(){return this->road_token;}
    std::vector<DevCard*> getCards(){return this->Cards;}
    std::vector<Road*> getRoads(){return this->Roads;}
    std::vector<Settlement*> getSettlements(){return this->Settlements;}
    std::vector<City*> getCities(){return this->Cities;}
    static std::vector<Player*> getPlayers(){return players;}

    void set_road_token(){this->road_token+=2;}
    void setName(std::string name1);
    void set_Winning_p(int increment);
    void set_Cards(DevCard* card){this->Cards.emplace_back(card);}
    static void set_Players(Player * player){players.emplace_back(player);}

    /*
     * Game Actions:
     */
    bool Check_Res(const std::string& complex);
    void Place_Settle(int hexagon,int vertex,Board& board);
    void Place_Settle(Point *v);
    void Place_City(Settlement *settle);
    void Place_Road(Point &p1,  Point &p2, Board& board);
    void Place_Road(Edge &e,Board& board);
    void placeRoadInteractive(Board &board);
    void placeSettleInteractive(Board &board);


    void Buy_Card();
    void gainResource(int res,int increase);
    void playCard(const std::string& card ,Board &board);
    int roll();


    /*
     * trade actions
     */
    void offer(Player &p,const std::string& product1,const std::string& product2,int amount1,int amount2);
    void Trade(Player &p,const std::string& product1, [[maybe_unused]] const std::string& product2,int amount1,int amount2);
    bool ensure_card_amount(const std::string& card_name,int amount);
};


#endif //EX3_SW2_PLAYER_HPP
