#include <stdio.h>
#include <stdlib.h>

struct element{
	int key;
	int pr;
	struct element* next;
};

struct queue{
	int length;
	struct element* front;
	struct element* rear;
};

typedef struct element* Element;
typedef struct queue* Queue;

Queue newQ();
int isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);
void printQ(Queue q);
