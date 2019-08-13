/*
Juan Antonio Melendres Villa A00369017
comentarios: El programa solo recibe expresiones en prefix 
    ejemplo:
        expression in prefix form:
        3 
        *+253
        -+354
        +*423

        1.
        Prefix: *+253
        Infix: 2+5*3
        postfix: 25+3*
        Result: 21

        2.
        Underflow
        Prefix: -+354
        Infix: 3+5-4
        postfix: 35+4-
        Result: 4

        3.
        Prefix: +*423
        Infix: 4*2+3
        postfix: 42*3+
        Result: 11
<------------------------------------------------------------------->
Write a program in C that reads an integer n followed by n lines
each line contains a mathematical expression that can be written in prefix, infix or postfix notation
for each expression, build a binary tree that represents that expression and write the prefix, infix and postfix notations and the result of that expression

sample input:

3
((2+5)*3)
3 5 + 4 -
+ * 4 2 3

sample output:

1.
prefix: * + 2 5 3
infix: ((2+5)*3)
postfix: 2 5 + 3 *
result: 21

2.
prefix: - + 3 5 4
infix: ((3+5)-4)
postfix: 3 5 + 4 -
result: 4

3.
prefix: + * 4 2 3
infix: ((4*2)+3)
postfix: 4 2 * 3 +
result: 11
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//TreeNode
struct TreeNode {
    char data;
    struct TreeNode *left,*right;
};

struct TreeNode* createTree(char data) {
    struct TreeNode* nodes = (struct TreeNode*) malloc(sizeof(struct TreeNode)); 
    nodes->data = data;  
    nodes->left = NULL;
    nodes->right = NULL;
    return nodes;
}

//StackNode
struct StackNode {
   struct TreeNode *treeNode;
   struct StackNode *next;
};

struct TreeNode *node;
struct StackNode *next;

struct StackNode* createStack(struct TreeNode* a) {
    struct StackNode* node = (struct StackNode*) malloc(sizeof(struct StackNode));
    node->treeNode = a;
    node->next = NULL;
    return node;
}

struct StackNode* top = NULL;

void clear() {
    top = NULL;
}

//function to push a node
void push(struct TreeNode* ptr) {
    if (top == NULL)
        top = createStack(ptr);
    else {
        struct StackNode* nptr = createStack(ptr);
        nptr->next = top;
        top = nptr;
    }
}

//function to pop a node
struct TreeNode* pop() {
    if (top == NULL) {
        printf("Underflow\n");
    }
    else {
        struct TreeNode* ptr = top->treeNode;
        top = top->next;
        return ptr;
    }
    return 0;
}

//function to get top node
struct TreeNode* peek() {
    return top->treeNode;
}

//function to check if digit
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

//function to check if operator 
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

//function to convert character to digit
int toDigit(char ch) {
    return ch - '0';
}

//function to insert character
void insert(char val) {
    if (isDigit(val)) {
        struct TreeNode* nptr = createTree(val);
        push(nptr);
    }
    else if (isOperator(val)) {
        struct TreeNode *nptr = createTree(val);
        nptr->left = pop();
        nptr->right = pop();
        push(nptr);
    }
}

//function to build Binary Search Tree from input
void buildTree(char* eqn) {
    for (int i = sizeof(eqn) - 1; i >= 0; i--) {
        insert(eqn[i]);
    }
}

//function to evaluate tree
int evaluateTree(struct TreeNode* ptr) {
    if (ptr->left == NULL && ptr->right == NULL) {
        return toDigit(ptr->data);
    }
    else {
        int res = 0;
        int left = evaluateTree(ptr->left);
        int right = evaluateTree(ptr->right);
        char op = ptr->data;
        switch (op) {
            case '+': 
                res = left + right; 
                break;
            case '-':   
                res = left - right; 
                break;
            case '*': 
                res = left * right; 
                break;
            case '/': 
                res = left / right; 
                break;
            default: 
                res = left + right; 
                break;
        }
        return res;
    }
}

//function to evaluate tree
int evaluate() {
    return evaluateTree(peek());
}

//preOrder
void preOrder(struct TreeNode* node) {
    if (node == NULL) {
        return; 
    }
    printf("%c", node->data);   
    preOrder(node->left);   
    preOrder(node->right); 
} 

//inOrder
void inOrder(struct TreeNode* node) {
    if (node == NULL) {
        return; 
    }
    inOrder(node->left); 
    printf("%c", node->data);   
    inOrder(node->right); 
} 

//postOrder
void postOrder(struct TreeNode* node) {
    if (node == NULL) {
        return; 
    }     
    postOrder(node->left); 
    postOrder(node->right); 
    printf("%c", node->data); 
}

int main(){
    int n;
    scanf("%d", &n);
    char word[100][50];
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d.\n", i+1);
        buildTree(word[i]);
        printf("Prefix: ");
        preOrder(peek());
        printf("\n");
        printf("Infix: ");
        inOrder(peek());
        printf("\n");
        printf("postfix: ");
        postOrder(peek());
        printf("\n");
        printf("Result: %d\n", evaluate());
        printf("\n");
    }
    return 0;
}