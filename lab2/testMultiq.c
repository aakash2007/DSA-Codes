#include "multiq.h"
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


Element newEl(int val, int prr){
	Element nel = (Element)malloc(sizeof(struct element));
	nel->key = val;
	nel->pr = prr;
	nel->next = NULL;
	return nel;
}

void func(){
	FILE *fl;
	MultiQ mq = createMQ(10);
	fl = fopen("input10000.txt","r");
	char line[256];
	char *pch;
	if(fl){
		while(fgets(line, sizeof(line), fl)){
			pch = strtok(line,",");
			int p1 = atoi(pch);
			pch = strtok(NULL, ",");
			int p2 = atoi(pch);
			Element nel = newEl(p1,p2);
			mq = addMQ(mq, nel);
		}
		if(ferror(fl)){
			printf("ERROR\n");
		}
		fclose(fl);
	}

	printMQ(mq);
	for (int i = 0; i < 20; ++i)
	{
		delNextMQ(mq);
	}
	printMQ(mq);
}

int main(){
	struct timeval t1,t2;
	double elap_time=0.0;
	gettimeofday(&t1, NULL);
	
	func();

	gettimeofday(&t2, NULL);

	elap_time = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elap_time += (t2.tv_sec - t1.tv_sec) / 1000.0;
	printf("\nElapsed Time: %f\n", elap_time);
}