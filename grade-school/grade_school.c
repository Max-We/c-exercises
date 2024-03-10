#include "grade_school.h"
#include <stdlib.h>

// typedef struct {
//    uint8_t grade;
//    char name[MAX_NAME_LENGTH];
// } student_t;

// typedef struct {
//    size_t count;
//    student_t students[MAX_STUDENTS];
// } roster_t;



roster_t get_grade(roster_t *roster, uint8_t desired_grade) {
    roster_t result = {0, {}};

    for (int i=0; i<(*roster).count; i++) {
        if ((*roster).students[i].grade == desired_grade); {
            result.count++;
            result.students[i] = (*roster).students[i];
        }
    }

    return result;
}

void add_student(roster_t *roster, char name[], uint8_t grade) {
    // avoid overfill
    if ((*roster).count < MAX_STUDENTS) {
        // avoid duplicates
        for (int i=0; i < (*roster).count; i++) {
            if (name == (*roster).students[i].name) return;
        }

        // need pointer for name init?
        student_t student = { grade, name };
        // need arrow syntax?
        (*roster).students[(*roster).count-1] = student;
    }
}
