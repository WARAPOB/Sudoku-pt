#include <stdio.h>
#include<stdlib.h>
bool stage1();
void Red();
void Cyan();
void Yellow();
void Green();
void reset();
int i;
bool test = true;
int main() {
    Cyan();
    printf("Welcome to SUDOKU game\n");
    reset();
    do {
        system("cls");
        stage1();
    } while (test == false);
    system("cls");
    Green();
    printf("Great!!!! ");
   

}

bool stage1() {
    int b[16], a[4][4],d[4][4];
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][3] = 2;
    a[2][0] = 3;
    a[2][3] = 1;
    a[3][0] = 2;
    a[3][3] = 3;
    b[2] = 3;
    b[5] = 4;
    b[6] = 2;
    b[9] = 3;
    b[10] = 1;
    b[12] = 2;
    b[15] = 3;
    Yellow();
    printf("a b | %d c\n", a[0][2]);
    printf("d %d | %d e\n", a[1][0], a[1][3]);
    printf("----|----\n");
    printf("f %d | %d g\n", a[2][0], a[2][3]);
    printf("%d h | i %d\n", a[3][0], a[3][3]);
    reset();
    for (int i = 0; i < 16; i++) {
        if (i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 12 || i == 15) {
            continue;
        }
        scanf_s("%d", &b[i]);
    }
    int h = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            d[i][j] = b[h];
            //printf("d[%d][%d] = %d\n", i, j, d[i][j]);
            h++;
        }
    }
    int x = 0;
    int* pt;
    pt = b;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            printf("pt = %d d = %d\n", *(pt+x),d[i][j]);
            if (*(pt + x) == d[i][j]) {
                Red();
                printf("Wrong\n");
                reset();
                test = false;
                return test;
            }
        }
        x = x + 4;
    }
    x = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            printf("pt = %d d = %d\n", *(pt + x), d[i][j]);
            if (*(pt + x) == d[j][i]) {
                Red();
                printf("Wrong\nTry again");     
                reset();
                test = false;
                return test;
            }
        }
        x++;
    }
}

void Red() {
    printf("\033[0;31m");
}
void Green() {
    printf("\033[1;32m");
}
void Yellow() {
    printf("\033[0;33m");
}
void Cyan() {
    printf("\033[1;36m");
}
void reset() {
    printf("\033[0m");
}