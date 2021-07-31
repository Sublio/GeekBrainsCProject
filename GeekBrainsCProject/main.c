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

void bmi(void){
    // Task 1: BMI
    float body_weight;
    float body_height;
    float bmi;
    printf("Enter body weight in kilos:\n");
    scanf("%f", &body_weight);
    printf("Enter body height in meters:\n");
    scanf("%f", &body_height);
    //I=m/(h*h)
    bmi = body_height/(pow(body_weight, 2));
    printf("The BMI is: %f\n", bmi);
}

void findMaxNumber(void){
    // Task 2:  Найти максимальное из четырех чисел. Массивы не использовать.
    int a,b,c,internal;
    printf("Введите первое число:\n");
    scanf("%d", &a);
    printf("Введите второй число:\n");
    scanf("%d",&b);
    printf("Введите третье число:\n");
    scanf("%d", &c);
    internal = a;
    if (internal < b) internal = b;
    if (internal < c) internal = c;
    printf("Максимальное число: %d\n", internal);
}

void exchangeNumber(void){
    // Task 3: Написать программу обмена значениями двух целочисленных переменных
    // With third variable
    int a,b,c;
    printf("Введите первое число:\n");
    scanf("%d", &a);
    printf("Введите второе число:\n");
    scanf("%d", &b);
    printf("Первое число: %d. Второе число: %d\n", a,b);
    c = a;
    a = b;
    b = c;
    printf("После перестановки первое число: %d. Второе число: %d\n", a,b);
    
    //    // Without third variable
    //    int a,b;
    //    printf("Введите первое число:\n");
    //    scanf("%d", &a);
    //    printf("Введите второе число:\n");
    //    scanf("%d", &b);
    //    printf("Первое число: %d. Второе число: %d\n", a,b);
    //    a = a + b;
    //    b = a - b;
    //    a = a - b;
    //    printf("После перестановки первое число: %d. Второе число: %d\n", a,b);
}

void equationRoots(void){
    //Task 4: Написать программу нахождения корней заданного квадратного уравнения.
    float a,b,c,d, x1, x2;
    printf("Введите а число квадратного уравнения\n");
    scanf("%f", &a);
    printf("Введите b число квадратного уравнения\n");
    scanf("%f", &b);
    printf("Введите c число квадратного уравнения\n");
    scanf("%f", &c);
    
    d = (pow(b, 2) - 4*a*c);
    
    if (d > 0) {
        x1 = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        x2 = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        printf("Уравнение имеет два корня: x1 = %f, x2 = %f\n", x1,x2);
    }else {
        printf("Уравнение не имеет корней\n");
    }
}

void monthOfYear(void){
    //Task 5: С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
    int month;
    printf("Введите порядковый номер месяца в году\n");
    scanf("%d",&month);
    
    if (month >= 1 && month <= 2){
        printf("Месяц относится к зимнему периоду\n");
    }else if (month >= 3 && month <= 5){
        printf("Месяц относится к весеннему периоду\n");
    }else if ( month >= 6 && month <= 8){
        printf("Месяц относится к летнему периоду\n");
    }else if (month >= 9 && month <= 11){
        printf("Месяц относится к осеннему периоду\n");
    }else if (month == 12) {
        printf("Месяц относится к зимнему периоду\n");
    }else {
        printf("Неправильное число - попробуйте ввести номер месяца от 1 до 12\n");
    }
}

void yearYears(void){
    
    //Task 6 - Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
    
    int age, x, y;
    x = 10;
    y = 100;
    printf("Введите возраст от 1 до 150 лет\n");
    scanf("%d", &age);
    if (age < 1 || age > 150){
        printf("Введите возраст от 1 до 150 лет включительно\n");
    }
    
    if (x%y == 1 && x!=11 && x!=111){
        printf("Вам %d год\n", age);
    }else if (x%y>1 && x%y<5 && x!=12 && x!=13 && x!=14){
        printf("Вам %d года\n", age);
    }else {
        printf("Вам %d лет\n", age);
    }
    
}

void chess(void){
    char c,b;
    printf("Введите координаты первой клетки в формате а1\n");
    scanf("%s", &c);
    printf("Введите координаты второй клетки в формате а1\n");
    scanf("%s", &b);
    checkSquaresSameColor(&c, &b);
}

void squaresCubes(void){
    //Task 8: Ввести a и b и вывести квадраты и кубы чисел от a до b.
    int i,  a, b;
    printf("Введите первое число\n");
    scanf("%d", &a);
    printf("Введите второе число\n");
    scanf("%d", &b);
    printf("Сперва выводим все квадраты чисел\n");
    i = a;
    for (i; i<=b; i++) {
        printf("%d\n", i*i);
    }
    printf("Теперь выводим все кубы чисел на промежутке\n");
    for (a; a<=b; a++){
        printf("%d\n", a*a*a);
    }
}

void quotientRemainder(void){
    //Task 9: Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
    int N, K, a = 0, b;
    // a - частное
    // b - остаток
    printf("Введите первое число\n");
    scanf("%d", &N);
    printf("Введите второе число\n");
    scanf("%d", &K);
    
    if (N > 0 & K > 0){
        
        while (N > K) {
            a++;
            N = N - K;
        }
        b = N;
        printf("%d - частное\n%d - остаток\n", a, b);
    }else {
        puts("Введите положительные числа\n");
    }
}

void oddNumber(void){
    //Task 10: Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа
    // N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
    int n, a, result = 0;
    printf("Введите целое число\n");
    scanf("%d", &n);
    
    for (a=n; a && !result; a/=10){
        if ( (a%10)%2 ) result = 1;
    }
    printf("%s\n", result? "True" : "False");
}


void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);\n");
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
            bmi();
            showMenu();
            break;
        case 2:
            findMaxNumber();
            showMenu();
            break;
        case 3:
            exchangeNumber();
            showMenu();
            break;
        case 4:
            equationRoots();
            showMenu();
            break;
        case 5:
            monthOfYear();
            showMenu();
            break;
        case 6:
            yearYears();
            showMenu();
            break;
        case 7:
            chess();
            showMenu();
            break;
        case 8:
            squaresCubes();
            showMenu();
            break;
        case 9:
            quotientRemainder();
            showMenu();
            break;
        case 10:
            oddNumber();
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
