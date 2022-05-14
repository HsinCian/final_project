#include "myDS.h"


void my_print_id(){
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
  char Name[128];
  scanf("%s",Name);
	for (p = HEAD; p != NULL; p = p->next){
		if (strcmp(p->name,Name)==0){
			PRINT();
			return;
		}
	}
	if (p == NULL){
		printf("INVALID OPERATION\n");
		return;
    }
}
