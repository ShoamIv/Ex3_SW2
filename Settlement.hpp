

#ifndef EX3_SW2_SETTLEMENT_HPP
#define EX3_SW2_SETTLEMENT_HPP
#include "Hexagon.hpp"
#include "Player.hpp"
/*
 * required resources: 1 of each: Brick,Wool,Wood,Wheat
 */
class Settlement{
    Player p;
    Hexagon hexagon;
    Point vertex;
    int resource;

public:
    Settlement(const Player &p1, const Point& v, const Hexagon &hexagon);
    Player GetOwner();
    Hexagon getHex();
    static bool ValidBuilding(Point& a);



};

#endif //EX3_SW2_SETTLEMENT_HPP
