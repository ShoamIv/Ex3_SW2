/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_BOARD_HPP
#define EX3_SW2_BOARD_HPP
#include "Hexagon.hpp"

class Board {
    static Board * pt;
    Board();
    std::vector<Hexagon> board_hexagons;
    std::vector<Point> board_vertex;
    std::vector<Edge> board_edges;
    void Set_board();
    void Add_Hexagon();

public:
    static Board * getBoard();
    std::vector<Hexagon> getHexagon();
    std::vector<Edge> getEdge();

};
#endif //EX3_SW2_BOARD_HPP
