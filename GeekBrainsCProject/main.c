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

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;


void printTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
        printf("(");
 
        if (root->left)
            printTree(root->left);
        else
            printf("NULL");
        printf(",");
 
        if (root->right)
            printTree(root->right);
        else
            printf("NULL");
        printf(")");
        }
    }
}


Node* createFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = createFreeNode(value, NULL);
        return;
    }
 
    tmp = *head;
    while (tmp)
    {
        if (value> tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = createFreeNode(value, tmp);
                return;
            }
        }
        else if (value< tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = createFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2); // wrong tree node
        }
    }
}


void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}


void simTreePass(Node* root) {
    if (root) {
        simTreePass(root->left);
        printf("%d ", root->data);
        simTreePass(root->right);
    }
}

void inverseTreePrint(Node* root) {
    if (root) {
        simTreePass(root->left);
        simTreePass(root->right);
        printf("%d ", root->data);
    }
}

Node *find(Node *root, int value)
{
    while (root)   // Until tree is not null
    {
        if (root->data > value)
        {
            root = root->left;
            continue;
        }
        else if (root->data > value)
        {
            root = root->right;
            continue;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}


int hash(char *S)
{
     int r=0;
     while(*S)
     {
         r+=(int)(*S);
         S++;
     }
     return r;
}


//void showMenu(void) {
//    int select;
//    printf("Выберите алгоритм:\n");
//    printf("[1] Реализовать простейшую хеш-функцию;\n");
//    printf("[2] Написать программу, которая определяет, является ли введенная скобочная последовательность правильной;\n");
//    printf("[3] Реализовать очередь;\n");
//    printf("[0] выход \n");
//
//    scanf("%d", &select);
//    int i;
//
//    switch (select) {
//        case 1:
//            i = hash("avs");
//            printf("Result is %d\n", i);
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        case 0:
//        default:
//            break;
//    }
//}


int main(int argc, const char * argv[]) {
    //showMenu();
    return 0;
}
