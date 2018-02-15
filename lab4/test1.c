#include "test1.h"

void read_record(char *filename, Record *arr){
	FILE *fl;
	fl = fopen(filename, "r");
	char line[50];
	int i=0;
	while(fgets(line, 50, fl)){
		// printf("%s\n", line);
		char cd[17];
		char* bank = (char*)malloc(sizeof(char)*6);
		char* exp = (char*)malloc(sizeof(char)*8);
		char* fnm = (char*)malloc(sizeof(char)*6);
		char* lnm = (char*)malloc(sizeof(char)*6);
		splice(line,cd,1,16);
		long long cardn = atoll(cd);
		splice(line,bank,18,22);
		splice(line,exp,24,30);
		splice(line,fnm,32,36);
		splice(line,lnm,38,42);

		arr[i].card_no = cardn;
		arr[i].bank_code = bank;
		arr[i].expiry = exp;
		arr[i].lname = lnm;
		arr[i].fname = fnm;
		// printf("%s\n", lnm);
		i++;
	}
	fclose(fl);
}
void splice(char* str, char* var, int l, int r){
	int k=0;
	for (int i = l; i <= r; ++i)
	{
		var[k] = str[i];
		k++;
	}
	var[k] = '\0';
	// printf("%s\n", var);
}

void print_record(Record *arr, int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%llu %s %s %s %s\n", arr[i].card_no, arr[i].bank_code, arr[i].expiry, arr[i].fname, arr[i].lname);
	}
}