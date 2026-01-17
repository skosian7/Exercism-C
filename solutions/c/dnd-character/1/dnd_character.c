#include "dnd_character.h"

void roll_4_dices(short int* roll)
{
    srand(time(NULL));

    for(int i = 0; i < 4; i++)
    {
        roll[i] = (rand()%6) + 1;
    }
}

void sort_4_dices(short int* roll)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < (3-i); j++)
        {
            if(roll[j] < roll[j + 1])
            {
                roll[j] = roll[j]^roll[j + 1];
                roll[j + 1] = roll[j]^roll[j + 1];
                roll[j] = roll[j]^roll[j + 1];
            }
        }
    }
}

int sum_top_3(short int* roll)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += roll[i];
    }
    return sum;
}

int ability(void)
{
    short int roll[4];
    
    roll_4_dices(roll);
    sort_4_dices(roll);

    return sum_top_3(roll);    
}

int modifier(int score)
{
    float fl_mod =(score - 10)/ 2.0; 
    int mod = (int)floor(fl_mod); 
    return mod;  
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;
    
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();

    character.hitpoints = 10 + modifier(character.constitution);

    return character;
}