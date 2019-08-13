/*
Juan Antonio Melendres Villa A00369017
comentarios: Tuve problemas con poner los stacks y las queue, el programa no pudo correr con la lectura de archivos
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

# define MAXSTACK 100 
# define INFIXSIZE 100
//------------------>>>>Stack
int c = 0;

struct NodeSta* topS; 

struct NodeSta {
	int data;
	struct NodeSta *prev;
	struct NodeSta *next;
};

struct NodeSta* createStack() { 
    struct NodeSta* stack = (struct NodeSta*) malloc(sizeof(struct NodeSta)); 
    stack->data = 0;
    stack->prev = stack->next = NULL; 
    return stack; 
} 

bool isEmpty(struct NodeSta* head) { //IsEmpty
	return head == NULL;
}

struct NodeSta* getnode() {
	return (struct NodeSta*)malloc(sizeof(struct NodeSta));
};

struct NodeSta* pushS(struct NodeSta* node) {
	struct NodeSta* T;
  	if(node == NULL ) {
    	node = getnode();
    	T = topS = node;
    	T->prev = NULL;
  	}
  	else {  
    	T = getnode();
    	topS->next = T;   
    	T->prev = topS;
    	topS = T;
  	}
	printf("Enter a val\n"); 
	c++;
	scanf("%d", &T->data);
	T->next = NULL;
	return node;
}

struct NodeSta* popS(struct NodeSta* node) {
	struct NodeSta* tmp;
	if((node == NULL) && (c < 1)) {
	    printf("Underflow\n"); 
	    return node;
	}
	tmp = topS;
	printf("The deleted value is : %d\n", tmp->data);
	if(c != 1) {
	    topS = tmp->prev;
	    tmp->prev = NULL; 
	    topS->next = NULL;
	}
	else if(c == 1) {
	    node = NULL;
	}
	c--;
	return node;
}

 int stack[MAXSTACK];
 int top = -1 ;            
 void push(int item){

	 if(top >= MAXSTACK -1) {
		 printf("stack over flow");
		 return;
	 }
	 else {
		 top = top + 1 ;
		 stack[top]= item;
	 }
 }

 int pop() {
	 int item;
	 if(top <0) {
		printf("stack under flow");
	 }
	 else {
		 item = stack[top];
		 top = top - 1;
		 return item;
	 }
 }

//------------------>>>>Queue

struct QNode {
    char data; 
    struct QNode *next; 
    struct QNode *prev;
}; 
  
struct Queue {
    struct QNode *front, *rear; 
};

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

//------------------>>>>MainProgram

int Prec(char ch) { 
    switch (ch) { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '/': 
        return 2;  
    } 
    return -1; 
} 
  
bool isMatchingPair(char character1, char character2) { 
	if (character1 == '(' && character2 == ')') {
    	return 1; 
   	}
   	else {
     	return 0; 
   	}
} 

 void Evalinfix(char infix[]){
	int i ;
	char ch;
	int val;
	int A, B ;
	for (i = 0 ; infix[i] != ')'; i++){
		ch = infix[i];
		if (isdigit(ch)) {
			push(ch - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			A = pop();
			B = pop();
			switch (ch) {
				case '*':
					val = B * A;
					break;
				case '/':
					val = B / A;
					break;
				case '+':
					val = B + A;
					break;
				case '-':
					val = B - A;
					break;
			}
			push(val);
		}
	}
	printf( "Result of expression: %d \n", pop()) ;
}

int main()	{ 
  	int i ;
	char infix[INFIXSIZE];
	printf("Enter infix expression: ");
	for (i = 0 ; i <= INFIXSIZE - 1 ; i++) {
		scanf("%c", &infix[i]);
		if ( infix[i] == ')' ) { 
			break; 
		}
	}
	Evalinfix(infix);
	return 0;
}     