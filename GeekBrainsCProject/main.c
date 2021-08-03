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

int convertIntToBinary(int i){
        if (i == 0)
            return 0;
        else
            return (i % 2 + 10 *convertIntToBinary(i / 2));
}

void powerNonRecur(void){
    int i, power;
    printf("Enter the number:\n");
    scanf("%d", &i);
    printf("Enter exponenta:\n");
    scanf("%d", &power);
    printf("%f\n", pow(i, power));
   
}

int powerRecursively(int base, int a) {
    if (a != 0)
        return (base * powerRecursively(base, a - 1));
    else
        return 1;
}


//void calcRecursion(int a, int b, char str){
//    for (int i = 0; i<2; i++){
//        char s = str;
//        int n = a;
//        if (i == 0){
//            n++;
//            s+=*("+1");
//        }else{
//            n*=2;
//            s+=*("*2");
//        }
//        if (n<b) {
//            calcRecursion(a, b, str);
//        }else {
//            if (n==b){ printf("%d = %d", s, b);}
//        }
//    }
//}

int calcRecursion(int a, int b){
    if (a == b) {
        return 1;
    }
    if (a>b){
        return 0;
    }
    
    return calcRecursion(a + 1, b) + calcRecursion(a * 2, b);
}


void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Перевод числа из десятичной системы в двоичную;\n");
    printf("[2] Реализовать функцию возведения числа a в степень b без рекурсии;\n");
    printf("[3] Реализовать функцию возведения числа a в степень b через рекурсию;\n");
    printf("[4] Сколько существует программ, которые число 3 преобразуют в число 20: С использованием массива;\n");
    printf("[5] Сколько существует программ, которые число 3 преобразуют в число 20: С использованием рекурсии;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    int number, power;
    int result;
    
    switch (select) {
        case 1:
            printf("%d\n",convertIntToBinary(61));
            showMenu();
            break;
        case 2:
            powerNonRecur();
            showMenu();
            break;
        case 3:
            printf("Enter the number:\n");
            scanf("%d", &number);
            printf("Enter the power:\n");
            scanf("%d", &power);
            printf("Result is: %d\n", powerRecursively(number,power));
            showMenu();
            break;
        case 4://Сколько существует программ, которые число 3 преобразуют в число 20 через массив.
            printf("Enter the number:\n");
            scanf("%d", &number);
            printf("Enter the power:\n");
            scanf("%d", &power);
            printf("Result is: %d\n", powerRecursively(number,power));
            showMenu();
            break;
        case 5://Сколько существует программ, которые число 3 преобразуют в число 20 через рекурсию.
            result = calcRecursion(3, 20);
            printf("Количество программ: %d\n", result);
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
