#include "test1.h"

int main(){
	Employee arr[2000];
	readrec("data.txt", arr);
	// QuickSort(arr,0,2000);
	InsertionSort(arr,0,1999);
	printrec(arr,2000);
}