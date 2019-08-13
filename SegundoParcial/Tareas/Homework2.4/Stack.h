#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node* getnode() {
  return (struct Node*)malloc(sizeof(struct Node));
};

struct Node* top; 
int c = 0;
struct Node* push(struct Node *);
struct Node* pop(struct Node *);
void display(struct Node *);

struct Node* push(struct Node* node) {
  struct Node* T;
  if(node == NULL ) {
    node = getnode();
    T = top = node;
    T->prev = NULL;
  }
  else {  
    T = getnode();
    top->next = T;   
    T->prev = top;
    top = T;
  }
  printf("Enter a val\n"); 
  c++;
  scanf("%d", &T->data);
  T->next = NULL;
  return node;
}

struct Node* pop(struct Node* node) {
  struct Node* tmp;
  if((node == NULL) && (c < 1)) {
    printf("Underflow\n"); 
    return node;
  }
  tmp = top;
  printf("The deleted value is : %d\n", tmp->data);
  if(c != 1) {
    top = tmp->prev;
    tmp->prev = NULL; 
    top->next = NULL;
  }
  else if(c == 1) {
    node = NULL;
  }
  c--;
  return node;
}

void display(struct Node* node) {   
  if(node == NULL) {
    printf("Empty\n"); 
    return;
  }
  while(node != NULL) {
      printf("%d  ", node->data);
      node = node->next;
  }
  printf("\n");
}