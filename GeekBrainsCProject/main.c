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

void swapArrayEl(int *array, int i){
    int intermediate;
    intermediate = array[i];
    array[i] = array[i-1];
    array[i-1] = intermediate;
}

void shakeSort(int *array, int size){
    int leftMark = 1;
    int rightMark = size - 1;
    while(leftMark <= rightMark){
        for (int i = rightMark; i >= leftMark; i--){
            if (array[i-1]> array[i]){
                swapArrayEl(array, i);
                leftMark++;
            }
        }
        for (int j = leftMark; j <= rightMark; j++){
            if (array[j-1] > array[j]){
                swapArrayEl(array, j);
                rightMark--;
            }
        }
        printf("Iteration: %d", leftMark - 1);
    }
}

void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Перевод числа из десятичной системы в двоичную;\n");
    printf("[2] Шейкерная сортировка;\n");
    printf("[3] Реализовать функцию возведения числа a в степень b через рекурсию;\n");
    printf("[4] Сколько существует программ, которые число 3 преобразуют в число 20: С использованием массива;\n");
    printf("[5] Сколько существует программ, которые число 3 преобразуют в число 20: С использованием рекурсии;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    int array[7] = {1,42,525,4,23454,2,45};
    
    switch (select) {
        case 1:
            showMenu();
            break;
        case 2:
            shakeSort(&array, 7);
            showMenu();
            break;
        case 3:
            showMenu();
            break;
        case 4:
            showMenu();
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
