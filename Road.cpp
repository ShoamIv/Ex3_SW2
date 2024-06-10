
#include "Road.hpp"

#include <utility>

Road::Road(Edge t,std::string id) {
    this->edge=std::move(t);
    this->owner_id=std::move(id);
}

std::string Road::getOwner() {
    return this->owner_id;
}

Edge Road::getEdge() {
    return this->edge;
}

bool Road::ValidRoad() {

    if(this->getEdge().getOwner()!=" ")return false;
    Point a=this->getEdge().getPoints().at(0);
    Point b=this->getEdge().getPoints().at(1);

    if(a.getOwner()==this->getEdge().getOwner()) return true;

    if(b.getOwner()==this->getEdge().getOwner()) return true;

        for(int j=0; j<this->getEdge().get_neighbors_edge().size(); j++){
            if(a.getNeighbors().at(j)==b)continue;
            if(this->getEdge().get_neighbors_edge().at(j).getOwner()==this->getEdge().getOwner()){
                return true;
            }
        }
    return false;
}
