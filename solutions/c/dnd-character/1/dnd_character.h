#ifndef DND_CHARACTER_H
#define DND_CHARACTER_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

typedef struct {
   int strength;
   int dexterity;
   int constitution;
   int intelligence;
   int wisdom;
   int charisma;
   int hitpoints;
} dnd_character_t;

int ability(void);
int modifier(int score);
dnd_character_t make_dnd_character(void);

void roll_4_dices(short int* roll);
void sort_4_dices(short int* roll);
int sum_top_3(short int* roll);

#endif
