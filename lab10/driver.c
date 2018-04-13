#include "sgraph.h"

int main(){
	char* flname = "graph0.txt";
	Graph G = creategraph(10);
	G = readfile(flname, G);
	printadj(G);
	DFS(G);
}
