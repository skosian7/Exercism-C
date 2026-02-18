 #include "yacht.h"

 

#define SWAP(a, b) if (arr[a] > arr[b]) { int temp = arr[a]; arr[a] = arr[b]; arr[b] = temp; }

void sortFive(int arr[]) {
    // A Bose-Nelson Algorithm sequence for 5 elements
    SWAP(0, 1); SWAP(3, 4);
    SWAP(2, 4); SWAP(2, 3);
    SWAP(0, 3); SWAP(0, 2);
    SWAP(1, 4); SWAP(1, 3);
    SWAP(1, 2);
}

int score(dice_t dice, category_t category) {

    int my_score = 0;

    //count score for categories 1-6
    if (category < FULL_HOUSE) {
        for (int i = 0; i < 5; i++) {
            if (dice.faces[i] == (int)(category + 1)) my_score += dice.faces[i];
        }
    }

    //sort the dice.faces array
    sortFive(dice.faces);

     
    int a = dice.faces[0];
    int b = dice.faces[4];

    //count category full house
    if (category == FULL_HOUSE && (a != b)) {
        int zero_one = dice.faces[0] == dice.faces[1];
        int three_four = dice.faces[3] == dice.faces[4];

        if ( zero_one && three_four ) {

            for (int i = 0; i < 5; i++) {
                my_score += dice.faces[i];
                if (dice.faces[i] != a && dice.faces[i] != b) {
                    my_score = 0;
                    break;
                }
            }
        }

    }

    if (category == FOUR_OF_A_KIND) {
        if (dice.faces[0] == dice.faces[3]) {
            for (int i = 0; i < 4; i++) {
                my_score += dice.faces[i];
                if (dice.faces[i] != dice.faces[0]) {
                    my_score = 0;
                    break;
                }
            }
        }else if (dice.faces[1] == dice.faces[4]) {
            for (int i = 1; i < 5; i++) {
                my_score += dice.faces[i];
                if (dice.faces[i] != dice.faces[1]) {
                    my_score = 0;
                    break;
                }
            }
        }
    }

    if (category == LITTLE_STRAIGHT) {
        my_score = 30;
        for (int i = 0; i < 5; i++) {
            if (dice.faces[i] != (i + 1)) {
                my_score = 0;
                break;
            }
        }
    }
    
    if (category == BIG_STRAIGHT) {
        my_score = 30;
        for (int i = 0; i < 5; i++) {
            if (dice.faces[i] != (i + 2)) {
                my_score = 0;
                break;
            }
        }
    }

    //count category choice
    if (category == CHOICE) {
        for (int i = 0; i < 5; i++) {
            my_score += dice.faces[i];
        }
    }

    //count category yacht
    if (category == YACHT) {
        int same_faces = 1;
        for (int i = 0; i < 5; i++) {
            if (dice.faces[i] != dice.faces[0]) {
                same_faces = 0;
                break;
            }
        }
        if (same_faces == 1) {
            my_score = 50;
        }
    }

    return my_score;
}
