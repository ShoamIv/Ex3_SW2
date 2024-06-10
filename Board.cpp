//
// Created by shoham on 6/4/24.
//

#include <iostream>
#include "Board.hpp"


Board::Board() {
        Set_board();
        Add_Hexagon();
}
void Board::Set_board() {
    for (int x = -2; x <= 2; x++) {        //x coordinate4
        for (int y = -8; y <= 8; y++) {
            if (x % 2 == 0) {
                if (y % 2 == 0) {
                    if (y % 6 == 0 || y == 0) {
                        continue;
                    }
                    board_vertex.emplace_back(x, y);
                }
            }
            if (x % 2 != 0) {
                    if(y%2!=0) {
                        if (y == 3 || y == -3 || y == 0)continue;
                        else {
                            board_vertex.emplace_back(x, y);
                        }
                    }
            }
        }
    }

    int xN = -3;
    int xP = 3;
    for (int y = -7; y <= 7; y = y + 2) {
        if (y == 3 || y == -3)continue;
        else {
            board_vertex.emplace_back(xN, y);
            board_vertex.emplace_back(xP, y);
        }
    }
    xN = -4;
    xP = 4;
    for (int y = -4; y <= 4; y =y+2) {
        if(y==0)continue;
        else{
            board_vertex.emplace_back(xN, y);
            board_vertex.emplace_back(xP, y);
        }
    }
    xN = -5;
    xP = 5;
    board_vertex.emplace_back(xN, -1);
    board_vertex.emplace_back(xN, 1);
    board_vertex.emplace_back(xP, -1);
    board_vertex.emplace_back(xP, 1);

    Edge::Add(this->board_edges,this->board_vertex);
    Point::set_rep(this->board_vertex);
}

void Board::Add_Hexagon() {
    std::vector<std::vector<Point>> vertex_bank;
    for(auto j : Point::representatives){
        std::vector<Point>hex;
        hex.push_back(j);
        for(auto & t : board_vertex){
            if(Point::Same_Tiles(j,t)){
                hex.push_back(t);
            }
        }
        vertex_bank.emplace_back(hex);
    }

    int i=0;
    board_hexagons.emplace_back(5,Point::Brick,vertex_bank.at(i++));
    board_hexagons.emplace_back(6,Point::Wheat,vertex_bank.at(i++));
    board_hexagons.emplace_back(11,Point::Wool,vertex_bank.at(i++));
    board_hexagons.emplace_back(8,Point::Wood,vertex_bank.at(i++));
    board_hexagons.emplace_back(3,Point::Ore,vertex_bank.at(i++));
    board_hexagons.emplace_back(4,Point::Wheat,vertex_bank.at(i++));
    board_hexagons.emplace_back(5,Point::Wool,vertex_bank.at(i++));
    board_hexagons.emplace_back(9,Point::Wheat,vertex_bank.at(i++));
    board_hexagons.emplace_back(11,Point::Wool,vertex_bank.at(i++));
    board_hexagons.emplace_back(7,Point::Desert,vertex_bank.at(i++));
    board_hexagons.emplace_back(3,Point::Wood,vertex_bank.at(i++));
    board_hexagons.emplace_back(8,Point::Ore,vertex_bank.at(i++));
    board_hexagons.emplace_back(12,Point::Wheat,vertex_bank.at(i++));
    board_hexagons.emplace_back(6,Point::Brick,vertex_bank.at(i++));
    board_hexagons.emplace_back(4,Point::Wool,vertex_bank.at(i++));
    board_hexagons.emplace_back(10,Point::Brick,vertex_bank.at(i++));
    board_hexagons.emplace_back(10,Point::Ore,vertex_bank.at(i++));
    board_hexagons.emplace_back(2,Point::Wool,vertex_bank.at(i++));
    board_hexagons.emplace_back(9,Point::Wood,vertex_bank.at(i++));

}
