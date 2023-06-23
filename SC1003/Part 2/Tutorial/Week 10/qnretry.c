void freq(int ar[], int ar2d[][50], int n);
void printer(int array2d[][50],int *min, int *max);
int main()
{
    int noinput, i, k, j, l;
    int array[100];
    int arrange[10][50];
    int min=0, max=9;

    printf("How many integars?\n");
    scanf("%d", &noinput);

    for (k=0;k<100;k++){
        array[k] = 101;
    }

    for (j=0;j<10;j++) {
        for (l=0;l<50;l++)
            arrange[j][l] = 101;
    }

    for (i=0; i < noinput; i++){
        array[i] = rand() %100;
    }


    freq(array, arrange, noinput);

    printer(arrange, &min, &max);
    return 0;
}

void freq(int ar[], int ar2d[][50],int n)
{
    int i, num;
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, ifun=0, j=0;

    for (i=0; i<n; i++) {
        num = ar[i]/10;
        switch (num) {
        case (0):
            ar2d[0][a] = ar[i];
            a+=1;
            break;
        case (1):
            ar2d[1][b] = ar[i];
            b+=1;
            break;
        case(2):
            ar2d[2][c] = ar[i];
            c+=1;
            break;
        case(3):
            ar2d[3][d] = ar[i];
            d+=1;
            break;
        case(4):
            ar2d[4][e] = ar[i];
            e+=1;
            break;
        case(5):
            ar2d[5][f] = ar[i];
            f+=1;
            break;
        case(6):
            ar2d[6][g] = ar[i];
            g+=1;
            break;
        case(7):
            ar2d[7][h] = ar[i];
            h+=1;
            break;
        case(8):
            ar2d[8][ifun] = ar[i];
            ifun+=1;
            break;
        case(9):
            ar2d[9][j] = ar[i];
            j+=1;
            break;
        }
    }
}
void printer(int array2d[][50],int *min, int *max) {

    int i, j;

    for (i=0; i<10; i++){
        printf("%2d - %2d |", *min, *max);

        for (j=0; j<50; j++) {
            if (array2d[i][j] == 101)
                break;
            else
                printf("*");
        }
        *min+=10;
        *max+=10;
        printf("\n");
    }
}
