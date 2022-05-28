#ifndef DISTANCE_H
#define DISTANCE_H

#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半徑

double get_distance(double lat1, double lng1, double lat2, double lng2);

void distance(Store *HEAD);

void PRINTNEAR(Store *HEAD);


#endif
