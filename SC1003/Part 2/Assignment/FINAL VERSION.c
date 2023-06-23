#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	/*end_edit*/
	/*edit*/
/* Write your code here */
#define MAX 5

typedef struct
{
    int roomID;
    int status;
    char customerName[20];
} Room;

int listOccupiedRooms(Room dehotel[MAX]);
int assignRoom(Room dehotel[MAX]);
int removeRoom(Room dehotel[MAX]);
int findcustomer(Room dehotel[MAX]);

int main()
{
    int def_id = 1, dump;
    int usersel, i;
    Room hotel[MAX];

    for (i=0; i<MAX;i++) {
        hotel[i].status = 0;
        hotel[i].roomID = def_id++;
        sscanf("0", "%s", hotel[i].customerName);
    }

    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");
    printf("Enter your choice: \n");
    scanf("%d", &usersel);

    while (usersel != 5) {
        switch (usersel)
        {
        case 1:
            dump = listOccupiedRooms(hotel);
            break;
        case 2:
            dump = assignRoom(hotel);
            break;
        case 3:
            dump = removeRoom(hotel);
            break;
        case 4:
            dump = findCustomer(hotel);
            break;
        case 5:
        default:
            break;
        }
        printf("Enter your choice: \n");
        scanf("%d", &usersel);
    }
    return 0;
}


int assignRoom(Room dehotel[MAX])
{
    int id;
    char name[20]; char *p;
    int sum = 0;

    printf("assignRoom():\n");

    for (int a=0;a<MAX;a++) {
        sum += (dehotel[a].status);
    }

    if (sum == 5) {
        printf("The hotel is full\n");
        return 0;
    }

    do {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &id);
        if ((id<=0) || (id>5))
            continue;
        if (dehotel[id-1].status==1) {
            printf("Occupied! Enter another roomID\n");
            continue;
        }
        break;
    } while (1);

    printf("Enter customer name:\n");
    scanf("\n");
    fgets(name, 20, stdin);
    if (p=strchr(name,'\n'))
        *p = '\0';

    dehotel[id-1].status = 1;
    strcpy(dehotel[id-1].customerName, name);
    printf("The room has been assigned successfully\n");

    return 0;
}


int listOccupiedRooms(Room dehotel[MAX])
{
    int sum = 0;

    printf("listOccupiedRooms():\n");

    for (int a=0;a<MAX;a++) {
        sum += (dehotel[a].status);
    }

    if (sum == 0) {
        printf("The hotel is empty\n");
        return 0;
    }

    for (int z=0; z<MAX; z++) {
        if ((dehotel[z].status) != 0) {
        printf("roomID: %d\n", dehotel[z].roomID);
        printf("customer name: %s\n", dehotel[z].customerName);
        }
    }
}


int removeRoom(Room dehotel[MAX])
{
    int id;
    char name[20] = "0";
    int sum = 0;

    printf("removeRoom():\n");

    for (int a=0;a<MAX;a++) {
        sum += (dehotel[a].status);
    }

    if (sum == 0) {
        printf("All the rooms are empty\n");
        return 0;
    }

    do {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &id);
        if ((id<=0) || (id>5))
            continue;
        if (dehotel[id-1].status==0) {
            printf("Empty! Enter another roomID for removal\n");
            continue;
        }
        break;
    } while (1);

    dehotel[id-1].status = 0;
    strcpy(dehotel[id-1].customerName, name);
    printf("Removal is successful\n");

    return 0;
}


int findCustomer(Room dehotel[MAX])
{
    int b,c;
    char name[20], arrname[20], *p, lowarr[20];

    printf("findCustomer():\n");

    printf("Enter customer name:\n");
    scanf("\n");
    fgets(name, 20, stdin);
    if(p=strchr(name,'\n'))
        *p = '\0';
    b=0;
    while (name[b] != '\0') {
        if (isupper(name[b]))
            name[b] = tolower(name[b]);
        b++;
    }

    for (int a=0;a<MAX; a++) {
        c=0;
        if (dehotel[a].status == 1) {
            strcpy(arrname,(dehotel[a].customerName));

            while (arrname[c] != '\0') {
                if (isupper(arrname[c]))
                    arrname[c] = tolower(arrname[c]);
                c++;
            }
            if (strcmp(name,arrname) == 0){
                printf("The target customer name is found\n");
                printf("roomID: %d\n", dehotel[a].roomID);
                printf("customer name: %s\n", dehotel[a].customerName);
                return 0;
            }
        }
    }
    printf("The target customer name is not found\n");
    return 0;
}

	/*end_edit*/
