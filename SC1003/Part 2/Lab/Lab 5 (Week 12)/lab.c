	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
   char name[20];
   int telno;
} PhoneBk;
void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);
int main()
{
   PhoneBk s[MAX];
   char t[20], *p;
   int size=0, choice;
   char dummychar;

   printf("Select one of the following options: \n");
   printf("1: readin()\n");
   printf("2: search()\n");
   printf("3: printPB()\n");
   printf("4: exit()\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            scanf("%c", &dummychar);
            size = readin(s);
            break;
         case 2:
            scanf("%c", &dummychar);
            printf("Enter search name: \n");
            fgets(t, 20, stdin);
            if (p=strchr(t,'\n')) *p = '\0';
            search(s,size,t);
            break;
         case 3:
            printPB(s, size);
            break;
      }
   } while (choice < 4);
   return 0;
}
void printPB(PhoneBk *pb, int size)
{
	/*edit*/
	/* Write your code here */

    printf("The phonebook list:\n");
    if (size == 0)
        printf("Empty phonebook");

    else {
        for (int i=0; i<size; i++) {
            printf("Name: %s\n", pb[i].name);
            printf("Telno: %d\n", pb[i].telno);
        }
    }

	/*end_edit*/
}
int readin(PhoneBk *pb)
{
	/*edit*/
	/* Write your code here */

    char dename[20],*p;
    int arsize=0;
    printf("Enter name:\n");
    scanf("\n");
    fgets(dename,20,stdin);
    if (p=strchr(dename, '\n'))
        *p='\0';

    while ( strcmp(dename, "#") != 0) {

        strcpy(pb[arsize].name,dename);
        printf("Enter tel:\n");
        scanf("%d", &(pb[arsize].telno));

        arsize+=1;

        printf("Enter name:\n");
        scanf("\n");
        fgets(dename,20,stdin);
        if (p=strchr(dename, '\n'))
            *p='\0';

    }

    return arsize;

	/*end_edit*/
}
void search(PhoneBk *pb, int size, char *target)
{
	/*edit*/
	/* Write your code here */
    for (int i=0;i<size;i++) {
        if (strcmp(pb[i].name, *target) == 0)
            printf("Name = %s, Tel = %d", pb[i].name, pb[i].telno);
            break

    printf("")
    }

	/*end_edit*/
}
