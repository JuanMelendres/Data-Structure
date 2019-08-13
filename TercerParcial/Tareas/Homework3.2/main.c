/*
Juan Antonio Melendres Villa A00369017
Comentarios: Los datos se ingresan de la siguiente manera
            ejemplo:    11
                        50
                        45
                        55
                        40
                        60
                        35
                        65
                        30
                        70
                        25
                        75
                    Preorder: 
                     50|B,  40|R,  30|B,  25|R,  35|R,  45|B,  60|R,  55|B,  70|B,  65|R,  75|R, 
                    Inorder: 
                     25|R,  30|B,  35|R,  40|R,  45|B,  50|B,  55|B,  60|R,  65|R,  70|B,  75|R, 
                    Postorder: 
                     25|R,  35|R,  30|B,  45|B,  40|R,  55|B,  65|R,  75|R,  70|B,  60|R,  50|B, 
 */
#include <stdio.h>
#include <stdlib.h>

struct rbtNode {
    int key;    
    char color;
    struct rbtNode *left, *right,*parent;
}; struct rbtNode* root = NULL;

void leftRotate(struct rbtNode *x) {
    struct rbtNode *y;
    y = x->right;  
    x->right = y->left;
    if( y->left != NULL) {          
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL) {          
    root = y;
    }
    else if( (x->parent->left != NULL) && (x->key == x->parent->left->key)) {          
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x; 
    x->parent = y; 
    return;
}

void rightRotate(struct rbtNode *y) {          
    struct rbtNode *x;
    x = y->left; 
    y->left = x->right;
    if ( x->right != NULL) {          
        x->right->parent = y;
    }
    x->parent = y->parent;
    if( y->parent == NULL) {          
        root = x;
    }
    else if((y->parent->left != NULL)&& (y->key == y->parent->left->key)) {          
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y; 
    y->parent = x;  
    return;
}

int search(int val) {          
    struct rbtNode* temp = root;
    int diff;
    while (temp != NULL) {          
        diff = val - temp->key;
        if (diff > 0) {          
            temp = temp->right;
        }
        else if (diff < 0) {          
            temp = temp->left;
        }
        else {          
            printf("Element Found!!\n");
        return 1;
        }

    }          
    return 0;
}

void colorInsert(struct rbtNode *z) {          
    struct rbtNode *y = NULL;
    while ((z->parent != NULL) && (z->parent->color == 'R')) {
        if ( (z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key)) {          
            if(z->parent->parent->right != NULL) {
                y = z->parent->parent->right;
            }
            if ((y != NULL) && (y->color == 'R')) {          
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                if(z->parent->parent != NULL) {
                    z = z->parent->parent;
                }
            }
            else {
                if ((z->parent->right != NULL) && (z->key == z->parent->right->key)) {          
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(z->parent->parent);
            }
        }
        else {
            if(z->parent->parent->left != NULL) {
                y = z->parent->parent->left;
            }
            if((y != NULL) && (y->color == 'R')) {          
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                if(z->parent->parent != NULL) {
                    z = z->parent->parent;
                }
            }
            else {
                if ((z->parent->left != NULL) && (z->key == z->parent->left->key)) {          
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(z->parent->parent);
            }
        }
    }          
    root->color = 'B';
}

void insert(int val) {          
    struct rbtNode *x, *y;
    struct rbtNode *z = (struct rbtNode*)malloc(sizeof(struct rbtNode));
    z->key = val;
    z->left = NULL;
    z->right = NULL;
    z->color = 'R';
    x = root;
    if(search(val) == 1) {          
        printf("\nEntered element exists in the tree\n");
        return;
    }
    if (root == NULL) {          
        root = z;
        root->color = 'B';
        return;
    }
    while (x != NULL) {          
        y = x;
        if (z->key < x->key) {          
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL) {          
        root = z;
    }
    else if(z->key < y->key) {          
        y->left = z;
    }
    else {
        y->right = z;
    }
    colorInsert(z);
    return;
}

void preOrder(struct rbtNode* root) { 
    struct rbtNode* temp = root;
    if(temp != NULL) { 
        printf(" %d|%c, ",temp->key,temp->color);
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

void inOrder(struct rbtNode* root) {          
    struct rbtNode* temp = root;
    if (temp != NULL) {          
        inOrder(temp->left);
        printf(" %d|%c, ",temp->key,temp->color);
        inOrder(temp->right);
    }
    return;
}

void postOrder(struct rbtNode* root) {          
    struct rbtNode* temp = root;
    if (temp != NULL) {          
        postOrder(temp->left);  
        postOrder(temp->right);
        printf(" %d|%c, ",temp->key,temp->color);
    }
    return;
}

void traversal(struct rbtNode* root) {          
    if (root != NULL) {          
        printf("\nPreorder: ");
        printf("\n");
        preOrder(root);
        printf("\nInorder: ");
        printf("\n");
        inOrder(root);
        printf("\nPostorder: ");
        printf("\n");
        postOrder(root);
    }
    return;
}

struct rbtNode* min(struct rbtNode *x) {          
    while (x->left) {          
        x = x->left;
    } 
    return x;
}

struct rbtNode* successor(struct rbtNode *x) {          
    struct rbtNode *y;
    if (x->right) {          
        return min(x->right);
    }          
    y = x->parent;
    while (y && x == y->right) {          
        x = y;
        y = y->parent;
    }
    return y;
}

void colorDelete(struct rbtNode *x) {          
    while (x != root && x->color == 'B') {          
        struct rbtNode *w = NULL;
        if ((x->parent->left != NULL) && (x == x->parent->left)) {          
            w = x->parent->right;
            if ((w != NULL) && (w->color == 'R')) {          
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w != NULL) && (w->right != NULL) && (w->left != NULL) && (w->left->color == 'B') && (w->right->color == 'B')) {
                w->color = 'R';
                x = x->parent;
            }
            else if((w != NULL) && (w->right->color == 'B')) {          
                w->left->color = 'B';
                w->color = 'R';
                rightRotate(w);
                w = x->parent->right;
            }
            if(w != NULL) {          
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B'; 
                leftRotate(x->parent);
                x = root;
            }
        }
        else if(x->parent != NULL) {          
            w = x->parent->left;
            if ((w != NULL) && (w->color == 'R')) {
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(x->parent);
                if(x->parent != NULL) {
                    w = x->parent->left;
                }
            }
            if ((w != NULL) && (w->right != NULL) && (w->left != NULL) && (w->right->color == 'B') && (w->left->color == 'B')) {
                x = x->parent;
            }
            else if((w != NULL) && (w->right != NULL) && (w->left != NULL) && (w->left->color == 'B')) {
                w->right->color = 'B';
                w->color = 'R';
                rightRotate(w);
                w = x->parent->left;
            }
            if(x->parent != NULL) {          
                w->color = x->parent->color;
                x->parent->color = 'B';
            }
            if(w->left != NULL) {
                w->left->color = 'B';
            }
            if(x->parent != NULL) {
                leftRotate(x->parent);
                x = root;
            }
        }
    } 
    x->color = 'B';
}

struct rbtNode* delete(int var) {          
    struct rbtNode *x = NULL, *y = NULL, *z;
    z = root;
    if((z->left == NULL ) &&(z->right == NULL) && (z->key == var)) {          
        root = NULL;
        printf("\nRBTREE is empty\n");
    }
    while(z->key !=var && z != NULL) {          
        if(var< z->key)  {
            z = z->left;
        }
        else {
            z = z->right;
        }
        if(z == NULL) {

        }
    }
    if((z->left == NULL)||(z->right == NULL)) {          
        y = z;
    }
    else {          
        y = successor(z);
    }
    if (y->left != NULL) {          
        x = y->left;
    }
    else {          
        if(y->right != NULL) {
            x = y->right;
        }
    }
    if((x!= NULL) && (y->parent != NULL)) {
        x->parent = y->parent;
    }
    if ((y != NULL) && (x != NULL) && (y->parent == NULL)) {          
        root=x;
    }
    else if (y == y->parent->left) {          
        y->parent->left = x;
    }
    else {          
        y->parent->right = x;
    }
    if (y != z) {          
        z->key = y->key;

    }
    if ((y != NULL) && (x != NULL) && (y->color == 'B')) {          
        colorDelete(x);
    }
    return y;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int data[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }
    for (int i = 0; i < n; ++i) {
        insert(data[i]);
    }
    traversal(root);
    printf("\n");
    return 0;
}