#include <stdio.h>

struct person {
    char firstName[15];
    char lastName[15];
    int trial;

    struct Info{
        int age;
        float height;
        float weight;
        char firstName[15];
    }Info, *InfoPtr;

    //struct person *PersonP;

    }student1;

int main() {


    int student5;

    typedef struct person person_t;
    person_t *studentPtr = &student1;


    person_t **studentPtrPtr = &studentPtr;

    (studentPtr->InfoPtr)->age = 10;

    printf("%d \n", (*studentPtrPtr)->InfoPtr->age);


    return 0;
}
