#include "queen_attack.h"

 

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    //testing if the positions are valid
    if(queen_1.column > 7 || queen_1.row > 7)return INVALID_POSITION;
    if(queen_2.column > 7 || queen_2.row > 7)return INVALID_POSITION;

    //testing if the positions are the same
    if(queen_1.column == queen_2.column && queen_1.row == queen_2.row)return INVALID_POSITION;
    
    //assuming valid positions are given
    if(queen_1.column == queen_2.column)return CAN_ATTACK;
    if(queen_1.row == queen_2.row)return CAN_ATTACK;
    int run = (int)queen_1.column - (int)queen_2.column;
    int rise = (int)queen_1.row - (int)queen_2.row;
    if((run*run) == (rise*rise))return CAN_ATTACK;
    
    return CAN_NOT_ATTACK;
}

