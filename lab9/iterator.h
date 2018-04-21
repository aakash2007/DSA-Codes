#include <stdio.h>
#include <stdlib.h>

typedef struct iterator* Iter;
typedef struct element* Elem;

struct iterator{
	Elem* arr;
	int n;
	int ind;
};

struct element{
	int val;
	Iter it;
};

int hasmoreelem(Iter it);
Elem getnext(Iter it);
void printiter(Iter it);
