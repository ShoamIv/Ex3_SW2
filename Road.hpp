/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_ROAD_HPP
#define EX3_SW2_ROAD_HPP
#include "Board.hpp"

/*
 * required resources: 1 of each: Brick,Wood
 */


class Road {
    Edge edge;
    std::string owner_id;

public:
    Road(const Point& p1,const Point& p2,const std::string& id,Board& board);
    Road(const Edge & e,const std::string& id,Board& board);

    Edge getEdge();
    bool ValidRoad();

};

#endif //EX3_SW2_ROAD_HPP
