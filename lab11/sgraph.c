#include "sgraph.h"

void printlist(Edgelist edgel){
	for(int i=0; i<9; i++){
		printf("%d %d\n", edgel.edges[i].u, edgel.edges[i].v);
	}
}

Edgelist readfile(char* filename, Edgelist olist){
	FILE *fl;
	fl = fopen(filename, "r");
	
	char line[256];
	char *pt;
	
	list.edgecnt = 9;
	list.edges = (Edge*)malloc((list.edgecnt)*sizeof(struct edge));
	
	int cnt=0;
	while(fgets(line, 256, fl)){
		(list.edges[cnt]).u = atoi(strtok(line, " "));
		(list.edges[cnt]).v = atoi(strtok(NULL, " "));
		cnt++;
	}
	
	
	return list;
}

Verlist convert(Edgelist olist, Edgelist newlist){
	Verlist vers;
	vers.vcnt = 0;
		
}
