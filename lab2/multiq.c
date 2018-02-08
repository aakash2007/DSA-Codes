#include "multiq.h"

MultiQ createMQ(int num){
	MultiQ mq = (MultiQ)malloc(sizeof(struct multiQ));
	mq->nq = num;

	Queue* arr = (Queue*)malloc(sizeof(struct queue)*num);
	mq->qptr = arr;

	for(int i=0;i<num;i++){
		mq->qptr[i] = newQ();
	}
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
	int prr = t->pr;
	Queue tq = mq->qptr[prr-1];
	tq = addQ(tq, t);
	return mq;
}

Task nextMQ(MultiQ mq){
	Queue* arr = mq->qptr;
	int len = mq->nq;
	for(int i=0; i< len; i++){
		if(!isEmptyQ(arr[i])){
			return front(arr[i]);
		}
	}
	return NULL;
}

MultiQ delNextMQ(MultiQ mq){
	Queue* arr = mq->qptr;
	int len = mq->nq;
	for(int i=0; i<len; i++){
		if(!isEmptyQ(arr[i])){
			arr[i] = delQ(arr[i]);
			return mq;
		}
	}
	return mq;
}

int isEmptyMQ(MultiQ mq){
	int len = mq->nq, fl = 1;
	Queue* arr = mq->qptr;
	for (int i = 0; i < len; ++i)
	{
		if(!isEmptyQ(arr[i])){
			fl=0;
			break;
		}
	}
	if (fl==1)
	{
		return 1;
	}
	else{
		return 0;
	}
}

int sizeMQ(MultiQ mq){
	return mq->nq;
}

int sizeMQbyPriority(MultiQ mq, int prr){
	return lengthQ(mq->qptr[prr-1]);
}

Queue getQueueFromMQ(MultiQ mq, int prr){
	return mq->qptr[prr-1];
}





void printMQ(MultiQ mq){

	for(int i=0; i < (mq->nq); i++){
		printf("Queue %d : ", i+1);
		printQ(mq->qptr[i]);
	}
}
