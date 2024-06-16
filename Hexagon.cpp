/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#include "Hexagon.hpp"

Hexagon::Hexagon(int dice, int resource, std::vector<Point*>& ver) {
    if (dice < 2 || dice > 12) {
        throw std::invalid_argument("invalid dice.");
    }
    if (!validRes(resource)) {
        throw std::invalid_argument("invalid resource.");
    }
    this->Num_Dice = dice;
    this->Resource = resource;
    setVertexs(ver);
}

Hexagon::Hexagon(const Hexagon &c) {
    this->Num_Dice=c.Num_Dice;
    this->Resource=c.Resource;
    this->vertex=c.vertex;
}

int Hexagon::getNum_Dice() const {
    return this->Num_Dice;
}

int Hexagon::getRes() const {
    return this->Resource;
}

void Hexagon::setVertexs(std::vector<Point*>&ver) {
    for (int i = 0; i < 5; ++i) {
        if (ver.at(i) == ver[i + 1]) {
            throw std::invalid_argument("invalid Point.");
        }
        this->vertex.push_back(ver[i]);
        this->vertex.at(i)->set_res(this->Resource);
    }
    this->vertex.push_back(ver.at(5));
    this->vertex.at(5)->set_res(this->Resource);
}

bool Hexagon::validRes(int res) {
    return res >= 0 && res <= 5;
}

std::vector<Point*> Hexagon::getVertex() {
    return this->vertex;
}

std::vector<std::string> Hexagon::Print_Hexagon() const {
    return {
            "  ___  ",
            " /   \\ ",
            std::string("/") + std::to_string(Num_Dice) + " " + std::to_string(Resource) + "\\",
            "\\     /",
            " \\___/ "

    };
}




