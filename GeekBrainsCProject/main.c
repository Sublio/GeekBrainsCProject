//
//  main.c
//  GeekBrainsCProject
//
//  Created by Denis Mordvinov on 25.07.2021.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void pathFinder()
{
    
    //    Map
    //    3 3
    //    1 1 1
    //    0 1 0
    //    0 1 0
    
    int N = 0, M = 0;
    
    printf("Input parameters for NxM map\n");
    printf("format N-M, like 3-3 : \n");
    scanf("%d-%d", &N, &M);
    
    printf("1 - we can move\n");
    printf("0 - we forbid to  move\n");
    printf("\n");
    
    int roadBoard[N][M];
    int value, i, j;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("Input value 1 or 0 for [%d]x[%d] : \n", i, j);
            scanf("%d", &value);
            if ((value > 1) || (value < 0))
                roadBoard[i][j] = 1;
            else
                roadBoard[i][j] = value;
        }
    }
    
    printf("\n");
    printf("Entered values : \n");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%d  ", roadBoard[i][j]);
        printf("\n");
    }
    
    roadBoard[0][0] = 1;
    
    for (i = 1; i < N - 1; i ++) {
        if (roadBoard[i][0] == 0)
            roadBoard[i+1][0] = 0;
    }
    for (j = 1; j < M - 1; j ++) {
        if (roadBoard[0][j] == 0)
            roadBoard[0][j+1] = 0;
    }
    
    printf("\n");
    printf("Map matrix : \n");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%d  ", roadBoard[i][j]);
        printf("\n");
    }
    
    printf("\n");
    
    for (i = 1; i < N; i++) {
        for (j = 1; j < M; j++)
            if (roadBoard[i][j] != 0)
                roadBoard[i][j] = roadBoard[i][j-1] + roadBoard[i-1][j];
    }
    
    
    printf("\n");
    printf("Steps count matrix : \n");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%d     ", roadBoard[i][j]);
        printf("\n");
        printf("\n");
    }
    
    printf("\n");
    printf("\n");
    
}

int max(int a, int b);

int lcs( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    
    return L[m][n];
}

int max(int a, int b)
{
    return (a > b)? a : b;
}



void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Вычислить длину подпоследовательности;\n");
    printf("[2] Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int m = strlen(X);
    int n = strlen(Y);
    
    
    switch (select) {
        case 1:
            printf("Длина подпоследовательности = %d\n", lcs( X, Y, m, n ) );
            break;
        case 2:
            pathFinder();
            break;
        case 0:
        default:
            break;
    }
}


int main(int argc, const char * argv[]) {
    showMenu();
    return 0;
}
