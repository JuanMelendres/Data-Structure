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

struct Node* insertAtHead(struct Node* head, char* info) {
	struct Node* tmp = createNode(info);
	if (isEmpty(head)) {
		return tmp;
	}
	else {
		tmp->next = head;
	}
	return tmp;
}

struct Node* insertAtEnd(struct Node* head, char* info) {
	struct Node* tmp = createNode(info);
	if (isEmpty(head)) {
		return tmp;
	}
	else {
		struct Node* aux = head;
		while(hasNext(aux)){
			aux = aux->next;
		}
		aux->next = tmp;
	}
	return head;
}

struct Node* insertBefore(struct Node* head, char* reference, char* info) {
	struct Node* current = head;
	struct Node* tmp;
	tmp = createNode(info);
	if (head == NULL) {
		return NULL;
	}
	while(current->next->data != reference) {
		current = current->next;
	}
	tmp->next = current->next;
	current->next = tmp;
	return head;
}

struct Node* insertAfter(struct Node* head, char* reference, char* info) {
	struct Node* current = head;
	struct Node* tmp;
	tmp = createNode(info);
	while(current->data != reference) {
		current = current->next;
	}
	tmp->next = current->next;
	current->next = tmp;
	return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
	if (isEmpty(head)){
		return NULL;
	}
	else {
		head = head->next;
		free(head);
	}
	return head;
}

struct Node* deleteAtEnd(struct Node* head) {
	struct Node* tmp = head;
	struct Node* aux;
	if (head->next == NULL)	{
		free(head);
		head = NULL;
	}
	else {
		while(tmp->next != NULL) {
			aux = tmp;
			tmp = tmp->next;
		}
		free(aux->next);
		aux->next = NULL;
	}
	return head;
}

struct Node* deleteBefore(struct Node* head, char* reference) {
	struct Node* tmp = head;
	struct Node* aux;
	if (head->next == NULL)	{
		free(head);
		head = NULL;
	}
	else {
		while(tmp->next->data != reference) {
			aux = tmp;
			tmp = tmp->next;
		}
		free(aux->next);
		aux->next = tmp->next;
	}
	return head;
}

struct Node* deleteAfter(struct Node* head, char* reference) {
	struct Node* tmp = head;
	struct Node* aux;
	if (head->next == NULL) {
		free(head);
		head = NULL;
	}
	else {
		while(tmp->data != reference) {
			aux = tmp;
			tmp = tmp->next;
		}
		free(aux->next);
		aux->next->next = tmp->next->next;
	}
	return head;
}

void printNode(struct Node* head) { //Print node
	if(head == NULL) {
		printf("NULL\n");
  	} 
  	else{
    	printf("%s -> ", head->data);    
  	}
}

void print(struct Node* head) { //Print list
	if(isEmpty(head)) {
		printf("Empty");
	}
  	struct Node* temp = head;
  	while(temp != NULL) {
    	printNode(temp);
    	temp = temp->next;
  	}
  	printf("Null\n");
}

int main(int argc, char const *argv[]) {
	struct Node* List = insertAtHead(List, "Karen");
	List = insertAtHead(List, "Juan");
 	List = insertAtHead(List, "Arturo");
 	List = insertAtHead(List, "Ximena");
 	List = insertAtHead(List, "Alicia");
 	List = insertAtEnd(List, "Mandis");
 	List = insertBefore(List, "Alicia", "Arturo");
	List = insertAfter(List, "Ximena", "Huevito");
	print(List);
	printf("_______________________________\n");
 	List = deleteAtBeginning(List);
 	//List = deleteAtEnd(List);
 	//List = deleteBefore(List, "Arturo");
 	//List = deleteAfter(List, "Karen");
	print(List);
	return 0;
}	