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

#define max 100
#define MAX 50

void insert(void);
void delete(void);
void display(void);
int queue_array[MAX];
int rear = -1;
int front = -1;



int stack[max], top = -1, i, x;

void queueManager(void){
    int choice;
    while(1){
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Wrong number selected\n");
                break;
        }
    }
}

void insert(void){
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}


void delete(void)
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}


void display(void)
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

void push(int x){
    ++top;
    stack[top] = x;
}

int pop(void){
    return stack[top];
}

void stackConvertion(void){
    int num, total = 0, item;
    printf("Please enter the number: ");
    scanf("%d", &num);
    
    while(num>0){
        total = num%2;
        push(total);
        num/=2;
    }
    
    for (i = top; top>-1; top --){
        item = pop();
        printf("%d", item);
    }
    
}

void bracketSequence(void){
    int c=0,count1=0,count2=0;
    char s[1000];
    printf("Enter bracket sequence: ");
    scanf("%s",s);
    while(s[c] != '\0')
    {
        if(s[c] == '"')
        {
            ++count2;
        }
        if(s[c] == ')')
        {
            --count1;
        }
        if (count1 != -1)
        {
            if(s[c]== '(')
            {
                ++count1;
            }
        }
        
        ++c;
    }
    //printf("%d\n",count1);
    //printf("%d\n",count2);
    if(count1 == 0 && count2%2 == 0)
    {
        printf("Sequence is valid!\n");
    }
    else
    {
        printf("Sequence is not valid!\n");
    }
}


void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Реализовать перевод из десятичной в двоичную систему счисления с использованием стека;\n");
    printf("[2] Написать программу, которая определяет, является ли введенная скобочная последовательность правильной;\n");
    printf("[3] Реализовать очередь;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    switch (select) {
        case 1:
            stackConvertion();
            break;
        case 2:
            bracketSequence();
            break;
        case 3:
            queueManager();
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
