#include "bst.h"

int main(){
	
	Node root = NULL;	
	
	root = addnode(root , 6);
	root = addnode(root , 3);
	root = addnode(root , 10);
	root = addnode(root , 1);
	root = addnode(root , 2);
	root = addnode(root , 856);
	root = addnode(root , 23);
	root = addnode(root , 11);
	root = addnode(root , 88);
	root = addnode(root , 99);
	root = addnode(root , 101);
	
	//root = deletenode(root, 88);
	
	Node ptr = find(root, 2);
	printf("ll %d\n",depth(root));
	printf("ll %d\n",depth(root->ltree));
	printf("ll %d\n",depth(root->rtree));
	printf("ll %d\n",calchb(root));
	root->hb = calchb(root);
	printbst(root);
}
