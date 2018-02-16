#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct employee
{
	char name[11];
	long long int empid;
} Employee;

void readrec(char *filename, Employee arr[]);
void printrec(Employee arr[], int n);
void QuickSort(Employee arr[], int S, int n);
void InsertionSort(Employee arr[], int l, int r);
// void QuickSort(Employee arr[], int l, int r);