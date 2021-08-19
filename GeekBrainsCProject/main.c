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

#define SIZE 20


void quickSort(int *numbers, int left, int right)
{
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = numbers[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо
    }
  }
  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}


void countArraySorting(int n, int array[], int sortedArray[])
{
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[i] > array[j])
                k++;
        }
        sortedArray[k] = array[i];
    }
}


void quickSortArrayForming(void){
    
    int a[SIZE];
     // Заполнение массива случайными числами
     for (int i = 0; i<SIZE; i++)
       a[i] = rand() % 201 - 100;
     // Вывод элементов массива до сортировки
     for (int i = 0; i<SIZE; i++)
       printf("%d ", a[i]);
     printf("\n");
     quickSort(a, 0, SIZE-1); // вызов функции сортировки
               // Вывод элементов массива после сортировки
     for (int i = 0; i<SIZE; i++)
       printf("%d ", a[i]);
     printf("\n");
}

void formTestArrayCounting(void){
    int N;
    printf("Введите размер массива\n");
    scanf("%d", &N);
    
    int *mass, *sortedMass;
    mass = (int *)malloc(N * sizeof(int));
    sortedMass = (int *)malloc(N * sizeof(int));
    //ввод элементов массива
    printf("Input the array elements:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &mass[i]);
    //сортировка методом подсчета
    countArraySorting(N, mass, sortedMass);
    //вывод отсортированного массива на экран
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", sortedMass[i]);
    printf("\n");
}


void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Сортировка подсчетом;\n");
    printf("[2] Быстрая сортировка;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    switch (select) {
        case 1:
            formTestArrayCounting();
            break;
        case 2:
            quickSortArrayForming();
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
