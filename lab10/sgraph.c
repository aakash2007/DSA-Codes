#include "sgraph.h"

Graph creategraph(int numV){
	Graph G = (Graph)malloc(sizeof(struct graph));
	G->vcnt = numV;
	(G->adjlist) = (Linklist*)malloc(numV*sizeof(struct linklist));
	//printf("addde %p\n", (G->adjlist)[0]);
	for(int i=0; i<numV; i++){
		(G->adjlist)[i].lcnt = 0;
		(G->adjlist)[i].head = NULL;
	}
	return G;
}

void printadj(Graph G){
	for(int i=0; i<G->vcnt; i++){
		Elem ptr = ((G->adjlist)[i]).head;
		printf("\n%d  %d: ", i, ((G->adjlist)[i]).lcnt);
		while(ptr != NULL){
			printf(" %d", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}

Linklist getAdj(Graph G, int v){
	Linklist ll = (G->adjlist)[v];
	return ll;
}

Graph addedge(Graph G, int u, int v){
	//printf("%d %d\n",u ,v);
	(G->adjlist)[u] = addelem((G->adjlist)[u], v);
	(G->adjlist)[v] = addelem((G->adjlist)[v], u);
	return G;
}

Graph readfile(char* flname, Graph G){
	FILE* fl;
	fl = fopen(flname, "r");
	
	char line[256];
	char *pt;
	while(fgets(line, 256, fl)){
		int u = atoi(strtok(line, " "));
		int v = atoi(strtok(NULL, "	"));
		printf("%d %d\n",u ,v);
		G = addedge(G, u, v);
	}
	return G;
}

void DFSutil(Graph g, int u, int* vis){
	vis[u] = 1;
	printf(" %d ", u);
	Linklist adj = getAdj(g, u);
	Elem ptr = adj.head;
	for(int i=0; i<adj.lcnt; i++){
		if(!vis[ptr->data]){
			DFSutil(g, ptr->data, vis);
		}
		ptr = ptr->next;
	}
}

void DFS(Graph g){
	int* vis = (int*)malloc((g->vcnt)*sizeof(int));
	memset(vis, 0, (g->vcnt)*sizeof(int));
	
	for(int i=0; i<g->vcnt; i++){
		if(!vis[i]){
			DFSutil(g, i, vis);
		}
	}
}


Linklist addelem(Linklist ll, int v){
	Elem ptr = (Elem)malloc(sizeof(struct element));
	ptr->data = v;
	ptr->next = NULL;
	if(ll.head == NULL){
		ll.head = ptr;
		ll.lcnt++;
	}
	else{
		Elem tmp = ll.head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = ptr;
		ll.lcnt++;
	}
	return ll;
}
