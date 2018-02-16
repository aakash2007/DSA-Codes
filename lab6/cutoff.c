#include "test1.h"

typedef struct timec
{
	float IStime;
	float QStime;
	float opQStime;
} Time;

Time testrun(Employee arr[], int size){
	Time tt;
	struct timeval t1, t2;

// Quick Sort
	gettimeofday(&t1, NULL);
	
	QuickSort(arr,0,size);
	
	gettimeofday(&t2,NULL);
	tt.QStime = (t2.tv_sec - t1.tv_sec)*1000.0;
	tt.QStime += (t2.tv_usec - t1.tv_usec)/1000.0;

// Insertion Sort
	gettimeofday(&t1, NULL);
	
	// InsertionSort(arr,0,size-1);

	gettimeofday(&t2,NULL);
	tt.IStime = (t2.tv_sec - t1.tv_sec)*1000.0;
	tt.IStime += (t2.tv_usec - t1.tv_usec)/1000.0;

// Optimized Quick Sort
	gettimeofday(&t1, NULL);
	
	// optQuickSort(arr,0,size);

	gettimeofday(&t2,NULL);
	tt.opQStime = (t2.tv_sec - t1.tv_sec)*1000.0;
	tt.opQStime += (t2.tv_usec - t1.tv_usec)/1000.0;
	return tt;
}

// void estimatecutoff(){

// }

int main(){
	Time t;
	Employee *arr;
	arr = (Employee*)malloc(2000*sizeof(Employee));
	readrec("data.txt", arr);
	t = testrun(arr, 2000);
	printf("Quick Sort: %f\n", t.QStime);
	printf("Insertion Sort: %f\n", t.IStime);
	printf("Optimized Quick Sort: %f\n", t.opQStime);
	// printrec(arr,2000);
}