#include <stdlib.h>
#include <stdio.h>

typedef struct node* Node;
struct node{
	int val;
	Node ltree, rtree;
	int hb : 2;
};

Node addnode(Node root, int v);
Node deletenode(Node root, int v);
Node find(Node root, int v);
