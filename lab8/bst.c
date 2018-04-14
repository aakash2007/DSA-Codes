#include "bst.h"

Node addnode(Node root, int v){

	if(root == NULL){
		Node ptr = (Node)malloc(sizeof(struct node));
		ptr->val = v;
		ptr->ltree = ptr->rtree = NULL;
		root = ptr;
		return root;
	}
	else{
		if(v <= root->val){
			root->hb--;
			root->ltree = addnode(root->ltree, v);
		}
		else{
			root->hb++;
			root->rtree = addnode(root->rtree, v);
		}
	}
	return root;
}

Node find(Node root, int v){
	if(root == NULL){
		return NULL;
	}
	else if(root->val == v){
		return root;
	}
	else if(root->val > v){
		return find(root->ltree, v);
	}
	else if(root->val < v){
		return find(root->rtree, v);
	}
}

Node nextsuccess(Node root){
	if(root->ltree == NULL){
		return root;
	}
	else
	return nextsuccess(root->ltree);
}

Node deletenode(Node root, int v){
	if(root == NULL){
		return NULL;
	}
	else if(v < root->val){
		root->ltree = deletenode(root->ltree, v);
	}
	else if(v > root->val){
		root->rtree = deletenode(root->rtree, v);
	}
	else{
		if(root->ltree == NULL){
			Node temp = root->rtree;
			free(root);
			return temp;
		}
		if(root->rtree == NULL){
			Node temp = root->rtree;
			free(root);
			return temp;
		}
		else{
			Node temp = nextsuccess(root->rtree);
			root->val = temp->val;
			root->rtree = deletenode(root->rtree, temp->val);
		}
	}
	return root;
}

void printbst(Node root){
	if(root == NULL){
		return;
	}	
	printbst(root->ltree);
	printf("%d %d\n", root->val, root->hb);
	printbst(root->rtree);
}



