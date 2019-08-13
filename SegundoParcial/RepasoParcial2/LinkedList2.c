#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	char* data;
	struct Node *next;
};

struct Node* createNode(char* info) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->next = NULL;
	node->data = info;
	return node;
}

bool isEmpty(struct Node* head) { //IsEmpty
	return head == NULL;
}

bool hasNext(struct Node* head) { //Next element
  return head->next != NULL;
}

char* getData(struct Node* head) { //Data of the node
	return head->data;
}

struct Node* insertHead(struct Node* head, char* info){
	struct Node* tmp = createNode(info);
	if ()
	{
		/* code */
	}
}