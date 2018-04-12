#include "sgraph.h"

void printedgelist(Edgelist edgel){
	for(int i=0; i<edgel.edgecnt; i++){
		printf("%d %d\n", edgel.edges[i].u, edgel.edges[i].v);
	}
}

void printvers(Verlist vers){
	printf("vers %d\n", vers.vcnt);
	for(int i=0; i<vers.vcnt; i++){
		printf("v %d %d\n", i, vers.varr[i].val);
	}
}

Edgelist readfile(char* filename, Edgelist list){
	FILE *fl;
	fl = fopen(filename, "r");
	
	char line[256];
	char *pt;
	list.edgecnt = 4e5;
	list.edges = (Edge*)malloc((list.edgecnt)*sizeof(struct edge));
	int cnt=0;
	while(fgets(line, 256, fl)){
		//printf("%d\n", cnt);
		//printf("%s\n", line);
		(list.edges[cnt]).u = atoi(strtok(line, "	"));
		(list.edges[cnt]).v = atoi(strtok(NULL, "	"));
		cnt++;
	}
	list.edgecnt = cnt;
	return list;
}

int findnode(Verlist vers, int val){
	for(int i=0; i<vers.vcnt; i++){
		if(vers.varr[i].val == val){
			return i;
		}	
	}
	return -1;
}

int addver(Verlist *vers, int val){
	Node ptr;
	ptr.val = val;
	(vers->varr)[vers->vcnt] = ptr;
	vers->vcnt++;
	return (vers->vcnt-1);
}

Verlist convert(Edgelist olist, Edgelist *newlist){
	Verlist vers;
	vers.vcnt = 0;
	vers.varr = (Node*)malloc(1e5*sizeof(Node));
	newlist->edgecnt = olist.edgecnt;
	newlist->edges = (Edge*)malloc((newlist->edgecnt)*sizeof(struct edge));
	
	for(int i=0; i<olist.edgecnt; i++){
		int ou = olist.edges[i].u;
		int ov = olist.edges[i].v;
		
		int u = findnode(vers, ou);
		int v = findnode(vers, ov);
		
		
		if(u == -1){
			u = addver(&vers, ou);
		}
		if(v == -1){
			v = addver(&vers, ov);
		}
		//printf("t %d %d %d %d\n", ou, ov, u, v);
		
		(newlist->edges[i]).u = u;
		(newlist->edges[i]).v = v;
	}
	return vers;
}

Linklist topsort(Edgelist list, Verlist vers){
	
	printf("In Topsort\n");
	int* indeg = (int*)malloc(vers.vcnt*sizeof(int));
	memset(indeg, 0, vers.vcnt*sizeof(int));

	//int* vis = (int*)malloc(vers.vcnt*sizeof(int));
	//memset(vis, 0, vers.vcnt*sizeof(int));
	int viscnt = 0;

	for(int i=0; i<list.edgecnt; i++){
		indeg[list.edges[i].v]++;
	}


	Que q = (Que)malloc(sizeof(struct que));
	for(int i=0; i<vers.vcnt; i++){
		if(indeg[i] == 0){
			q = enque(q, i);
		}
	}
	//printf("\n 0deg: %d\n", q->qcnt);

	Linklist torder = (Linklist)malloc(vers.vcnt*sizeof(struct element));
	
	Elem ptr;
	while((ptr = deque(q)) != NULL){
		//printf("qcnt = %d\n", q->qcnt);
		torder = addelem(torder, ptr->data);
		viscnt++;
		printf("\n");
		for(int i=0; i<list.edgecnt; i++){
			int src = list.edges[i].u;
			int dest = list.edges[i].v; 
			if(src == ptr->data){
				indeg[dest]--;
				if(indeg[dest] == 0){
					q = enque(q, dest);
				}
				printf("%d ", indeg[dest]);
			}
		}
	}
	printf("\n");
	printf("vis: %d %d %d %d\n", viscnt, torder->lcnt, vers.vcnt, q->qcnt);
	
	/*printf("indeg \n");
	for(int i=0; i<vers.vcnt; i++){
		printf("%d ", indeg[i]);
	}*/
	
	return torder;
}

Que enque(Que q, int vel){
	Elem el = (Elem)malloc(sizeof(struct element));
	el->data = vel;
	el->next = NULL;
	
	if(q->front == NULL){
		q->front = el;
		q->rear = el;
	}
	else{
		q->rear->next = el;
		q->rear = q->rear->next;		
	}
	q->qcnt++;
}

Elem deque(Que q){
	Elem ptr;
	if(q->front == NULL){
		return NULL;
	}
	if(q->front == q->rear){
		ptr = q->front;
		q->front = NULL;
		q->rear = NULL;
		q->qcnt--;
		return ptr;
	}
	else{
		ptr = q->front;
		q->front = q->front->next;
		q->qcnt--;
		return ptr;
	}
}

Linklist addelem(Linklist ll, int val){
	Elem ptr = (Elem)malloc(sizeof(struct element));
	ptr->data = val;
	ptr->next = NULL;
	if(ll->head == NULL){
		ll->head = ptr;
		ll->lcnt++;
	}
	else{
		Elem tmp = ll->head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = ptr;
		ll->lcnt++;
	}
	return ll;
}

void printque(Que q){
	printf("Queue:\n");
	Elem ptr = q->front;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void printll(Linklist ll){
	printf("Linklist:\n");
	Elem ptr = ll->head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}


