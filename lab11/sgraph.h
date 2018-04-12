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

Edgelist readfile(char* filename, Edgelist list);
Verlist convert(Edgelist olist, Edgelist newlist);
