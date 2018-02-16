#include "compRecMS.h"

int min(int a, int b){
	if(a > b)
		return b;
	else
		return a;
}

void readrec(char* filename, Element Ls[]){
	FILE *fl;
	printf("KK\n");
	fl = fopen(filename, "r");
	char line[50];
	int i=0;
	char *item;
	while(fgets(line,50,fl)){
		item = strtok(line, ",");
		strcpy(Ls[i].name, item);
		item = strtok(NULL, ",");
		Ls[i].cgpa = atof(item);
		i++;
	}
	fclose(fl);
}
	
void print_rec(Element Ls[], int size){
	for (int i = 0; i < size; ++i)
	{
		printf("%d: %s %f\n", i+1 ,Ls[i].name, Ls[i].cgpa);
	}
}

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	int i=0, j=0, k=0;
	while(i<sz1 && j<sz2){
		if(Ls1[i].cgpa <= Ls2[j].cgpa){
			Ls[k] = Ls1[i];
			i++;
		}
		else{
			Ls[k] = Ls2[j];
			j++;
		}
		k++;
	}
	while(i<sz1){
		Ls[k] = Ls1[i];
		i++;
		k++;
	}
	while(j<sz2){
		Ls[k] = Ls2[j];
		j++;
		k++;
	}
}

void recMS(Element Ls[], int l, int r){
	if(l < r){
		// int mid = l + (r-l)/2;
		int mid = (l+r)/2;

		int n1 = mid - l + 1;
		int n2 = r - mid;
		
		Element tmp[n1 + n2];

		for (int i = 0; i < n1 + n2; ++i)
		{
			tmp[i] = Ls[i];
		}
		// printf("%d %d %d %d %d\n", l,r,mid,n1,n2);

		Element arr1[n1], arr2[n2];
		
		for (int i = 0; i < n1; ++i)
		{
			arr1[i] = Ls[l+i];
		}
		for (int j = 0; j < n2; ++j)
		{
			arr2[j] = Ls[j+mid+1];
		}
		recMS(arr1, 0, n1-1);
		recMS(arr2, 0, n2-1);
		merge(arr1, n1, arr2, n2, tmp);
		
		for (int i = 0; i < n1 + n2; ++i)
		{
			Ls[i] = tmp[i];
		}
	}	
}