#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct record
{
	long long card_no;
	char* bank_code;
	char* expiry;
	char* fname;
	char* lname;
} Record;

void read_record(char *filename, Record *arr);
void splice(char* str, char* var, int l, int r);
void print_record(Record *arr, int len);