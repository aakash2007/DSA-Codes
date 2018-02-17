#include "test1.h"

void readrec(char *filename, Employee arr[]){
	FILE *fl;
	fl = fopen(filename, "r");
	char line[50];
	char *item;
	int i=0;
	while(fgets(line, 50, fl)){
		item = strtok(line, " ");
		strcpy(arr[i].name, item);
		item = strtok(NULL, " ");
		arr[i].empid = atoll(item);
		i++;
	}
	fclose(fl);
}

void printrec(Employee arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d: %s %lld\n", i+1, arr[i].name, arr[i].empid);
	}
}

int partition(Employee arr[], int l, int r){
	Employee key = arr[r];
	int i = l-1;
	for (int j = l; j < r; ++j)
	{
		if(arr[j].empid <= key.empid){
			i++;
			Employee tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	Employee tmp2 = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = tmp2;
	return i+1;
}

void QuickSort(Employee arr[], int S, int n){
	int l,r;
	l=0;
	r=n-1;

	int kk = r - l + 1;
	int *aux = malloc(kk*sizeof(int));
	int top = -1;

	aux[++top] = l;
	aux[++top] = r;

	while(top >= 0){
		r = aux[top--];
		l = aux[top--];

		int p = partition(arr, l, r);

		if(p-1 > l){
			aux[++top] = l;
			aux[++top] = p-1;
		}
		if(p+1 < r){
			aux[++top] = p+1;
			aux[++top] = r;
		}
	}
}

void optQuickSort(Employee arr[], int S, int n){
	int l,r;
	
	l = 0;
	r = n-1;	

	int kk = r - l + 1;
	int *aux = malloc(kk*sizeof(int));
	int top = -1;

	aux[++top] = l;
	aux[++top] = r;

	while(top >= 0){
		r = aux[top--];
		l = aux[top--];

		// if(r - l > S)
		{
			int p = partition(arr, l, r);

			if(p-1 > l){
				aux[++top] = l;
				aux[++top] = p-1;
			}

			if(p+1 < r){
				aux[++top] = p+1;
				aux[++top] = r;
			}
		}
		// else
		{
			// InsertionSort(arr,l,r);
		}
	}
}

void InsertionSort(Employee arr[], int l, int r){
	Employee key;
	for (int i = l; i <= r; ++i)
	{
		key = arr[i];
		int j = i-1;

		while(j >=0 && arr[j].empid > key.empid){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

// void QuickSort(Employee arr[], int l, int r){
// 	if(l < r){
// 		int pi = partition(arr, l, r);

// 		QuickSort(arr, l, pi-1);
// 		QuickSort(arr, pi+1, r);
// 	}
// }