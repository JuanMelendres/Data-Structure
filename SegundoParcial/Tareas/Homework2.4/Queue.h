#include <stdio.h>
#include <stdlib.h>
   
struct QNode {
    char data; 
    struct QNode *next; 
    struct QNode *prev;
}; 
  
struct Queue {
    struct QNode *front, *rear; 
};

struct QNode* newNode(char k);
struct Queue* createQueue();
void enQueue(struct Queue *q, int k);
struct QNode *deQueue(struct Queue *q);
  
struct QNode* newNode(char k) { 
    struct QNode* tmp = (struct QNode*)malloc(sizeof(struct QNode)); 
    tmp->data = k; 
    tmp->next = NULL; 
    tmp->prev = NULL;
    return tmp;  
} 
  
struct Queue* createQueue() { 
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
void enQueue(struct Queue *q, char k) { 
    struct QNode *temp = newNode(k); 
    if (q->rear == NULL) { 
       q->front = q->rear = temp; 
       return; 
    } 
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
struct QNode *deQueue(struct Queue *q) { 
    if (q->front == NULL) {
       return NULL; 
    }
    struct QNode *temp = q->front; 
    q->front = q->front->next;  
    if (q->front == NULL) {
       q->rear = NULL; 
    }
    return temp; 
} 
  