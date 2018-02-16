#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
	char name[11];
	float cgpa;
} Element;

void readrec(char* filename, Element Ls[]);
void print_rec(Element Ls[], int size);
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void recMS(Element Ls[], int l, int r);