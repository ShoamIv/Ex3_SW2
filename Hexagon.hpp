#ifndef EX3_SW2_HEXAGON_HPP
#define EX3_SW2_HEXAGON_HPP
#include "Edge.hpp"
#include <utility>
#include <vector>
#include <string>

class Hexagon {
    int Num_Dice{};
    int Resource{};
    std::vector<Point> vertex;
    bool validRes(int res);

public:
    Hexagon(int dice, int resource, std::vector<Point>& ver);
    Hexagon(Hexagon const &c);
    int getNum_Dice();
    int getRes();
    std::vector<Point> getVertex();
    void setResource(int r) { this->Resource = r; }
    void setDice(int d) { this->Num_Dice = d; }
    void setVertexs(std::vector<Point>& ver);
};

#endif // EX3_SW2_HEXAGON_HPP
