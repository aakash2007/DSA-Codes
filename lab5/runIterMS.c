#include "compIterMS.h"

int main(){
	Element Ls[10241];
	readrec("10240.txt",Ls);
	iterMS(Ls, 10240);
	print_rec(Ls, 10240);
}