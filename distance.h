#ifndef DISTANCE_H
#define DISTANCE_H

#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半徑

double GET_DISTANCE(double lat1, double lng1, double lat2, double lng2);

void LOCATE(double *lat1, double *lng1);

void CHANGE_LOCATE(double *lat1, double *lng1);

void DISTANCE(Store *HEAD,double lat1,double lng1);

void PRINT_NEAR(Store *HEAD,double lat1,double lng1);


#endif
