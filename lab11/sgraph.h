#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int val;
};
typedef struct node Node;


struct edge{
	int u;
	int v;
};
typedef struct edge Edge;
//according to index

struct edgelist{
	int edgecnt;
	Edge* edges;
};
typedef struct edgelist Edgelist;


struct verlist{
	int vcnt;
	Node* varr;
};
typedef struct verlist Verlist;

struct element{
	int data;
	struct element* next;
};
typedef struct element* Elem;

struct que{
	int qcnt;
	Elem front, rear;
};
typedef struct que* Que;

struct linklist{
	int lcnt;
	Elem head;
};
typedef struct linklist* Linklist;

// Queue functions
Que enque(Que q, int vel);
Elem deque(Que q);

// LL functions
Linklist addelem(Linklist ll, int val);

Edgelist readfile(char* filename, Edgelist list);
int findnode(Verlist vers, int val);
int addver(Verlist *vers, int val);
Verlist convert(Edgelist olist, Edgelist *newlist);
Linklist topsort(Edgelist list, Verlist vers);
