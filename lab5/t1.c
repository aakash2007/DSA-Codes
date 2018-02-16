#include "test1.h"
#include "compRecMS.h"

int main(){
	Element Ls[10241], Ls2[1025], fn[2050];
	readrec("10240.txt",Ls);
	// readrec("1024.txt",Ls2);
	// merge(Ls,1024, Ls2, 1024, fn);
	// print_rec(fn,2050);
	// recMS(Ls, 0, 10239);
	iterMS(Ls, 10240);
	print_rec(Ls, 10240);

}