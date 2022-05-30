#include "struct.h"
#include "myIO.h"
#include "insert.h"
#include "distance.h"
#include <math.h>

#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半徑

double GET_DISTANCE(double lat1, double lng1, double lat2, double lng2){
    // 求弧度
    double radLat1 = lat1 * PI / 180.0;
    double radLat2 = lat2 * PI / 180.0;
    double a = radLat1 - radLat2;
    double b = lng1 * PI / 180.0 - lng2 * PI / 180.0;
    //計算距離
    double dst = 2 * asin((sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2) )));
    
    dst = dst * EARTH_RADIUS;
    dst= round(dst * 10000) / 10000;
    return dst;
    
}
void LOCATE(double *lat1, double *lng1){
    char location[20];
    while(1){
	    printf("Where are you? (SCIENCE / ENGINEERING / CENTER / DORMITORY / GATE / MINXIONG_STATION / CHIAYI_STATION)\n");
	    scanf("%s", location);
	    STRUPR(location);
	    if((strcmp(location, "SCIENCE"))== 0){
		*lat1 = 23.564713;
		*lng1 = 120.476228;
		break;
	    }
	    else if((strcmp(location, "ENGINEERING"))== 0){
		*lat1 = 23.562293;
		*lng1 = 120.477894;
		break;
	    }
	    else if((strcmp(location, "CENTER"))== 0){
		*lat1 = 23.560825;
		*lng1 = 120.472384;
		break;
	    }
	    else if((strcmp(location, "DORMITORY"))== 0){
		*lat1 = 23.560451;
		*lng1 = 120.469058;
		break;
	    }
	    else if((strcmp(location, "GATE"))== 0){
		*lat1 = 23.558599; 
		*lng1 = 120.471946;
		break;
	    }
	    else if((strcmp(location, "MINXIONG_STATION"))== 0){
		*lat1 = 23.555316;
		*lng1 = 120.431967;
		break;
	    }
	    else if((strcmp(location, "CHIAYI_STATION"))== 0){
		*lat1 = 23.479372;
		*lng1 = 120.441165;
		break;
	    }
	    else{
		printf("INVALID OPERATION, please input again\n");
	    }
    }
}
void CHANGE_LOCATE(double *lat1, double *lng1){
    char location[20];
    while(1){
	    printf("Where are you? (SCIENCE / ENGINEERING / CENTER / DORMITORY / GATE / MINXIONG_STATION / CHIAYI_STATION)\n");
	    scanf("%s", location);
	    STRUPR(location);
	    if((strcmp(location, "SCIENCE"))== 0){
		*lat1 = 23.564713;
		*lng1 = 120.476228;
		break;
	    }
	    else if((strcmp(location, "ENGINEERING"))== 0){
		*lat1 = 23.562293;
		*lng1 = 120.477894;
		break;
	    }
	    else if((strcmp(location, "CENTER"))== 0){
		*lat1 = 23.560825;
		*lng1 = 120.472384;
		break;
	    }
	    else if((strcmp(location, "DORMITORY"))== 0){
		*lat1 = 23.560451;
		*lng1 = 120.469058;
		break;
	    }
	    else if((strcmp(location, "GATE"))== 0){
		*lat1 = 23.558599; 
		*lng1 = 120.471946;
		break;
	    }
	    else if((strcmp(location, "MINXIONG_STATION"))== 0){
		*lat1 = 23.555316;
		*lng1 = 120.431967;
		break;
	    }
	    else if((strcmp(location, "CHIAYI_STATION"))== 0){
		*lat1 = 23.479372;
		*lng1 = 120.441165;
		break;
	    }
	    else{
		printf("INVALID OPERATION, please input again\n");
	    }
    }
}
void DISTANCE(Store *HEAD,double lat1, double lng1){
    double lat2=0,lng2=0;
    // insert code here...
    Store *p;
    char Name[128];
    printf("Where do you want to go?\n");
    scanf("%s",Name);
    for (p = HEAD; p != NULL; p = p->next){
	    if (strcmp(p->name,Name)==0){
          lat2=p->latitude;
          lng2=p->longitude;
      }
    }
    if(lat2!=0 && lng2!=0){
	  printf("dst = %0.3fkm\n", GET_DISTANCE(lat1,lng1,lat2,lng2));
    }
    else{
    	printf("INVALID OPERATION\n");
    }	
}

void PRINTNEAR(Store *HEAD,double lat1, double lng1){
    double lat2;
    double lng2;
    Store *p;
    printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    for (p = HEAD; p != NULL; p = p->next){
          lat2=p->latitude;
          lng2=p->longitude;
          if(GET_DISTANCE(lat1,lng1,lat2,lng2)<1){
            char type[13];
            totype(type, p->type);
            printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
            printf("\t%04d\t%04d\t%d\t",p->time[0],p->time[1],p->price);
	    IS_OPEN(p);
	    printf("\n");
          }
    }
}
