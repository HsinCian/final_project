#ifndef MYIO_H
#define MYIO_H

void STRUPR(char *str);

enum TYPE gettype(const char *string);

void totype(char *string, enum TYPE type);

int INITIAL(Store **HEAD, int count);

void WRITE_BACK(Store *HEAD);

void WRITE_EXCEL(Store *HEAD);

void MAP(Store *HEAD,double lat1, double lng1);

void MAPNEAR(Store *HEAD,double lat1, double lng1);

#endif
