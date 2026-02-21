#include "kindergarten_garden.h"

plants_t plants(const char *diagram, const char *student) {
    plants_t my_plants;

    //find the student
    //const char *children [] = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
    char the_student = student[0];
    const char children[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    int indexx = 0;
    for (int i = 0; i < 12; i++) {
        if (the_student == children[i]) {
            indexx = 65 - i;
            break;
        }
    }

    //find the indices of plants in diagram
    int index0 = the_student - indexx;
    int index1 = index0 + 1;

    int n_index = 0;
    char find_n = diagram[n_index];
    while (find_n != '\n') {
        n_index++;
        find_n = diagram[n_index];
    }
    int index2 = n_index + index1;
    int index3 = index2 + 1;

    //find the plants
    char the_plants[4];
    the_plants[0] = diagram[index0];
    the_plants[1] = diagram[index1];
    the_plants[2] = diagram[index2];
    the_plants[3] = diagram[index3];

    for (int i = 0; i < 4; i++) {
        switch (the_plants[i]) {
            case 'C':
                my_plants.plants[i] = CLOVER;
                break;
            case 'G':
                my_plants.plants[i] = GRASS;
                break;
            case 'R':
                my_plants.plants[i] = RADISHES;
                break;
            case 'V':
                my_plants.plants[i] = VIOLETS;
                break;
            default:
                break;
        }
    }

    return my_plants;
}