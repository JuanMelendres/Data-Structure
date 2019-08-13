#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *tmp;
int size = 0;

bool isEmpty() {
   return head == NULL;
}

bool search(int key, struct Node * node) {
    while (node != NULL) {
        if (node->data == key) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void iatb(int newdata, struct Node ** pointerToHead) { //insertAtBeginnig
	struct Node *tmp;
	tmp = malloc(sizeof(struct Node));
	size++;
	tmp->data = newdata;
	tmp->next = *pointerToHead;
	*pointerToHead = tmp;
}

void printList(struct Node * node) { 
	while (node != NULL) { 
    	printf("|%d| ->", node->data);  //printf("%d\n", node->data); para imprimir node por node
    	node = node->next; 
	}
	printf(" Null\n");
} 

int main(int argc, char const *argv[]) {
	//first node
	tmp = malloc(sizeof(struct Node));
	tmp->data = 8;
	tmp->next = NULL;
	head = tmp;
	//adding new nodes at the beginning
	iatb(9, &head);
	iatb(5, &head);
	iatb(3, &head);

	printf("Created Linked list is: \n"); 
	printList(head);
	if (search(8, head)){
		printf("8 is in the Linked List. \n"); 
	}
	else {
		printf("8 isn't in the Linked List. \n"); 
	}
	if (isEmpty()){
		printf("Linked List is empty.\n"); 
	}
	else {
		printf("Linked List not is empty.\n"); 
	}

	return 0;
}

	//second node
	// tmp = malloc(sizeof(struct node));
	// tmp->data = 9;
	// tmp->next = head;
	// head = tmp;
	// // printf("%d\n", head->data);
	// // printf("%d\n", head->next->data);
	//third node
	// tmp = malloc(sizeof(struct node));
	// tmp->data = 5;
	// tmp->next = head;
	// head = tmp;
	// printf("%d\n", head->data);
	// printf("%d\n", head->next->data);
	// printf("%d\n", head->next->next->data);