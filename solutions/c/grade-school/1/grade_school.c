 #include "grade_school.h"


//helper functions
int compare_students(const void *a, const void *b) {
    const student_t *s1 = a;
    const student_t *s2 = b;

    if (s1->grade != s2->grade)
        return s1->grade - s2->grade;

    return strcmp(s1->name, s2->name);
}

int compare_students_by_name(const void *a, const void *b) {
    const student_t *s1 = a;
    const student_t *s2 = b;
    return strcmp(s1->name, s2->name);
}


void init_roster(roster_t *yellow_roster) {
    yellow_roster->count = 0;
}

int add_student(roster_t *yellow_roster, char *name, uint8_t grade) {

    //check if the student is already listed
    for (int i = 0; i < (int)yellow_roster->count; i++) {
        char *temp = yellow_roster -> students[i].name;
        if (strcmp(temp, name) == 0) {
            return 0;
        }
    }


    size_t indexx = yellow_roster->count;
    yellow_roster->students[indexx].grade = grade;
    strcpy(yellow_roster->students[indexx].name, name);

    yellow_roster->count++;

    //sort the students array
    qsort(yellow_roster->students, yellow_roster->count, sizeof(student_t), compare_students);

    return 1;
}

roster_t get_grade (roster_t *yellow_roster, uint8_t grade) {

    
    roster_t grade_roster;
    grade_roster.count = 0;

    for (size_t i = 0; i < yellow_roster->count; i++) {

        uint8_t yellow_grade = yellow_roster->students[i].grade;

        if (yellow_grade == grade) {

            add_student(&grade_roster, yellow_roster->students[i].name, yellow_roster->students[i].grade);

        }
    }

    qsort(yellow_roster->students, yellow_roster->count, sizeof(student_t), compare_students_by_name);

    return grade_roster;
}