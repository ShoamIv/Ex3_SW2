
#include "Settlement.hpp"
#include <utility>



Settlement::Settlement(const Player &p1, const Point& v, const Hexagon& hexagon) : hexagon(hexagon) {
    if(ValidBuilding(const_cast<Point &>(v))) {
        this->p = p1;
        this->vertex=v;
        this->hexagon = hexagon;
        this->resource= this->hexagon.getRes();
    }
}

Player Settlement::GetOwner() {
    return this->p;
}

Hexagon Settlement::getHex() {
    return this->hexagon;
}

bool Settlement::ValidBuilding(Point& a) {
    bool flag=false;
    for(int i=0; i<a.getNeighbors().size(); i++){
        if(a.getNeighbors().at(i).getOwner()!=" "){flag=false;break;}

            if(a.getNeighbors_Edge().size(); i++){
                if(a.getNeighbors_Edge().at(i)->getOwner()==a.getOwner()){
                    flag=true;
                }
            }
        }
    return flag;
}

