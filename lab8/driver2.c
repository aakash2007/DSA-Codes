#include "bst.h"

int main(){
	
	Node root = NULL;	
	
	root = avlinsert(root , 6);
	root = avlinsert(root , 3);
	root = avlinsert(root , 10);
	root = avlinsert(root , 1);
	root = avlinsert(root , 2);
	root = avlinsert(root , 856);
	root = avlinsert(root , 23);
	root = avlinsert(root , 11);
	root = avlinsert(root , 88);
	root = avlinsert(root , 99);
	root = avlinsert(root , 101);
	root = avlinsert(root , 89);
	root = avlinsert(root , 45);
	root = avlinsert(root , 78);
	root = avlinsert(root , 7);
	root = avlinsert(root , 61);
	root = avlinsert(root , 12);
	root = avlinsert(root , 18);
	root = avlinsert(root , 999);
	
	//root = deletenode(root, 88);
	
	Node ptr = find(root, 2);
	printf("ll %d\n",depth(root));
	printf("ll %d\n",depth(root->ltree));
	printf("ll %d\n",depth(root->rtree));
	printf("ll %d\n",calchb(root));
	root->hb = calchb(root);
	printbst(root);
}
