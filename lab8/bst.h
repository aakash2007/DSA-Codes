#include <stdlib.h>
#include <stdio.h>

typedef struct node* Node;
struct node{
	int val;
	int lcnt;
	Node ltree, rtree;
	int hb;
};

Node addnode(Node root, int v);
Node deletenode(Node root, int v);
Node find(Node root, int v);
Node rotate(Node x, Node y, Node z);
int depth(Node ptr);
Node avlinsert(Node root, int v);
