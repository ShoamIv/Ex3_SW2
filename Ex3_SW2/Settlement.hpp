/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#ifndef EX3_SW2_SETTLEMENT_HPP
#define EX3_SW2_SETTLEMENT_HPP
#include "Board.hpp"


/*
 * required resources: 1 of each: Brick,Wool,Wood,Wheat
 */
class Player;
class Settlement{
protected:
    Point* vertex{};
    Player * owner{};

public:
    Settlement()=default;
    Settlement(Player *p, Point* v);
    virtual ~Settlement();
    Player* GetOwner();
    Point* get_Vertex();

    static bool ValidBuilding(Point* a);

};


#endif //EX3_SW2_SETTLEMENT_HPP
