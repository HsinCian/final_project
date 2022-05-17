#include "myDS.h"


void SEARCH(){
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
  char Name[128];
  scanf("%s",Name);
  for (p = HEAD; p != NULL; p = p->next){
	if (strcmp(p->name,Name)==0){
		printf("%s %s %lf %lf %f %d %d %lf %d\n",p->name,p->phonenumber,p->longitude,p->latitude,p->data,p->time[0],p->time[1],p->distance,p->price);
		return;
	}
  }
  printf("INVALID OPERATION\n");
    
}
