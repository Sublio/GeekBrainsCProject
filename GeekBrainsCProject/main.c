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

#define N 10

int swapsCount = 0;

void swapElement(int *arr, int i)
{
    int intermediate;
    intermediate = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = intermediate;
    swapsCount++;
    printf("Current swaps count is: %d\n", swapsCount);
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    swapsCount++;
}

void shakerSort(int *arr, int size)
{
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--)
             if (arr[i - 1] > arr[i]) swapElement(arr, i);
         leftMark++;
 
         for (int i = leftMark; i <= rightMark; i++)
              if (arr[i - 1] > arr[i]) swapElement(arr, i);
         rightMark--;
      }
    swapsCount = 0;
}

void bubbleSort(int *num, int size)
{
  for (int i = 0; i < size-1; i++)
  {
    for (int j = (size - 1); j > i; j--)
    {
      if (num[j - 1] > num[j])
      {
        int temp = num[j - 1];
        num[j - 1] = num[j];
        num[j] = temp;
        swapsCount++;
      }
    }
  }
    printf("Current swaps count is: %d\n", swapsCount);
    swapsCount = 0;
}

void optimisedBubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    
    printf("Current swaps count is: %d\n", swapsCount);
    swapsCount = 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Неоптимизированная сортировка пузырьком;\n");
    printf("[2] Оптимизированная сортировка пузырьком;\n");
    printf("[3] Шейкерная сортировка;\n");
    printf("[4] Бинарный поиск;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    int A[N] = {1,3,4, 54, 22,66,23,55,6,10};
    printf("Array before sorting\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int searchableELement = 40;
    int result;
    
    
    switch (select) {
        case 1:
            bubbleSort(A, N);
            printf("Array after sorting\n");
            for (int i = 0; i < N; i++) {
                printf("%d ", A[i]);
            }
            printf("\n");
            break;
            
        case 2:
            optimisedBubbleSort(A, N);
            printf("Array after sorting\n");
            for (int i = 0; i < N; i++) {
                printf("%d ", A[i]);
            }
            printf("\n");
            break;
        case 3:
            shakerSort(A, N);
            printf("Array after sorting\n");
            for (int i = 0; i < N; i++) {
                printf("%d ", A[i]);
            }
            printf("\n");
            showMenu();
            break;
        case 4:
            result = binarySearch(arr, 0, n - 1, searchableELement);
            printf("Index of element is %d\n", result);
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
