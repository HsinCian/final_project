#include "struct.h"
#include "myIO.h"
#include "insert.h"
#include "my_habit.h"

void RECORD_SEARCH(Store *HEAD, char Name[128], int *rec){
	Store *p;
	for (p = HEAD; p != NULL; p = p -> next){
		if (strcmp(p -> name, Name)==0){
			rec[p->type]++;
			break;
		}
		else continue;
	}
}

void MY_HABIT(Store *HEAD, int *rec){
	int max = rec[0];
	int maxid = 0;
	for(int j = 1; j < 8; j++){
		if(max < rec[j]){
			max = rec[j];
			maxid = j;
		}
	}
	int TYPE = maxid;
    	Store *p;
    	int count = 0, typenumber[100], i = 0;
    	srand( time(NULL) );
    	int x = rand();
    	for(p = HEAD; p != NULL; p = p -> next){
		if(p -> type == TYPE){
			typenumber[i] = count;
			i++;
		}
		count++;
    	}
    	x = x % (i);
    	p = HEAD;
    	for(int i = 0; i < typenumber[x]; i++) p = p -> next;
	char type[36];
    	totype(type, p -> type);
    	printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    	printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
    	printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
	IS_OPEN(p);
}
