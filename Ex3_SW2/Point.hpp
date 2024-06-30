/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_POINT_HPP
#define EX3_SW2_POINT_HPP
#include <string>
#include <utility>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Edge;

class Point{
private:
    int x{};
    int y{};
    std::string owner;
    std::string building;
    std::vector<Point>neighbors;
    std::vector<Edge *>neighbors_Edges;
    std::vector<int> resource = {0, 0, 0, 0, 0, 0};


public:
    //getters
    [[nodiscard]] int getX() const{return this->x;}
    [[nodiscard]] int getY() const{return this->y;}
    [[nodiscard]] std::string getOwner() const{return this->owner;}
    [[nodiscard]] std::vector<int> get_res(){return this->resource;}
    [[nodiscard]] std::string get_building_type(){return this->building;}
    //setters
    void setOwner(std::string own){this->owner=std::move(own);}
    void set_res(int res);
    void set_building_type(const std::string& type){this->building=type;}

    //get,set neighbors.
    std::vector<Point> getNeighbors();
    std::vector<Edge*> getNeighbors_Edge();
    void setNeighbors(const Point& a);
    void setNeighbors_Edge(Edge *a);


    //3 constructors.
    Point();
    Point(int x,int y);
    Point(const Point& other);

    //useful operations on points.
    Point& operator=(const Point& other);
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    void print_p() const;

    //hexagon helper functions.
    static std::vector<Point>representatives;
    static bool Same_Tiles( Point& v, Point& u);
    static void set_rep(std::vector<Point>& vertex);


    //enum.
    enum ResourceType {
        Wood,
        Brick,
        Wool,
        Wheat,
        Ore,
        Desert,
    };
    // Destructor
    ~Point() {
   }
};
#endif //EX3_SW2_POINT_HPP
