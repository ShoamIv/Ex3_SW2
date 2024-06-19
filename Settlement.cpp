/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Settlement.hpp"


Settlement::Settlement( Player *p, Point* v) {
    this->owner=p;
    this->vertex=v;
    this->vertex->set_building_type("Settle");
}


Player* Settlement::GetOwner() {
    return this->owner;
}

Point * Settlement::get_Vertex() {
    return this->vertex;
}

bool Settlement::ValidBuilding(Point* a) {
    
    if(!a->getOwner().empty())return false;
    bool flag=false;
    for(int i=0; i<a->getNeighbors().size(); i++){
        if(!a->getNeighbors().at(i).getOwner().empty()){
            flag=false;
            break;
             }
            if(a->getNeighbors_Edge().at(i)->getOwner()==a->getOwner()){
                    flag=true;
                }
        }
    return flag;
}
Settlement::~Settlement() = default;









