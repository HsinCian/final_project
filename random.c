#include "struct.h"
#include "myIO.h"
#include "distance.h"
#include "random.h"

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
	printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    	printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
    	printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
}

void RANDOM_TYPE (Store *HEAD){
    printf("What type do you want? (CHICKEN_RICE / JAPANESE / KOREAN / AMERICAN / CHINESE / BREAKFAST / DRINKS / DESSERT)\n");
    char type[36];
    scanf("%s",type);
    int TYPE=gettype(type);
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
    totype(type, p->type);
    printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
    printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
}

void RANDOM_NEAR(Store *HEAD){
    char location[20];
    double lat1,lng1;
    double lat2;
    double lng2;
    // insert code here...

    printf("Where are you? (Science / Engineering / Center / Dormitory / Gate / Minxiong_Station / Chiayi_Station)\n");
    scanf("%s", location);
    STRUPR(location);
    if((strcmp(location, "SCIENCE"))== 0){
        lat1 = 23.564713;
        lng1 = 120.476228;
    }
    if((strcmp(location, "ENGINEERING"))== 0){
        lat1 = 23.562293;
        lng1 = 120.477894;
    }
    if((strcmp(location, "CENTER"))== 0){
        lat1 = 23.560825;
        lng1 = 120.472384;
    }
    if((strcmp(location, "DORMITORY"))== 0){
        lat1 = 23.560451;
        lng1 = 120.469058;
    }
    if((strcmp(location, "GATE"))== 0){
        lat1 = 23.558599;
        lng1 = 120.471946;
    }
    if((strcmp(location, "MINXIONG_STATION"))== 0){
        lat1 = 23.555316;
        lng1 = 120.431967;
    }
    if((strcmp(location, "CHIAYI_STATION"))== 0){
        lat1 = 23.479372;
        lng1 = 120.441165;
    }
    Store *p;
    srand( time(NULL) );
	int x = rand();
    int count=0,typenumber[100],i=0;
    for (p = HEAD; p != NULL; p = p->next){
          lat2=p->latitude;
          lng2=p->longitude;
          if(GET_DISTANCE(lat1,lng1,lat2,lng2)<1){
            typenumber[i]=count;
			i++;
          }
          count++;
    }
    x=x%i;
	p = HEAD;
	for(int i=0; i<typenumber[x]; i++)
		p = p->next;
	char type[13];
    totype(type, p->type);
    printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
    printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);


}
