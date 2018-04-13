#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
	int data;
	struct element* next;
};
typedef struct element* Elem;

struct linklist{
	int lcnt;
	Elem head;
};
typedef struct linklist Linklist;

struct graph{
	int vcnt;
	Linklist* adjlist;
};
typedef struct graph* Graph;

struct vertex{
	int val;
	int degree;
};

Linklist addelem(Linklist ll, int v);

Graph readfile(char* flname, Graph G);

Graph creategraph(int numV);
Linklist getAdj(Graph G, int v);
Graph addedge(Graph G, int u, int v);
int degree(Graph G, int v);
void DFS(Graph g);
