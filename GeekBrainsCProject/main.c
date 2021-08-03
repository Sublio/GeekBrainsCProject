//
//  main.c
//  GeekBrainsCProject
//
//  Created by Denis Mordvinov on 25.07.2021.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "ChessSquareColor.h"
#include <string.h>

//void bmi(void){
//    // Task 1: BMI
//    float body_weight;
//    float body_height;
//    float bmi;
//    printf("Enter body weight in kilos:\n");
//    scanf("%f", &body_weight);
//    printf("Enter body height in meters:\n");
//    scanf("%f", &body_height);
//    //I=m/(h*h)
//    bmi = body_height/(pow(body_weight, 2));
//    printf("The BMI is: %f\n", bmi);
//}

void convertInt(void){
    int i, r;
    printf("Enter the number\n");
    scanf("%i", &i);
    printf("%i", i);
}


void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Перевод числа из десятичной системы в двоичную;\n");
    printf("[2] Найти максимальное из четырех чисел.Массивы не использовать;\n");
    printf("[3] Написать программу обмена значениями двух целочисленных переменных;\n");
    printf("[4] Написать программу нахождения корней заданного квадратного уравнения;\n");
    printf("[5] С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится;\n");
    printf("[6] Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет»;\n");
    printf("[7]  С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся поля к одному цвету или нет;\n");
    printf("[8] Ввести a и b и вывести квадраты и кубы чисел от a до b;\n");
    printf("[9] Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления;\n");
    printf("[10] Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    switch (select) {
        case 1:
            convertInt();
            //showMenu();
            break;
//        case 2:
//            findMaxNumber();
//            showMenu();
//            break;
//        case 3:
//            exchangeNumber();
//            showMenu();
//            break;
//        case 4:
//            equationRoots();
//            showMenu();
//            break;
//        case 5:
//            monthOfYear();
//            showMenu();
//            break;
//        case 6:
//            yearYears();
//            showMenu();
//            break;
//        case 7:
//            chess();
//            showMenu();
//            break;
//        case 8:
//            squaresCubes();
//            showMenu();
//            break;
//        case 9:
//            quotientRemainder();
//            showMenu();
//            break;
//        case 10:
//            oddNumber();
//            showMenu();
//            break;
        case 0:
        default:
            break;
    }
}



int main(int argc, const char * argv[]) {
    showMenu();
    return 0;
}
