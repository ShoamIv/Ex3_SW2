/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Edge.hpp"


Edge::Edge(Point * point1, Point * point2) {
    this->v1=point1;
    this->v2=point2;
    owner=" ";
}

void Edge::Contain(std::vector<Edge> &edges, Point& a, Point& b) {
    for(auto & edge : edges){
        if(*edge.v1==a && *edge.v2==b){return;}
        if(*edge.v2==a && *edge.v1==b){return;}
    }
    Edge e(&a,&b);
    edges.emplace_back(e);
}

std::vector<Point*> Edge::getPoints() {
    std::vector<Point*> points;
    points.emplace_back(v1);
    points.emplace_back(v2);
    return points;
}

void Edge::Add(std::vector<Edge> &edges,std::vector<Point> &points) {

    for(int i=0; i<points.size(); i++){
       for(int j=0; j<points.size(); j++) {
           if(i==j)continue;
           if ((points.at(i).getY() == points.at(j).getY() + 2) ||
               (points.at(i).getY() == points.at(j).getY() - 2)) {
               if (points.at(i).getX() == points.at(j).getX()) {
                   points.at(i).setNeighbors(points.at(j));
                   Edge::Contain(edges, points.at(i), points.at(j)); //check if contain. if not added to the vector.
               }
           }

           if (points.at(i).getY() == points.at(j).getY() + 1 ||
               points.at(i).getY() == points.at(j).getY() - 1) {
               if ((points.at(i).getX() == points.at(j).getX() + 1) ||
                   (points.at(i).getX() == points.at(j).getX() - 1)) {
                   points.at(i).setNeighbors(points.at(j));
                   Edge::Contain(edges, points.at(i),
                                 points.at(j)); //check if contain. if not added to the vector..
               }
           }
       }
    }
    for(int i=0; i<edges.size(); i++){
        edges.at(i).set_neighbors(edges);
    }
}

void Edge::set_neighbors(std::vector<Edge> &edges) {
    for(auto & edge : edges){
        if(this->v1==edge.v1 && this->v2==edge.v2)continue;


        if(this->v1==edge.v1){
            this->neighbors_edge.emplace_back(edge);
            this->v1->setNeighbors_Edge(&edge);
        }
        if(this->v1==edge.v2){
            this->neighbors_edge.emplace_back(edge);
            this->v1->setNeighbors_Edge(&edge);
        }
        if(this->v2==edge.v1){
            this->neighbors_edge.emplace_back(edge);
            this->v2->setNeighbors_Edge(&edge);
        }
        if(this->v2==edge.v2){
            this->neighbors_edge.emplace_back(edge);
            this->v2->setNeighbors_Edge(&edge);
        }

    }
}









