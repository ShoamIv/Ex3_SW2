
#ifndef EX3_SW2_BOARD_HPP
#define EX3_SW2_BOARD_HPP
#include "Hexagon.hpp"
class Board {
    std::vector<Hexagon> board_hexagons;
    std::vector<Point> board_vertex;
    std::vector<Edge> board_edges;
    void Set_board();
    void Add_Hexagon();
public:
    Board();
};
#endif //EX3_SW2_BOARD_HPP
