#include<stdio.h>
#include<stdlib.h>
  
struct BSTnode {
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};

typedef struct {
    int front, rear, size;
    unsigned capacity;
    struct BSTnode* arr[100];
} Queue;

Queue* createQ(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->capacity = 100;
    q->front = q->size = 0; 
    q->rear = q->capacity - 1;
    return q;
}

int isEmpty(Queue* q) {  
    return (q->size == 0); 
}

int isFull(Queue* q) {  
    return (q->size == q->capacity);  
}

void enqueue(Queue* q, struct BSTnode* item) {
    if (isFull(q)){
        return;
    }
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = item;
    q->size = q->size + 1;
 }


struct BSTnode* dequeue(Queue* q) {
    if (isEmpty(q)){
        return NULL;
    }
    struct BSTnode* item = q->arr[q->front];
    q->front = (q->front + 1)%q->capacity;
    q->size = q->size - 1;
    return item;
}

struct BSTnode* createNode(value) {
    struct BSTnode* newNode = malloc(sizeof(struct BSTnode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
  
struct BSTnode* insert(struct BSTnode* root, int data){
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left  = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);   
    }
    return root;
}

struct BSTnode* minValueNode(struct BSTnode* node) { 
    struct BSTnode* current = node; 
    while (current->left != NULL) {
        current = current->left; 
    }
    return current; 
} 

void preorder(struct BSTnode* node) { 
    if (node == NULL) {
        return; 
    }
    printf("%d ->", node->data);   
    preorder(node->left);   
    preorder(node->right); 
} 

void inorder(struct BSTnode* node) { 
    if (node == NULL) {
        return; 
    }
    inorder(node->left); 
    printf("%d ->", node->data);   
    inorder(node->right); 
} 

void postorder(struct BSTnode* node) { 
    if (node == NULL) {
        return; 
    }     
    postorder(node->left); 
    postorder(node->right); 
    printf("%d ->", node->data); 
}

void levelorder(struct BSTnode* root) {
    if(root == NULL) {
        return;
    }
    else {
        Queue* q = createQ();
        enqueue(q,root);
        while(!isEmpty(q)) {
            struct BSTnode* temp = dequeue(q);
            printf("%d ",temp->data);
            if(temp->right) {
                enqueue(q,temp->right);
            }
            if(temp->left) {
                enqueue(q,temp->left);
            }
        }
    }
}

int main(){ 
    int n, num;
    struct BSTnode *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        root = insert(root, num);
    }
    printf("Preorder \n");
    preorder(root);
    printf(" NULL \n");
    printf("Inorder \n");
    inorder(root);
    printf(" NULL \n");
    printf("Posorder \n");
    postorder(root);
    printf(" NULL \n");
    printf("Levelorder \n");
    levelorder(root);
    printf(" NULL \n");
}