/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Point.hpp"
std::vector<Point> Point::representatives;
        // Default constructor
        Point::Point() {
            this->x=0;this->y=0;this->owner="";
        }
        // Parameterized constructor
        Point::Point(int X, int Y)  {
            this->x=X;this->y=Y;
        }
// Copy constructor
        Point::Point(const Point &other) {
            *this=other;
        }

        bool Point::operator==(const Point &other) const{
        return this->x == other.x && this->y == other.y;
        }

        bool Point::operator!=(const Point &other) const {
        return *this==other;
        }

        Point &Point::operator=(const Point &other) {
            this->x = other.x;
            this->y = other.y;
            return *this; // Return *this to allow chained assignments
        }

        std::vector<Point> Point::getNeighbors() {
            return this->neighbors;
        }

        void Point::setNeighbors(const Point& a) {
          this->neighbors.emplace_back(a);
        }

        void Point::setNeighbors_Edge(Edge *a) {
            this->neighbors_Edges.emplace_back(a);
        }

        std::vector<Edge*> Point::getNeighbors_Edge() {
         return this->neighbors_Edges;
        }

        bool Point::Same_Tiles(Point &v, Point &u) {
        if(v.getX()==u.getX()){
         if(v.getY()+4==u.getY()){
            return true;
        }
    }
      if(v.getX()== u.getX()+1){
        if((v.getY()+1==u.getY()) ||v.getY()+3==u.getY()) {
            return true;
        }
    }

     if(v.getX()== u.getX()-1){
        if((v.getY()+1==u.getY()) ||v.getY()+3==u.getY()) {
            return true;
        }
    }

    return false;
}

        void Point::set_rep(std::vector<Point> &vertex) {
        for(auto & i : vertex){
        int x=i.getX();
        int y=i.getY();

        if(y==-8 || y==4){
            if(abs(x)==2 || x==0){
                Point::representatives.emplace_back(i);
                continue;
            }
        }
        if(y==-5 || y==1){
            if(abs(x)==1 || abs(x)==3){
                Point::representatives.emplace_back(i);
                continue;
            }
        }
        if(y==-2){
            if(x%2==0){
                Point::representatives.emplace_back(i);
                continue;
            }
        }
    }
        std::sort(representatives.begin(), representatives.end(), [](const Point& a, const Point& b) {
                if (a.y != b.y)
                    return a.y < b.y; // Sort by y coordinate
                return a.x < b.x; // If y is the same, sort by x coordinate
            });
}

        void Point::set_res(int res) {
            this->resource.at(res)++;
        }

void Point::print_p() const {
    std::cout<<std::to_string(this->getX())
             <<","<<std::to_string(this->getY());
}



