#include "test1.h"

int main(){
	int size=10;
	Record* ptr = malloc(size*sizeof(Record));
	// printf("%d\n", sizeof(Record));

	FILE *fl;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	fl = fopen("10", "r");
	if(fl==NULL){
		exit(1);
	}

	// while((read = getline(&line, &len, fl)) != -1){
	// 	printf("Size: %zu \n", read);
	// 	printf("%d\n", len);
	// 	printf("%s\n", line);
	// }

	fclose(fl);
	if(line){
		free(line);
	}
	Record arr[10];
	read_record("10",arr);

	print_record(arr,10);

	return 0;
}