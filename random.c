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

void RANDOM_TYPE (Store *HEAD,int TYPE){
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

void PRINT_NEAR(Store *HEAD){
    char location[20];
    double lat1,lng1;
    double lat2;
    double lng2;
    printf("Where are you? (Science/Engineering/Center/Dormitory/Gate/Minxiong_Station/Chiayi_Station)\n");
    scanf("%s", location);
    if((strcmp(location, "Science"))== 0){
        lat1 = 23.564713;
        lng1 = 120.476228;
    }
    if((strcmp(location, "Engineering"))== 0){
        lat1 = 23.562293;
        lng1 = 120.477894;
    }
    if((strcmp(location, "Center"))== 0){
        lat1 = 23.560825;
        lng1 = 120.472384;
    }
    if((strcmp(location, "Dormitory"))== 0){
        lat1 = 23.560451;
        lng1 = 120.469058;
    }
    if((strcmp(location, "Gate"))== 0){
        lat1 = 23.558599;
        lng1 = 120.471946;
    }
    if((strcmp(location, "Minxiong_Station"))== 0){
        lat1 = 23.555316;
        lng1 = 120.431967;
    }
    if((strcmp(location, "Chiayi_Station"))== 0){
        lat1 = 23.479372;
        lng1 = 120.441165;
    }
    Store *p;
    for (p = HEAD; p != NULL; p = p->next){
          lat2=p->latitude;
          lng2=p->longitude;
          if(get_distance(lat1,lng1,lat2,lng2)<1){
            char type[13];
            totype(type, p->type);
            printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
            printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
          }
    }
}
