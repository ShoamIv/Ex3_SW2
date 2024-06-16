/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_HEXAGON_HPP
#define EX3_SW2_HEXAGON_HPP
#include "Edge.hpp"


class Hexagon {
    int Num_Dice{};
    int Resource{};
    std::vector<Point*> vertex;
    bool validRes(int res);

public:
    Hexagon(int dice, int resource, std::vector<Point*>& ver);
    Hexagon(Hexagon const &c);
    [[nodiscard]] int getNum_Dice() const;
    [[nodiscard]] int getRes() const;
    std::vector<Point*> getVertex();
    void setVertexs(std::vector<Point*>& ver);
    std::vector<std::string> Print_Hexagon() const;
};

#endif // EX3_SW2_HEXAGON_HPP
