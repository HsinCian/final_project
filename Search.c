#include "myDS.h"


void SEARCH(){
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
  char Name[128];
  scanf("%s",Name);
  for (p = HEAD; p != NULL; p = p->next){
	if (strcmp(p->name,Name)==0){
		PRINT(); 這個好像要在外面
		return;
	}
  }
  printf("INVALID OPERATION\n");
    
}
