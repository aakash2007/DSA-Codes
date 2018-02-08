#include "multiq.h"
#include <stdlib.h>

Element newEl(int val){
	Element nel = (Element)malloc(sizeof(struct element));
	int k = (rand()%10) +1;
	nel->key = val;
	nel->next = NULL;
	return nel;
}

int main(){
	Queue q = newQ();
	printQ(q);
	Element nl = newEl(1220);
	q = addQ(q,nl);
	printQ(q);
	nl = newEl(2556);
	q = addQ(q,nl);
	printQ(q);
	nl = newEl(43534);
	q = addQ(q,nl);
	nl = newEl(987);
	q = addQ(q,nl);
	printQ(q);
	printf("\n %d\n", lengthQ(q));
	q = delQ(q);
	printQ(q);
	q = delQ(q);
	printQ(q);
	printf("\nMultiQueue:\n");
	MultiQ mq = createMQ(10);
	nl->pr = (rand()%10);
	addMQ(mq, nl);
	printMQ(mq);
	printf("#### %d\n", isEmptyMQ(mq));
	printf("@%d %d\n", nextMQ(mq)->pr, nextMQ(mq)->key);
	// mq = delNextMQ(mq);
	printf("#### %d\n", isEmptyMQ(mq));
	printMQ(mq);
	for (int i = 0; i < (mq->nq); ++i)
	{
		int tp = sizeMQbyPriority(mq, i+1);
		printf("Queue %d == %d\n", i+1, tp);	
	}
}
