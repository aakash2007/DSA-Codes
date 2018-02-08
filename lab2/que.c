#include "que.h"

Queue newQ(){
	Queue q;
	q = (Queue)malloc(sizeof(struct queue));
	q->length = 0;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int isEmptyQ(Queue q){
	if(q->front == NULL)
		return 1;
	else
		return 0;
}

Queue delQ(Queue q){
	if(isEmptyQ(q)){
		return q;
	}
	if(lengthQ(q)==1){
		Element tmp = q->front;
		q->front = NULL;
		q->rear = NULL;
		q->length--;
		free(tmp);
		return q;
	}
	else{
		Element tmp = q->front;
		q->front = q->front->next;
		free(tmp);
		q->length--;
		return q;
	}
}

Queue addQ(Queue q, Element e){
	if(isEmptyQ(q)){
		q->front = e;
		q->rear = e;
		q->length++;
	}
	else{
		q->rear->next = e;
		q->rear = e;
		q->length++;
	}
}

Element front(Queue q){
	if(isEmptyQ(q)){
		return NULL;
	}
	else{
		return q->front;
	}
}

int lengthQ(Queue q){
	return q->length;
}

void printQ(Queue q){
	if(isEmptyQ(q)){
		printf("Empty Queue\n");
	}
	else{
		Element ptr = q->front;
		printf("Length = %d\n", q->length); 
		while(ptr !=NULL){
			printf(" %d->", ptr->key);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
