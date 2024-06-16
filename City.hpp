/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX3_SW2_CITY_HPP
#define EX3_SW2_CITY_HPP
#include "Settlement.hpp"


class City : public Settlement {
public:
    explicit City(Player *p, Point* v);

    // Overriding increase_Resource
};


#endif //EX3_SW2_CITY_HPP
