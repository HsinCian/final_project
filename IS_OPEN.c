#include "myDS.h"

void IS_OPEN(Store *HEAD){
	// Print the opening time.
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
	char Name[128];
	scanf("%s",Name);
	for (p = HEAD; p != NULL; p = p->next){
		if (strcmp(p->name,Name)==0){
			const char * const delim = ":";
			char buf[30] = {0};
			char *substr = NULL;
			strcpy(buf, __TIME__);
			substr = strtok(buf, delim);
			int time1,time2;
			time1 = atoi(substr);
			substr = strtok(NULL, delim);
			time2 = atoi(substr);
			if(p->time[0] <= (100*time1+time2) && (100*time1+time2) <= p->time[1]){
			    printf("YES\n");
			}
			else
			    printf("NO\n");
			
			return;
		}
	}
	printf("INVALID OPERATION\n");
	
}

//printf("Current time: %s",__TIME__); //可以用這個取得當下時間,output: Current time: 19:54:39
