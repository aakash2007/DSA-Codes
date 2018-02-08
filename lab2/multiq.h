#include "que.h"

typedef struct element* Task;

struct multiQ{
	int nq;
	Queue* qptr;
};

typedef struct multiQ* MultiQ;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int prr);
Queue getQueueFromMQ(MultiQ mq, int prr);
void printMQ(MultiQ mq);