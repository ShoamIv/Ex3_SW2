
#ifndef EX3_SW2_DICE_HPP
#define EX3_SW2_DICE_HPP


#include <cstdlib>

class Dice {
    int dice [];
public:
    static int roll(){
        return rand()%6+1;
    }
};


#endif //EX3_SW2_DICE_HPP
