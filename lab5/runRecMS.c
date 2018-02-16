#include "compRecMS.h"

int main(){
	Element Ls[1025];
	readrec("1024.txt",Ls);
	printf("LL\n");
	recMS(Ls, 0, 1023);
	print_rec(Ls, 1024);
}