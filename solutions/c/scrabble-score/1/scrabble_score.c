 #include "scrabble_score.h"

const char row1[] = {'A','a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'L', 'l', 'N', 'n', 'R', 'r', 'S', 's', 'T', 't'}; //1
const char row2[] = {'D', 'd', 'G', 'g'};//2
const char row3[] = {'B', 'b', 'C', 'c', 'M', 'm', 'P', 'p'};//3
const char row4[] = {'F', 'f', 'H', 'h', 'V', 'v', 'W', 'w', 'Y', 'y'};//4
const char row5[] = {'K', 'k'};//5
const char row8[] = {'J', 'j', 'X', 'x'};//8
const char row10[] = {'Q', 'q', 'Z', 'z'};//10

const int map_sizes[] = {20, 4, 8, 10, 2, 4, 4};

const char* map[] = {row1, row2, row3, row4, row5, row8, row10};

unsigned int score(const char *word) {
    unsigned int score = 0;

    int k = 0;
    while (word[k] != '\0') {
        char letter = word[k];
        for ( int i = 0; i < 7; i++) {
            for ( int j = 0; j < map_sizes[i]; j++) {

                if (letter == map[i][j]) {
                    if (i < 5) {
                        score += (i + 1);
                    }else if (i == 5) {
                        score += 8;
                    }else {
                        score += 10;
                    }
                }
            }
        }
        k++;
    }

    return score;
}