#include <stdio.h>

int main()

{
int number;

int *p;

number = 8;

p=100;

printf("part i\n")

printf("digit of d is %d\n", number);

printf("memory of d is %p\n", &number);

printf("p is %p\n", p);

printf("memory of p is %p\n", &p);

printf("digit of p is %d\n", *p);

printf("\n");

number = p;



return 0;
}