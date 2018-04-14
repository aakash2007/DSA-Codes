#include "bst.h"

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int depth(Node ptr){
	if(ptr == NULL){
		return 0;
	}
	return max(1+depth(ptr->ltree), 1+depth(ptr->rtree));
}

int calchb(Node ptr){
	int a = depth(ptr->ltree);
	int b = depth(ptr->rtree);
	return (b-a);
}

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
			root->ltree = addnode(root->ltree, v);
		}
		else{
			root->rtree = addnode(root->rtree, v);
		}
	}
	root->hb = calchb(root);
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


Node rotate(Node X , Node Y , Node Z)
{	
	
	Node a , b , c , T0 , T1 , T2 , T3;
	if(Z->ltree == Y)
	{
		if(Y->ltree == X)
		{
			b = Y;
			a = X;
			T2 = Y->rtree;
			T1 = X->rtree;
			T0 = X->ltree;	
		}
		else
		{
			a = Y;
			b = X;
			T0 = Y->ltree;
			T1 = X->ltree;
			T2 = X->rtree;
		}
		c = Z;
		T3 = Z->rtree;
	
	}
	else if(Z->rtree == Y)
	{
		if(Y->ltree == X)
		{
			b = X;
			c = Y;
			T1 = X->ltree;
			T2 = X->rtree;
			T3 = Y->rtree;
		}
		else
		{
			b = Y;
			c = X;
			T1 = Y->ltree;
			T2 = X->ltree;
			T3 = X->rtree;
		
		}
		
		a = Z;
		T0 = Z->ltree;
	
	}
	
	Z = b;
	b->ltree = a;
	a->ltree = T0;
	a->rtree = T1;
	b->rtree = c;
	c->rtree = T3;
	c->ltree = T2;
	
	a->hb = calchb(a);
	b->hb = calchb(b);
	c->hb = calchb(c);	
	return Z;

}

Node createnode(int v){
	Node ptr = (Node)malloc(sizeof(struct node));
	ptr->val = v;
	ptr->ltree = ptr->rtree = NULL;
	return ptr;
}

Node avlinsert(Node root, int v){
	if(root == NULL){
		Node ptr = createnode(v);
		root = ptr;
		return root;
	}
	
	if(v <= root->val){
		root->ltree = avlinsert(root->ltree, v);
		root->hb = calchb(root);
	}
	else if(v > root->val){
		root->rtree = avlinsert(root->rtree, v);
		root->hb = calchb(root);
	}
	else
		return NULL;
		
	if(root->hb < -1){
		Node z = root;
		Node y = root->ltree;
		Node x;
		if(y->hb < 0)	x = y->ltree;
		else x = y->rtree;
		root = rotate(x,y,z);
	}
	else if(root->hb > 1){
		Node z = root;
		Node y = root->rtree;
		Node x;
		if(y->hb < 0)	x = y->ltree;
		else x = y->rtree;
		root = rotate(x,y,z);
	}
	root->hb = calchb(root);
	return root;
}




