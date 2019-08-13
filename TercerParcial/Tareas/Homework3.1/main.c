/*
Juan Antonio Melendres Villa
Write a program in C that reads a number n followed by nxn values

the first number indicates the number of nodes that a graph contains
the following nxn values represents the weight of the edges from node i to node j
if there is no edge betwen node i and node j, the value in the matrix is a "-1"

a) Build the adjacency matrix and display it.
b) Build the Edge list and display it
c) Buid a list (of lists) and display the adjacent nodes of each node

It also outputs the
BFS :
a list beginning in every node,
and
DFS :
a list beginning in every node

and displays the result of the Dijkstra and Floyd Algorithms



Sample input:

    4
    -1  2 -1  3
    -1 -1  1  5
     2  3 -1 -1
     3 -1  4 -1

Sample output:

Adjacency matrix:
      
             0  1  2  3
          +------------
        0 | -1  2 -1  3
        1 | -1 -1  1  5
        2 |  2  3 -1 -1
        3 |  3 -1  4 -1

 Edge list :

        Edge 0 connects node 0 with node 1 with a weight 2
        Edge 1 connects node 0 with node 3 with a weight 3
        Edge 2 connects node 1 with node 2 with a weight 1
        Edge 3 connects node 1 with node 3 with a weight 5
        Edge 4 connects node 2 with node 0 with a weight 2
        Edge 5 connects node 2 with node 1 with a weight 3
        Edge 6 connects node 3 with node 0 with a weight 3
        Edge 7 connects node 3 with node 2 with a weight 4


    Adjacency list :

        Node 0 connects with node 1(weight: 2)
        Node 0 connects with node 3(weight: 3)
        Node 1 connects with node 2(weight: 1)
        Node 1 connects with node 3(weight: 5)
        Node 2 connects with node 0(weight: 2)
        Node 2 connects with node 1(weight: 3)
        Node 3 connects with node 0(weight: 3)
        Node 3 connects with node 2(weight: 4)


Dijkstra :
From node 1 to node 2 : dist1
From node 1 to node 3 : dist2
...
From node n to node n-1 : distx

Floyd:

Adjacency matrix:

Routes matrix:



Due date:

Tuesday Nov 20, 11:20 hrs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 6

struct Graph {
	struct Node* head[N];
};

struct Node {
	int src, dest, weight;
	struct Node* next;
};

struct Edge {
	int src, dest, weight;
	bool visited;
};

struct Graph* createGraph(struct Edge edges[], int n) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	for (int i = 0; i < N; i++) {
		graph->head[i] = NULL;
	}
	for (int i = 0; i < n; i++) {
		int src = edges[i].src;
		int dest = edges[i].dest;
        int weight = edges[i].weight;
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->src = src;
		newNode->dest = dest;
		newNode->weight = weight;
		newNode->next = graph->head[src];
		graph->head[src] = newNode;
	}
	return graph;
}

void printAdjacencyMatrix(struct Graph* graph, int n){
	printf("Adjacency matrix:\n");
	printf("\t    ");
	for (int i = 0; i < n; ++i) {
		printf("\t%.1d ", i);
	}
	printf("\n");
	printf("\t  +--");
	for (int i = 0; i < n; ++i) {
		printf("-------");
	}
	printf("\n");
	for (int i = 0; i < n; ++i){
		struct Node* ptr = graph->head[i];
		printf("\t%.1d| ", i);
		while (ptr != NULL) {
			printf("\t%.1d", ptr->weight);
			ptr = ptr->next;
		}
		printf("\n");
	}
	printf("\n");
}

void edgeList(struct Graph* graph, int numEdge){
	printf("Edge list :\n");
	for (int i = 0; i < N; i++) {
		struct Node* ptr = graph->head[i];
		while (ptr != NULL) {
			if (ptr->weight != -1){
				printf("Edge %d connects node %d with node %d with a weight %d \n", i, ptr->src, ptr->dest, ptr->weight);
			}
			ptr = ptr->next;
		}
	}
	printf("\n");
}

void printAdjacencyList(struct Graph* graph) {
	printf("Adjacency List :\n");
	for (int i = 0; i < N; i++) {
		struct Node* ptr = graph->head[i];
		while (ptr != NULL) {
			if (ptr->weight != -1){
				printf("Node %d connects with node %d (weight: %d)\n", i, ptr->dest, ptr->weight);
			}
			ptr = ptr->next;
		}
	}
	printf("\n");
}

int main(void) {
	struct Edge edges[] =
	{
		{ 0, 0, -1 }, { 0, 1, 2 }, { 0, 2, -1 }, { 0, 3, 3 },
		{ 1, 0, -1 }, { 1, 1, -1 }, { 1, 2, 1 }, { 1, 3, 5 },
		{ 2, 0, 2 }, { 1, 1, 3 }, { 2, 2, -1 }, { 2, 3, -1 },
		{ 3, 0, 3 }, { 3, 1, -1 }, { 3, 2, 4 }, { 3, 3, -1 }
	};
	int n = sizeof(edges)/sizeof(edges[0]);
	struct Graph *graph = createGraph(edges, n);
	printAdjacencyMatrix(graph, 4);
	edgeList(graph, n);
	printAdjacencyList(graph);
	return 0;
}