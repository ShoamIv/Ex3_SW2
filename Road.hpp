
#ifndef EX3_SW2_ROAD_HPP
#define EX3_SW2_ROAD_HPP
#include "Edge.hpp"
/*
 * required resources: 1 of each: Brick,Wood
 */
class Road {
    Edge edge;
    std::string owner_id;

public:
    Road(Edge t,std::string id);
    std::string getOwner();
    Edge getEdge();
    bool ValidRoad();
};

#endif //EX3_SW2_ROAD_HPP
