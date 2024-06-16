/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Road.hpp"


Road::Road(const Point& p1,const Point& p2, const std::string& id, Board& board) {
    bool flag=false;
    flag=ValidRoad();
    for(int i=0; i<board.getEdge().size(); i++){
        if(*board.getEdge().at(i).getPoints().at(0)==p1 && *board.getEdge().at(i).getPoints().at(1)==p2){
            this->edge=board.getEdge().at(i);
            this->owner_id=id;
            flag=true;break;
        }
        if(*board.getEdge().at(i).getPoints().at(1)==p1 && *board.getEdge().at(i).getPoints().at(0)==p2){
            this->edge=board.getEdge().at(i);
            this->owner_id=id;
            flag=true;break;
        }
    }
    if(!flag){
        throw std::invalid_argument("You entered invalid Points for the Road.");

    }
}

Road::Road(Edge &e, const std::string &id, Board &board) {
    if(!ValidRoad()){
        throw std::invalid_argument("You entered invalid Points for the Road.");

    }
            this->edge=e;
            this->owner_id=id;
}

Edge Road::getEdge() {
    return this->edge;
}

bool Road::ValidRoad() {
    if(this->getEdge().getOwner()!=" ")return false;
    Point * a=this->getEdge().getPoints().at(0);
    Point * b=this->getEdge().getPoints().at(1);

    if(a->getOwner()==this->getEdge().getOwner()) return true;

    if(b->getOwner()==this->getEdge().getOwner()) return true;
        bool flag=false;
        for(int i=0; i<a->getNeighbors().size(); i++){
            if(&a->getNeighbors().at(i)==b){
               flag=true; break;
            }
        }
        if(flag){
        for(int j=0; j<this->getEdge().get_neighbors_edge().size(); j++){
            if(&a->getNeighbors().at(j)==b)continue;
            if(this->getEdge().get_neighbors_edge().at(j).getOwner()==this->getEdge().getOwner()) {
                return true;
                }
            }
        }
    return false;
}


