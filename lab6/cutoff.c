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

	Employee *tmp;
	tmp = (Employee*)malloc(size*sizeof(Employee));

	for (int i = 0; i < size; ++i)
	{
		tmp[i] = arr[i];
	}
// Quick Sort
	gettimeofday(&t1, NULL);
	
	QuickSort(tmp,0,size);
	
	gettimeofday(&t2,NULL);
	tt.QStime = (t2.tv_sec - t1.tv_sec)*1000.0;
	tt.QStime += (t2.tv_usec - t1.tv_usec)/1000.0;

	for (int i = 0; i < size; ++i)
	{
		tmp[i] = arr[i];
	}
// Insertion Sort
	gettimeofday(&t1, NULL);
	
	InsertionSort(tmp,0,size-1);

	gettimeofday(&t2,NULL);
	tt.IStime = (t2.tv_sec - t1.tv_sec)*1000.0;
	tt.IStime += (t2.tv_usec - t1.tv_usec)/1000.0;

	for (int i = 0; i < size; ++i)
	{
		tmp[i] = arr[i];
	}
// Optimized Quick Sort
	gettimeofday(&t1, NULL);
	
	optQuickSort(tmp,0,size);

	gettimeofday(&t2,NULL);
	tt.opQStime = (t2.tv_sec - t1.tv_sec)*1000.0;
	tt.opQStime += (t2.tv_usec - t1.tv_usec)/1000.0;
	return tt;
}

int estimatecutoff(Employee arr[]){
	Time tt1, tt2;
	int mx = 2000, mn = 1;
	tt1 = testrun(arr, mn);
	tt2 = testrun(arr, mx);
	int mid = mx;

	FILE *fl;
	fl = fopen("outIS.csv", "w");

	for (int i = 1; i <= mx; ++i)
	{
		tt1 = testrun(arr, i);
		fprintf(fl, "%d,%f\n", i, tt1.IStime);
	}
	
	while(abs(tt2.QStime - tt2.IStime) >= 0.001){
		// mid = (mn + mx)/2;
		tt2 = testrun(arr, mid);
		mid--;
	}

	printf("N: %d\n", mid);
	// printf("tt1: %f %f\n", tt1.QStime, tt1.IStime);
	// printf("tt2: %f %f\n", tt2.QStime, tt2.IStime);
	return mid;
}

int main(){
	Time t;
	Employee *arr;
	arr = (Employee*)malloc(2000*sizeof(Employee));
	readrec("data.txt", arr);
	// t = testrun(arr, 2000);
	// printf("Quick Sort: %f\n", t.QStime);
	// printf("Insertion Sort: %f\n", t.IStime);
	// printf("Optimized Quick Sort: %f\n", t.opQStime);
	estimatecutoff(arr);
	// printrec(arr,2000);
}