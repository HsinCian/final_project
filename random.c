#include "struct.h"
#include "myIO.h"
#include "insert.h"
#include "distance.h"
#include "random.h"
//RANDOM,RANDOM_NEAR,RANDOM_TYPE


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
  printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\tOPEN?\n");
  printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
  printf("\t%04d\t%04d\t%d\t",p->time[0],p->time[1],p->price);
  IS_OPEN(p);
  printf("\n");
}

void RANDOM_TYPE (Store *HEAD){
  //printf("What type do you want? (CHICKEN_RICE / JAPANESE / KOREAN / AMERICAN / CHINESE / BREAKFAST / DRINKS / DESSERT)\n");
  char type[36];
  //scanf("%s",type);
  FILE *file;
  file = fopen("input.txt", "r");
  fscanf (file, "%s", type);
  fclose(file);
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
  printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\tOPEN?\n");
  printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
  printf("\t%04d\t%04d\t%d\t",p->time[0],p->time[1],p->price);
  IS_OPEN(p);
  printf("\n");
}

void RANDOM_NEAR(Store *HEAD,double lat1,double lng1){
  double lat2;
  double lng2;
  // insert code here...
  Store *p;
  srand( time(NULL) );
  int x = rand();
  int count=0,typenumber[100],i=0;
  for (p = HEAD; p != NULL; p = p->next){
    lat2=p->latitude;
    lng2=p->longitude;
    if(GET_DISTANCE(lat1,lng1,lat2,lng2)<2){
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
  printf("\t%04d\t%04d\t%d\t",p->time[0],p->time[1],p->price);
  IS_OPEN(p);
  printf("\n");
}
