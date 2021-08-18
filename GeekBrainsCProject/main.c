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

#define SIZE 40

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

// Queue section declaration

struct queue* createQueue(void);
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

// End Queue section

int readNumbers(char *filename, int *data);
void showData(int *data, int len);
struct node* createNode(int v);

struct node {
    int vertex;
    struct node* next;
};


// Create a queue
struct queue* createQueue(void) {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Print the queue
void printQueue(struct queue* q) {
    int i = q->front;
    
    if (isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
    }
}

struct Graph {
    int numVertices;
    int* visited;
    
    // We need int** to store a two dimensional array.
    // Similary, we need struct node** to store an array of Linked lists
    struct node** adjLists;
};

void DFS(struct Graph* graph, int vertex) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;
    
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);
    
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void bfs(struct Graph* graph, int startVertex) {
    struct queue* q = createQueue();
    
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while (!isEmpty(q)) {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);
        
        struct node* temp = graph->adjLists[currentVertex];
        
        while (temp) {
            int adjVertex = temp->vertex;
            
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    
    graph->visited = malloc(vertices * sizeof(int));
    
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\n Список соседних вершин %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void graphInit(void){
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    DFS(graph, 2);
}

void graphBFS(void){
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    
    bfs(graph, 0);
}


void readData(void){
    char key;
    int len, data[1000];
    len = readNumbers("numbers.txt", data);
    showData(data, len);
    scanf("%c", &key);
}

int readNumbers(char *fileName, int *data){
    FILE *in;
    int len;
    int j;
    in = fopen("numbers.txt", "r");
    {
        printf("////////////////////Reading matrix//////////////////////\n");
        fscanf(in, "%d", &len);
        for (j = 0; j<len; j++){
            fscanf(in, "%d", data + j);
        }
        fclose(in);
    }
    return len;
}

void showData(int *data, int len){
    int j;
    
    printf("Showing %d numbers from data array....\n", len);
    for(j=0;j<len;j++) {
        printf("%d", *(data + j));
    }
    printf("\n");
}



void showMenu(void) {
    int select;
    printf("Выберите алгоритм:\n");
    printf("[1] Считывание матрицы смежности из файла и вывод ее в консоль;\n");
    printf("[2] Обход графа в глубину;\n");
    printf("[3] Обход графа в ширину;\n");
    printf("[0] выход \n");
    
    scanf("%d", &select);
    
    switch (select) {
        case 1:
            readData();
            break;
        case 2:
            graphInit();
            break;
        case 3:
            graphBFS();
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
