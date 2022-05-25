#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h> 

void RANDOM(Store *HEAD){
	Store *p;
	int count=0;
	srand( time(NULL) );
	int x = rand();
	for (p = HEAD; p != NULL; p = p->next) count++;
	x=x%count;
	p = HEAD;
	for (int i=0; i<x; i++)
		p = p->next;
	char type[13];
    	totype(type, p->type);
    	printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
    	printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
}

void RANDOMTYPE (Store *HEAD,int TYPE){
    Store *p;
    int count=0,typenumber[100],i=0;
    srand( time(NULL) );
    int x = rand();
    for(p = HEAD; p!= NULL; p = p->next){
	if(p->type== TYPE){
		typenumber[i]=count;
		i++;
	}
	count++;
    }
    x=x%(i);
    p = HEAD;
    for(int i=0; i<typenumber[x]; i++)
	p = p->next;
    char type[13];
    totype(type, p->type);
    printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
    printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
}
