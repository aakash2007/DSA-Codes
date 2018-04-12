#include "sgraph.h"

int main(){
	//char* flname = "graph0.txt";
	char* flname = "citation.txt";
	Edgelist oedgel, newlist;
	oedgel = readfile(flname, oedgel);
	Verlist vers;
	vers = convert(oedgel, &newlist);
	//printvers(vers);
	//printedgelist(oedgel);
	//printedgelist(newlist);
	Linklist topord;
	topord = topsort(newlist, vers);
	//printll(topord);
	
	
	/*Linklist ll = (Linklist)malloc(sizeof(struct linklist));
	Que q = (Que)malloc(sizeof(struct que));
	for(int i=0; i<20; i++){
		ll = addelem(ll, i);
		q = enque(q, i);
	}
	printll(ll);
	printque(q);
	deque(q);
	printque(q);
	deque(q);
	printque(q);
	deque(q);
	printque(q);
	deque(q);
	printque(q);
	*/
	
}
