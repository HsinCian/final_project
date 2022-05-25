#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半徑

double get_distance(double lat1, double lng1, double lat2, double lng2){
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

void distance(Store *HEAD){
    char location[20];
    double lat1,lng1;
    double lat2;
    double lng2;
    // insert code here...
    
    printf("Where are you? (Science / Engineering / Center / Dormitory / Gate / Minxiong_Station / Chiayi_Station)\n");
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
    char Name[128];
    scanf("%s",Name);
    for (p = HEAD; p != NULL; p = p->next){
	    if (strcmp(p->name,Name)==0){
          lat2=p->latitude;
          lng2=p->longitude;
      }
    }
    printf("dst = %0.3fkm\n", get_distance(lat1,lng1,lat2,lng2));
}
