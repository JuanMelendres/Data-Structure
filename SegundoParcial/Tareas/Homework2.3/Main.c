/*

Juan Antonio Melendres Villa A00369017
comentarios: perdon profe, pero tuve muchos problemas con la lectura de los archivos me comia letras o me ponia las palabras de otra forma.

Create a program in C that performs the following operations
with linked lists, where the information field is a String:

 1. insert at the beginning (head, newData) **
 2. insert at the end (head, newData) **
 3. insert before (head, reference, newData) **
 4. insert after (head, reference, newData)  **
 5. insert n before (head, n, reference, newData) **
 6. insert n after (head, n, reference, newData) **
 7. delete at the beginning (head) **
 8. delete at the end (head) **
 9. delete before (head, reference) **
10. delete after (head, reference) **
11. delete n before (head, n, reference) **
12. delete n after (head, n, reference) **
13. print (head) **
14. print backwards (head) **
15. recursive print (head) **
16. recursive backwards print (head) **
17. search (head, data) **
18. search from last to first (head, data) **
19. recursive search (head, data) **
20. recursive search from last to first (head, data) **
21. ascending sort the elements (head) **
22. descending sort the elements (head) **
 0. quit **

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
	char* data;
    struct Node *next;
};

struct Node* createNode(char* info) { //Struct that creates new node
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

int getSize(struct Node* head) { //GetSize
	int size = 0;
	if(isEmpty(head)) {
    	return size;
  	}
  	else {
    	struct Node* tmp =  head;
    	while(tmp != NULL) {
      		size++;
      		tmp = tmp->next;
    	}
  	}
	return size;
}

int indexOf(struct Node* head, char* info) { //Index of a node
	int size = getSize(head);
	struct Node* current = head;  
	int index = 0;
	while (current != NULL) { 
        if (current->data == info) {
            return index; 
        }
        index++;
        current = current->next; 
    }
    return index;
}

struct Node* iatb(struct Node* head, char* info) { //Insert at the beginning
  	struct Node* newNode = createNode(info)
    //struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //newNode->next = NULL;
    //newNode->data = info;
  	if(isEmpty(head)) {
    	return newNode;
  	}
  	else {
    	newNode->next = head;
  	}
  	return newNode;
}

struct Node* iate(struct Node* head, char* info) { //Insert at the end
  	struct Node* newNode = createNode(info);
  	if(isEmpty(head)) {
    	return newNode;
  	}
  	else {
   		struct Node* tmp = head; //current = head;
   		while(hasNext(tmp)) { //currentNode->next != NULL
    		tmp = tmp->next;  //current = current->next;
   		}
   		tmp->next = newNode; //current->next = newNode;
  	}
	return head;
}

struct Node* inbf(struct Node* head, char* reference, char* info) { //Insert Before (head, reference, newData)
	struct Node *currentNode = head;
	struct Node *newNode;
	newNode = createNode(info);
	if (head == NULL) {  
       printf("the given previous node cannot be NULL");
    }
	while (currentNode->next->data != reference) {
		currentNode = currentNode->next;
	}
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return head;
}

struct Node* inaf(struct Node* head, char* reference, char* info) { //Insert after (head, reference, newData) 
	struct Node* currentNode = head;
	struct Node* newNode;
	newNode = createNode(info);   
	while (currentNode->data != reference) {
	    currentNode = currentNode->next;
	}
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return head;
}

struct Node* nodePos(struct Node* head, int position, char* info){
    struct Node* newNode = createNode(info);
    if (head == NULL) {
        return newNode;
    }
 
    if (position == 0) {
       return iate(head, info);
    }

    struct Node* currentNode = head;
    while (position - 1 > 0) {
        currentNode = currentNode->next;
        position--;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return head;
 }

struct Node* inNbf(struct Node* head, int n, char* reference, char* info) { //Insert n before (head, n, reference, newData)
	struct Node* currentNode = head;
	struct Node* newNode;
	newNode = createNode(info);
	if(isEmpty(head)) {
    	return newNode;
  	}
	else {
		int pos = indexOf(head, reference) - n;
		nodePos(head, pos, info);
	}
	return head;
}

struct Node* inNaf(struct Node* head, int n, char* reference, char* info) { //Insert n after (head, n, reference, newData)
	struct Node* currentNode = head;
	struct Node* newNode;
	newNode = createNode(info);
	if(isEmpty(head)) {
    	return newNode;
  	}
  	else {
		int pos = indexOf(head, reference) + n + 1;
		nodePos(head, pos, info);
	}
	return head;
}


struct Node* datb(struct Node* head) { //Delete at the beginning
	if(isEmpty(head)) {
	    return NULL;
	}
	else {
		head = head->next;
	 	free(head);
	}
	return head;
}

struct Node* date(struct Node* head){ //Delete at the end
	struct Node* tmp = head;
	struct Node* aux;
	if(head->next == NULL) {
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

struct Node* debef(struct Node* head, char* reference) { //Delete before (head, reference)
	struct Node* tmp = head;
	struct Node* aux;
	if(head->next == NULL) {
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

struct Node* deaft(struct Node* head, char* reference) { //Delete after (head, reference)
	struct Node* tmp = head;
	struct Node* aux;
	if(head->next == NULL) {
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

struct Node* nodeDel(struct Node* head, int index) {
	if (head == NULL) {
      	free(head);
   		head = NULL;
   	}
   	struct Node* temp = head;
    for (int i = 0; temp != NULL && i < index-1; i++) {
        temp = temp->next;
    }
    struct Node* aux = temp->next->next;
    free(temp->next);  
    temp->next = aux; 
    return head;
}

struct Node* deNbf(struct Node* head, int n, char* reference) { //Delete n before (head, n, reference)
	struct Node* tmp = head;
	struct Node* aux;
	if(head->next == NULL) {
    	free(head);
   		head = NULL;
  	}
	else {
		while(tmp->next->data != reference) {
        	aux = tmp;
        	tmp = tmp->next;
     	}	
		int pos = indexOf(head, reference) - n;
		nodeDel(head, pos);
     	aux->next = tmp->next;
	}
	return head;
}

struct Node* deNaf(struct Node* head, int n, char* reference) { //Delete n after (head, n, reference)
	struct Node* tmp = head;
	struct Node* aux;
	if(head->next == NULL) {
    	free(head);
   		head = NULL;
  	}
  	else {
  		while(tmp->data != reference) {
        	aux = tmp;
        	tmp = tmp->next;
     	}
		int pos = indexOf(head, reference) + n;
		nodeDel(head, pos);
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

void printBackwards(struct Node* head) { //Print backwards
	struct Node* current = head;
	if(isEmpty(head)) {
		printf("Empty");
	}
    while (current != NULL) { 
        printf("%s -> ", current->data); 
        current = current->next; 
    }
    printf("Null\n");
}

void recursivePrint(struct Node* head) { //Recursive print
    if (head == NULL) {
        return; 
    } 
    else {
    	recursivePrint(head->next);
        printf("%s -> ", head->data);
    }
}

void recursivePrintBackwards(struct Node* head) { //Recursive print backwards   
    if (head == NULL) {
       return; 
    } 
    recursivePrintBackwards(head->next); 
    printf("%s -> ", head->data); 
}

struct Node* reverse_recursive(struct Node* head) {
 	if (head == NULL || head->next == NULL) {
		return head;
  	}
 	struct Node* reversed_list = reverse_recursive(head->next);
  	head->next->next = head;
  	head->next = NULL;
  	return reversed_list;
}

struct Node* search(struct Node* head, char* info) { //Search (head, data)
    struct Node* current = head;  
    while (current != NULL) { 
        if (current->data == info) {
            return current; 
        }
        current = current->next; 
    } 
    return NULL; 
}

struct Node* middle(struct Node* start, struct Node* last){ 
    if (start == NULL) {
        return NULL; 
    }
    struct Node* slow = start; 
    struct Node* fast = start -> next; 
    while (fast != last) { 
        fast = fast -> next; 
        if (fast != last) { 
            slow = slow -> next; 
            fast = fast -> next; 
        } 
    } 
    return slow; 
} 

bool SearchLaToFi(struct Node* head, char* info) { //search from last to first (head, data)
    struct Node* start = head; 
    struct Node* last = NULL; 
    do { 
        // Find middle 
        struct Node* mid = middle(start, last); 
        // If middle is empty 
        if (mid == NULL) {
            return NULL; 
        }
        // If value is present at middle 
        if (mid->data == info) {
            return mid; 
        }
        // If value is more than mid 
        else if (mid->data != info) {
            start = mid->next; 
        }
        // If the value is less than mid. 
        else {
            last = mid; 
        }
    } 
    while (last == NULL || last -> next != start); 
    return NULL;
}

struct Node* recursiveSearch(struct Node* head, char* info) { //Recursive Search
    if (head == NULL) {
        return NULL; 
    } 
    if (head->data == info) {
        return head; 
    }
    return search(head->next, info); 
}

struct Node* recursiveSearchLaToFi(struct Node* head, char* info) { //recursive search from last to first (head, data)
    if (head == NULL) {
        return NULL; 
    } 
    if (head->data == info) {
        return head; 
    }
    return search(head->next, info); 
}

void swap(struct Node* a, struct Node* b) { //function to swap data of two nodes a and b
    char* temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void bubbleSort(struct Node* start) { //Bubble sort the given linked list
    int swapped; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
    if (start == NULL) {
        return; 
    }
    do { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) { 
            if (ptr1->data > ptr1->next->data) {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

struct Node* insertion_sort(struct Node* head) {
  struct Node *x, *y, *e;
  x = head;
  head = NULL;
  while(x != NULL){
    e = x;
    x = x->next;
    if (head != NULL) {
      if(e->data > head->data) {
        y = head;
        while ((y->next != NULL) && (e->data> y->next->data)) {
          y = y->next;
        }
        e->next = y->next;
        y->next = e;
      }
      else {
        e->next = head;
        head = e ;
      }
    }
    else {
      e->next = NULL;
      head = e ;
    }
  }
  return head;
}

int main(int argc, char const *argv[]) {
  struct Node* head = NULL;
  struct Node* tmp = NULL;
 	// char data;
 	// char ref;
 	// int n, opcion;
 	// while (opcion <= 22) {
  //       printf( "\n 1. insert at the beginning (newData) ");
  //       printf( "\n 2. insert at the end (newData) ");
  //       printf( "\n 3. insert before (reference, newData) ");
  //       printf( "\n 4. insert after (reference, newData) ");
  //       printf( "\n 5. insert n before (n, reference, newData) ");
  //       printf( "\n 6. insert n after (head, n, reference, newData) ");
  //       printf( "\n 7. delete at the beginning ");
  //       printf( "\n 8. delete at the end ");
  //       printf( "\n 9. delete before (reference) ");
  //       printf( "\n 10. delete after (reference) ");
  //       printf( "\n 11 .delete n before (n, reference)");
  //       printf( "\n 12. delete n after (n, reference)");
  //       printf( "\n 13. print ");
  //       printf( "\n 14. print backwards ");
  //       printf( "\n 15. recursive print ");
  //       printf( "\n 16. recursive backwards print");
  //       printf( "\n 17. search (data)");
  //       printf( "\n 18. search from last to first (data)");
  //       printf( "\n 19. recursive search (data)");
  //       printf( "\n 20. recursive search from last to first (data)");
  //       printf( "\n 21. ascending sort the elements ");
  //       printf( "\n 22. descending sort the elements ");
  //       printf( "\n 0. Quit." );
  //       printf( "\n Option (0-22): \n");
  //       scanf("%d", &opcion);
  //       if(opcion == 0) {
  //        	exit(0);
		// }
  //       switch (opcion) {
  //           case 1: 
  //               printf("Insert at the beginning (newData): \n");
  //       		scanf("%s", &data);
  //       		head = iatb(head, &data);
  //           case 2:
  //           	printf("Insert at the end (newData): \n");
  //            	scanf("%c", &data);
  //               head = iate(head, &data); 
  //           case 3: 
  //           	printf("Insert before (reference, newData): \n");
  //            	scanf("%c %c", &ref, &data);
  //               head = inbf(head, &ref, &data);
  //           case 4: 
  //           	printf("Insert after (reference, newData): \n");
  //            	scanf("%c %c", &ref, &data);
  //               head = inaf(head, &ref, &data);
  //           case 5: 
  //           	printf("Insert n before (n, reference, newData) ");
  //            	scanf("%d %c %c", &n, &ref, &data);
  //               head = inNbf(head, n, &ref, &data);
  //           case 6:
  //           	printf("Insert n after (head, n, reference, newData) \n");
  //            	scanf("%d %c %c", &n, &ref, &data);
  //               head = inNaf(head, n, &ref, &data);
  //           case 7:
  //           	printf("Delete at the beginning \n");
  //               head = datb(head);
  //           case 8:
  //           	printf("Delete at the end \n"); 
  //               head = date(head);
  //           case 9: 
  //           	printf("Delete before (reference) \n");
  //            	scanf("%c", &ref);
  //               head = debef(head, &ref);
  //           case 10: 
  //           	printf("Delete after (reference) \n");
  //            	scanf("%c", &ref);
  //               head = deaft(head, &ref);
  //           case 11:
  //           	printf("Delete n before (n, reference) \n"); 
  //            	scanf("%d %c", &n, &ref);
  //               head = deNbf(head, n, &ref);
  //           case 12:
  //           	printf("Delete n after (n, reference) \n"); 
  //            	scanf("%d %c", &n, &ref);
  //               head = deNaf(head, n, &ref);
  //           case 13:
  //           	//printf( "Print \n");
  //            	print(head);
  //           case 14:
  //           	//printf( "Print backwards \n");
  //            	printBackwards(head);
  //           case 15:
  //           	//printf( "Recursive print \n");
  //            	recursivePrint(head);
  //           case 16:
  //           	//printf( "Recursive backwards print \n");
  //            	recursivePrintBackwards(head);
  //           case 17: 
  //           	printf("Search (data) \n");
  //           	scanf("%c", &data);
  //            	head = search(head, &data),
  //           case 18:
  //           	printf("Search from last to first (data) \n"); 
  //            	scanf("%c ", &data);
  //            	if (SearchLaToFi(head, &data)) {
  //            		printf("%c\n", data);
  //            	}
  //               else {
  //               	printf("The element is not in the list\n");
  //               }
  //           case 19: 
  //           	printf("Recursive search (data) \n");
  //            	scanf("%c ", &data);
  //            	head = recursiveSearch(head, &data);
  //           case 20:
  //           	printf("Recursive search from last to first (data) \n"); 
  //            	scanf("%c", &data);
  //               head = recursiveSearchLaToFi(head, &data);
  //           case 21:
  //           	printf("Ascending sort the elements \n");
  //           	bubbleSort(head);
  //           case 22:
  //           	printf("Descending sort the elements \n");
  //            	head = insertion_sort(head);
  //           default:
  //      			printf( "\n Wrong input \n");
  //       }
  //}
	return 0;
}