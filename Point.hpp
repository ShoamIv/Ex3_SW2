
#ifndef EX3_SW2_POINT_HPP
#define EX3_SW2_POINT_HPP
#include <string>
#include <vector>
#include <stdexcept>
class Edge;

class Point{
private:
    int x{};
    int y{};
    std::string owner;
    std::vector<Point>neighbors;
    std::vector<Edge *>neighbors_Edges;
public:
    //get,set x,y cord. owner.
    [[nodiscard]] int getX() const{return this->x;}
    [[nodiscard]] int getY() const{return this->y;}
    [[nodiscard]] std::string getOwner() const{return this->owner;}
    void setX(int x1) {this->x=x1;}   //inline
    void setY(int y1) {this->y=y1;}
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
