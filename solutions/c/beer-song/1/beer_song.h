#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 

void recite(uint8_t start_bottles, uint8_t take_down, char **song);

int find_len(char *s);
void lines_zero(int line_number, char **song);
void lines_one(int line_number, char **song);
void lines_many_dd(int bottles, int line_number, char **song);


#endif
