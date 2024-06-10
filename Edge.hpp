

#ifndef EX3_SW2_EDGE_HPP
#define EX3_SW2_EDGE_HPP


#include "Point.hpp"


class Edge {
     Point v1;
     Point v2;
     std::vector<Edge>neighbors_edge;
     std::string owner;
public:
    Edge()= default;
    Edge(Point &point1, Point &point2);
    [[nodiscard]] std::string getOwner() const{return this->owner;}
    [[nodiscard]] std::vector<Edge> get_neighbors_edge() const{return this->neighbors_edge;}
    std::vector<Point> getPoints();
    static void Contain(std::vector<Edge> &edges,Point& a,Point& b);
    static void Add(std::vector<Edge> &edges,std::vector<Point> &points);
    void set_neighbors(std::vector<Edge> &edges);
};


#endif
